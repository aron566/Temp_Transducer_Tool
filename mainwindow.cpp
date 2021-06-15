/**
  ******************************************************************************
  * @file    mainwindow.cpp
  * @author  aron566
  * @version v1.0
  * @date    2021-05-28
  * @brief   None.
  ******************************************************************************
  */
/* Header includes -----------------------------------------------------------*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
/* Macro definitions ---------------------------------------------------------*/
#define POLL_PERIOD_TIME_MS 1000/**< 轮询参数周期*/

/* Type definitions ----------------------------------------------------------*/
/* Variable declarations -----------------------------------------------------*/
/* Variable definitions ------------------------------------------------------*/
/* Function declarations -----------------------------------------------------*/
/* Function definitions ------------------------------------------------------*/
/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Temp Transducer");

    /* Apply style sheet */
    QFile file(":/Temp_Transducer_Tool/styles/style.qss");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        this->setStyleSheet(file.readAll());
        file.close();
    }

    Utilities_obj = new Utilities(this->parent());

    /*modbus协议栈初始化*/
    modbus_stack_init();

    /*串口初始化*/
    serial_opt_init();

    /*界面初始化*/
    ui->set_pushButton->setVisible(false);

    Timer = new QTimer(this);
    Timer->setInterval(POLL_PERIOD_TIME_MS);
    connect(Timer, &QTimer::timeout ,this, &MainWindow::slot_timer_timeout);
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::modbus_stack_init
 */
void MainWindow::modbus_stack_init()
{
    modbus_stack_obj = new modbus_module(this, Utilities_obj->serial_obj);
    connect(modbus_stack_obj, &modbus_module::signal_master_modbus_set_ok, this, &MainWindow::slot_master_modbus_set_ok);
    connect(modbus_stack_obj, &modbus_module::signal_master_modbus_read_ok, this, &MainWindow::slot_master_modbus_read_ok);
    connect(modbus_stack_obj, &modbus_module::signal_master_modbus_timeout_error, this, &MainWindow::slot_master_modbus_timeout_error);
    connect(modbus_stack_obj, &modbus_module::signal_master_modbus_unknow_error, this, &MainWindow::slot_master_modbus_unknow_error);
}

/**
 * @brief MainWindow::serial_opt_init
 */
void MainWindow::serial_opt_init()
{
    if(Utilities_obj == nullptr)
    {
        return;
    }

    if(Utilities_obj->serial_obj == nullptr)
    {
        return;
    }

    connect(Utilities_obj->serial_obj, &serial_opt::signal_scan_serial_port, this, &MainWindow::slot_scan_serial_port);
    Utilities_obj->serial_obj->scan_serial_port();

    /*建立环形缓冲区*/
    Utilities_obj->serial_obj->create_cq_buf(CircularQueue::CQ_BUF_2K);

    /*启动modbus主机协议栈*/
    modbus_stack_obj->set_modbus_cq_handle(Utilities_obj->serial_obj->CQ_Buf_Obj->get_cq_handle());

    if(Utilities_obj->serial_obj->have_cq_buf == true)
    {
        modbus_stack_obj->modbus_stack_start();
    }
}

/**
 * @brief MainWindow::slot_scan_serial_port
 * @param port_name_list
 */
void MainWindow::slot_scan_serial_port(const QStringList &port_name_list)
{
    ui->com_list_comboBox->clear();
    for(int index = 0; index < port_name_list.size(); index++)
    {
        ui->com_list_comboBox->addItem(port_name_list.value(index));
    }
}

/**
 * @brief MainWindow::on_set_pushButton_clicked
 */
