/**
 *  @file .h
 *
 *  @date 2021-
 *
 *  @author aron566
 *
 *  @brief None
 *
 *  @version V1.0
 */
#ifndef MODBUS_MODE_H
#define MODBUS_MODE_H
/** Includes -----------------------------------------------------------------*/
#include <stdint.h> /**< need definition of uint8_t */
#include <stddef.h> /**< need definition of NULL    */
#include <stdbool.h>/**< need definition of BOOL    */
#include <stdio.h>  /**< if need printf             */
#include <stdlib.h>
#include <string.h>
/** Private includes ---------------------------------------------------------*/
#include <QObject>
#include <QTimer>
#include "Utilities_Lib/utilities.h"
/** Private defines ----------------------------------------------------------*/

/** Exported typedefines -----------------------------------------------------*/

/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/
/**
 * @brief The modbus_mode class
 */
class modbus_mode : public QObject
{
    Q_OBJECT
public:
    explicit modbus_mode(QObject *parent = nullptr, serial_opt *serial_obj = nullptr);
    ~modbus_mode();

private:
    typedef enum
    {
        RES_OK = 0,
        RES_TIMEOUT,
        RES_ERROR
    }MODBUS_RETUN_RES_Typedef_t;

    typedef struct
    {
        uint8_t cmd;
        uint16_t reg;
        uint16_t reg_num;
        qint64 start_time;
    }WAIT_RESPONSE_DATA_Typedef_t;
public:
    void modbus_stack_start()
    {
        run_state = true;
    }
    void modbus_stack_stop()
    {
        run_state = false;
    }

    /**
     * @brief set_modbus_cq_handle
     * @param cq_handle
     */
    void set_modbus_cq_handle(CircularQueue::CQ_handleTypeDef *cq_handle)
    {
        cq = cq_handle;
    }
    bool modbus_send_data_m(uint8_t slave_id, uint16_t reg, uint16_t num, const uint16_t *data);
    bool modbus_read_data_m(uint8_t slave_id, uint16_t reg, uint16_t num, uint16_t *rev_buf);

    static uint16_t modbus_crc_cal(uint16_t Data ,uint16_t GenPoly ,uint16_t CrcData);
    /*计算CRC*/
    static uint16_t modbus_crc_return(uint8_t *data, uint16_t data_len);
    /*查表法计算modbus CRC16*/
    static uint16_t modbus_crc_return_with_table(uint8_t *data, uint16_t data_len);
    /*计算CRC16并对比数据包中的CRC，返回结果，数据包含crc计算内容+crc结果，否则可能指针越界访问*/
    static bool modbus_get_crc_result(uint8_t *msg, uint16_t len);

private:
    /**
     * @brief modbus_decode_frame
     * @return
     */
    MODBUS_RETUN_RES_Typedef_t modbus_decode_frame(WAIT_RESPONSE_DATA_Typedef_t &wait);
private:
    QTimer *Timer = nullptr;

    serial_opt *serial_opt_obj = nullptr;
private:
    CircularQueue::CQ_handleTypeDef *cq = nullptr;

    uint8_t *send_buf = nullptr;

    QList<WAIT_RESPONSE_DATA_Typedef_t> modbus_wait_list;
signals:

public:
    bool run_state = false;
private slots:
    /**
     * @brief slot_timer_timeout
     */
    void slot_timer_timeout();

};

#endif // MODBUS_MODE_H
/******************************** End of file *********************************/
