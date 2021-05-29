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

    Utilities_obj = new Utilities(this->parent());

    modbus_stack_obj = new modbus_mode(this, Utilities_obj->serial_obj);

    /*串口初始化*/
    serial_opt_init();
}

MainWindow::~MainWindow()
{
    delete ui;
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
    if(ui->hi_temp_lineEdit->text().toFloat() > temp_hi_set || ui->hi_temp_lineEdit->text().toFloat() < temp_hi_set)
    {
        temp_hi_set = ui->hi_temp_lineEdit->text().toFloat();
    }

    if(ui->low_temp_lineEdit->text().toFloat() > temp_low_set || ui->low_temp_lineEdit->text().toFloat() < temp_low_set)
    {
        temp_low_set = ui->low_temp_lineEdit->text().toFloat();
    }
}

/**
 * @brief MainWindow::on_pushButton_clicked
 */
void MainWindow::on_get_temp_compensation_pushButton_clicked()
{

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
/* ---------------------------- end of file ----------------------------------*/