void MainWindow::on_set_pushButton_clicked()
{
    uint16_t send_buf[128];

    /*高温*/
    if(ui->hi_temp_lineEdit->text().toFloat() > temp_hi_set || ui->hi_temp_lineEdit->text().toFloat() < temp_hi_set)
    {
        temp_hi_set = ui->hi_temp_lineEdit->text().toFloat();
        int temp_hi_set_int = temp_hi_set*1000;
        send_buf[0] = static_cast<uint16_t>(((temp_hi_set_int >> 16)&0xFFFF));
        send_buf[1] = static_cast<uint16_t>((temp_hi_set_int&0xFFFF));
        modbus_stack_obj->modbus_send_data_m(1, REG_HI_TEMP_VALUE, 2, send_buf);
    }

    /*低温*/
    if(ui->low_temp_lineEdit->text().toFloat() > temp_low_set || ui->low_temp_lineEdit->text().toFloat() < temp_low_set)
    {
        temp_low_set = ui->low_temp_lineEdit->text().toFloat();
        int temp_low_set_int = temp_hi_set*1000;
        send_buf[0] = static_cast<uint16_t>(((temp_low_set_int >> 16)&0xFFFF));
        send_buf[1] = static_cast<uint16_t>((temp_low_set_int&0xFFFF));
        modbus_stack_obj->modbus_send_data_m(1, REG_LOW_TEMP_VALUE, 2, send_buf);
    }

    /*补偿*/
    if(compensation_list.size() > 0)
    {
        COMPENSATION_VALUE_Typedef_t compensation_value;
        for(int reg = 10390; reg < compensation_list.size()+10390;reg++)
        {
            compensation_value = compensation_list.front();
            send_buf[0] = static_cast<int16_t>(atoi(compensation_value.value));
            modbus_stack_obj->modbus_send_data_m(1, reg, 1, send_buf);
            compensation_list.removeFirst();
        }
    }
}

/**
 * @brief MainWindow::on_pushButton_clicked
 */
void MainWindow::on_get_temp_compensation_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "../", "ini(*.ini)");
    if(path.isEmpty() == false)
    {
        qDebug() << path;
        mINI::INIFile file(path.toStdString());
        mINI::INIStructure ini;
        bool readSuccess = file.read(ini);
        if(readSuccess == true)
        {
            ui->statusbar->showMessage(tr("读取ini成功."), 1000);
        }

        COMPENSATION_VALUE_Typedef_t compensation_value;
        memset(&compensation_value, 0, sizeof(COMPENSATION_VALUE_Typedef_t));
        compensation_list.clear();

        for (auto const& it : ini)
        {
            //auto const& section = it.first;
            auto const& collection = it.second;
            //std::cout << "[" << section << "]" << std::endl;
            for (auto const& it2 : collection)
            {
                auto const& key = it2.first;
                auto const& value = it2.second;
                //std::cout << key << "=" << value << std::endl;
                /*更新补偿*/
                strncpy(compensation_value.key, key.data(), 64);
                strncpy(compensation_value.value, value.data(), 64);
                compensation_list.append(compensation_value);
            }
        }
        ui->statusbar->showMessage(tr("已更新补偿."), 1000);
    }
}

/**
 * @brief MainWindow::on_connect_pushButton_clicked
 */
void MainWindow::on_connect_pushButton_clicked()
{
    if(Utilities_obj == nullptr)
    {
        qDebug() << "error";
        return;
    }
    if(Utilities_obj->serial_obj == nullptr)
    {
        qDebug() << "error";
        return;
    }
    if(Utilities_obj->serial_obj->connect_state == true)
    {
        qDebug() << "关闭串口";
        Utilities_obj->serial_obj->close();
    }
    else
    {
        qDebug() << "打开串口";
        Utilities_obj->serial_obj->set_baud_rate(static_cast<QSerialPort::BaudRate>(ui->baudrate_comboBox->currentText().toInt()));
        Utilities_obj->serial_obj->set_port_name(ui->com_list_comboBox->currentText());
        Utilities_obj->serial_obj->set_parity();
        Utilities_obj->serial_obj->set_data_bits();
        Utilities_obj->serial_obj->set_stop_bits();
        if(Utilities_obj->serial_obj->open() == false)
        {
            qDebug() << "打开串口失败";
        }
    }

    if(Utilities_obj->serial_obj->connect_state == true)
    {
        ui->connect_pushButton->setText("断开");
    }
    else
    {
        ui->connect_pushButton->setText("连接");
    }
}

/**
 * @brief MainWindow::on_rescan_pushButton_clicked
 */
void MainWindow::on_rescan_pushButton_clicked()
{
    if(Utilities_obj == nullptr)
    {
        return;
    }

    if(Utilities_obj->serial_obj == nullptr)
    {
        return;
    }
    Utilities_obj->serial_obj->scan_serial_port();
}

/**
 * @brief MainWindow::on_down_par_checkBox_clicked
 * @param checked
 */
void MainWindow::on_down_par_checkBox_clicked(bool checked)
{
    ui->set_pushButton->setVisible(checked);
    if(checked == false)
    {
       modbus_stack_obj->modbus_stack_stop();
    }
    else
    {
        modbus_stack_obj->modbus_stack_start();
    }
}

/**
 * @brief MainWindow::slot_master_modbus_set_ok
 * @param slave_id
 * @param reg_addr
 * @param reg_num
 */
