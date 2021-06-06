/**
 *  @file mainwindow.h
 *
 *  @date 2021-05-28
 *
 *  @author aron566
 *
 *  @brief 主界面
 *
 *  @version V1.0
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/** Includes -----------------------------------------------------------------*/
#include <stdint.h> /**< need definition of uint8_t */
#include <stddef.h> /**< need definition of NULL    */
#include <stdbool.h>/**< need definition of BOOL    */
#include <stdio.h>  /**< if need printf             */
#include <stdlib.h>
#include <string.h>
#include <cstring>
/** Private includes ---------------------------------------------------------*/
#include <QMainWindow>
#include <utilities.h>
#include <modbus_module.h>

//#define MINI_CASE_SENSITIVE /**< 检查ini文件内大小写*/
#include "ini.h"
/** Private defines ----------------------------------------------------------*/

/** Exported typedefines -----------------------------------------------------*/

/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /**
     * @brief serial_opt_init
     */
    void serial_opt_init();

    /**
     * @brief modbus_stack_init
     */
    void modbus_stack_init();
private slots:
    /**
     * @brief slot_scan_serial_port
     * @param port_name_list
     */
    void slot_scan_serial_port(const QStringList &port_name_list);
    /**
     * @brief on_set_pushButton_clicked
     */
    void on_set_pushButton_clicked();

    /**
     * @brief on_pushButton_clicked
     */
    void on_get_temp_compensation_pushButton_clicked();

    /**
     * @brief on_connect_pushButton_clicked
     */
    void on_connect_pushButton_clicked();

    /**
     * @brief on_rescan_pushButton_clicked
     */
    void on_rescan_pushButton_clicked();

    /**
     * @brief on_down_par_checkBox_clicked
     * @param checked
     */
    void on_down_par_checkBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;

    QTimer *Timer = nullptr;

    Utilities *Utilities_obj = nullptr;

    modbus_module *modbus_stack_obj = nullptr;
private:
    float temp_hi_set;
    float temp_low_set;
    typedef struct
    {
        char key[64];
        char value[64];
    }COMPENSATION_VALUE_Typedef_t;
    QList<COMPENSATION_VALUE_Typedef_t>compensation_list;
private slots:
    /**
     * @brief slot_master_modbus_set_ok
     * @param slave_id
     * @param reg_addr
     * @param reg_num
     */
    void slot_master_modbus_set_ok(uint8_t slave_id, uint16_t reg_addr, uint16_t reg_num);

    /**
     * @brief signal_master_modbus_read_ok
     * @param slave_id
     * @param reg_addr
     * @param reg_num
     * @param modbus_frame
     */
    void slot_master_modbus_read_ok(uint8_t slave_id, uint16_t reg_addr, uint16_t reg_num, uint8_t *modbus_frame);

    /**
     * @brief signal_master_modbus_timeout_error
     */
    void slot_master_modbus_timeout_error();

    /**
     * @brief signal_master_modbus_unknow_error
     */
    void slot_master_modbus_unknow_error();

    /**
     * @brief slot_timer_timeout
     */
    void slot_timer_timeout();

private:
    void update_temperature(const uint8_t *data);
    void update_humidity(const uint8_t *data);
    void update_hi_temp(const uint8_t *data);
    void update_low_temp(const uint8_t *data);
};

#endif // MAINWINDOW_H
/******************************** End of file *********************************/