void MainWindow::slot_master_modbus_set_ok(uint8_t slave_id, uint16_t reg_addr, uint16_t reg_num)
{
    QString msg;
    msg = QString("set id %1,reg %2,num %3,ok.").arg(slave_id).arg(reg_addr).arg(reg_num);
    ui->statusbar->showMessage(msg, 1000);
}

/**
 * @brief MainWindow::slot_master_modbus_read_ok
 * @param slave_id
 * @param reg_addr
 * @param reg_num
 * @param modbus_frame
 */
void MainWindow::slot_master_modbus_read_ok(uint8_t slave_id, uint16_t reg_addr, uint16_t reg_num, uint8_t *modbus_frame)
{
    Q_UNUSED(slave_id)
    Q_UNUSED(reg_num)

    switch(reg_addr)
    {
        case REG_REAL_TIME_TEMPERATURE:
            update_temperature(modbus_frame);
            break;
        case REG_REAL_TIME_HUMIDITY:
            update_humidity(modbus_frame);
            break;
        case REG_LOW_TEMP_VALUE:
            update_low_temp(modbus_frame);
            break;
        case REG_HI_TEMP_VALUE:
            update_hi_temp(modbus_frame);
            break;
        default:
            ui->statusbar->showMessage(tr("unknow reg."), 500);
            return;
    }
}

/**
 * @brief MainWindow::update_temperature
 * @param data
 */
void MainWindow::update_temperature(const uint8_t *data)
{
    int temp = data[0];
    temp <<= 8;
    temp |= data[1];
    temp <<= 8;
    temp |= data[2];
    temp <<= 8;
    temp |= data[3];
    float temp_value;
    memmove(&temp_value, &temp, sizeof(int));
    ui->temp_lineEdit->setText(QString("%1").arg(temp_value));
}

/**
 * @brief MainWindow::update_humidity
 * @param data
 */
void MainWindow::update_humidity(const uint8_t *data)
{
    int temp = data[0];
    temp <<= 8;
    temp |= data[1];
    temp <<= 8;
    temp |= data[2];
    temp <<= 8;
    temp |= data[3];
    float humidity_value;
    memmove(&humidity_value, &temp, sizeof(int));
    ui->temp_lineEdit->setText(QString("%1").arg(humidity_value));
}

/**
 * @brief MainWindow::update_hi_temp
 * @param data
 */
void MainWindow::update_hi_temp(const uint8_t *data)
{
    int temp = data[0];
    temp <<= 8;
    temp |= data[1];
    temp <<= 8;
    temp |= data[2];
    temp <<= 8;
    temp |= data[3];
    float temp_value = temp/1000;
    ui->temp_lineEdit->setText(QString("%1").arg(temp_value));
}

/**
 * @brief MainWindow::update_low_temp
 * @param data
 */
void MainWindow::update_low_temp(const uint8_t *data)
{
    int temp = data[0];
    temp <<= 8;
    temp |= data[1];
    temp <<= 8;
    temp |= data[2];
    temp <<= 8;
    temp |= data[3];
    float temp_value = temp/1000;
    ui->temp_lineEdit->setText(QString("%1").arg(temp_value));
}

/**
 * @brief MainWindow::slot_master_modbus_timeout_error
 */
void MainWindow::slot_master_modbus_timeout_error()
{
    ui->statusbar->showMessage(tr("modbus timeout."), 1000);
}

/**
 * @brief MainWindow::slot_master_modbus_unknow_error
 */
void MainWindow::slot_master_modbus_unknow_error()
{
    ui->statusbar->showMessage(tr("modbus unknow error."), 1000);
}


/**
 * @brief MainWindow::slot_timer_timeout
 */
void MainWindow::slot_timer_timeout()
{
    /*判断串口即modbus状态*/
    if(Utilities_obj->serial_obj->connect_state == false)
    {
        return;
    }

    if(modbus_stack_obj->run_state == false)
    {
        return;
    }

    /*读取温度、湿度*/
    modbus_stack_obj->modbus_read_data_m(1, REG_REAL_TIME_TEMPERATURE, 2);
    modbus_stack_obj->modbus_read_data_m(1, REG_REAL_TIME_HUMIDITY, 2);

    /*报警值*/
    modbus_stack_obj->modbus_read_data_m(1, REG_LOW_TEMP_VALUE, 2);
    modbus_stack_obj->modbus_read_data_m(1, REG_HI_TEMP_VALUE, 2);
}
/* ---------------------------- end of file ----------------------------------*/
