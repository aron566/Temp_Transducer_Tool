/**
  ******************************************************************************
  * @file    modbus_mode.cpp
  * @author  aron566
  * @version v1.0
  * @date    2021-05-28
  * @brief   None.
  ******************************************************************************
  */
/* Header includes -----------------------------------------------------------*/
#include "modbus_module.h"
#include <QDateTime>
/* Macro definitions ---------------------------------------------------------*/
#define RESPONSE_TIMEOUT_MAX    3/**< 超时3s*/
#define MODBUS_SEND_CMD         0x10
#define MODBUS_READ_CMD         0x03

#define MODBUS_FRAME_READ_SIZE_MIN  7/**< 主机读取回复最小帧长*/
#define MODBUS_FRAME_SEND_SIZE_MIN  8/**< 主机写入回复最小帧长*/

#if MODBUS_FRAME_READ_SIZE_MIN < MODBUS_FRAME_SEND_SIZE_MIN
    #define MODBUS_FRAME_SIZE_MIN  MODBUS_FRAME_READ_SIZE_MIN
#else
    #define MODBUS_FRAME_SIZE_MIN MODBUS_FRAME_SEND_SIZE_MIN
#endif
#define GET_U16_HI_BYTE(data)   (static_cast<uint8_t>((data>>8)&0x00FF))/**< 获得u16数据高字节*/
#define GET_U16_LOW_BYTE(data)  (static_cast<uint8_t>(data&0x00FF))/**< 获得u16数据低字节*/
/* Type definitions ----------------------------------------------------------*/
/* Variable declarations -----------------------------------------------------*/
/* Variable definitions ------------------------------------------------------*/
static const uint8_t auchCRCHi[] = {
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
  0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
  0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
  0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
  0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
  0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
  0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
  0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
  0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
  0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
  0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
  0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
  0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
  0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
  0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
  0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
  0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
  0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
};

static const uint8_t auchCRCLo[] = {
  0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
  0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
  0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
  0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
  0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
  0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
  0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
  0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
  0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
  0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
  0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
  0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
  0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
  0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
  0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
  0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
  0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
  0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
  0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
  0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
  0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
  0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
  0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
  0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
  0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
  0x43, 0x83, 0x41, 0x81, 0x80, 0x40
};
/* Function declarations -----------------------------------------------------*/
/* Function definitions ------------------------------------------------------*/
/**
 * @brief modbus_mode::modbus_mode
 * @param parent
 */
modbus_module::modbus_module(QObject *parent, serial_opt *serial_obj) : QObject(parent),
    serial_opt_obj(serial_obj)
{
    Timer = new QTimer(this);
    Timer->setInterval(1);
    connect(Timer, &QTimer::timeout, this, &modbus_module::slot_timer_timeout);

    send_buf = new uint8_t[256];
    if(send_buf == nullptr)
    {
        qDebug() << "modbus init error.";
        return;
    }

    /*建立环形缓冲区*/
//    serial_opt_obj->create_cq_buf(CircularQueue::CQ_BUF_2K);
//    cq = serial_opt_obj->CQ_Buf_Obj->get_cq_handle();
//    if(cq == nullptr)
//    {
//        qDebug() << "cq is null error";
//    }
}

modbus_module::~modbus_module()
{
    delete[] send_buf;
}

/**
 * @brief modbus_mode::modbus_send_data_m
 * @param slave_id
 * @param reg
 * @param num
 * @param data
 * @return
 */
bool modbus_module::modbus_send_data_m(uint8_t slave_id, uint16_t reg, uint16_t num, const uint16_t *data)
{
    if(send_buf == nullptr || serial_opt_obj == nullptr || run_state == false)
    {
        return false;
    }
    uint16_t index = 0;

    send_buf[index++] = slave_id;
    send_buf[index++] = MODBUS_SEND_CMD;

    send_buf[index++] = GET_U16_HI_BYTE(reg);
    send_buf[index++] = GET_U16_LOW_BYTE(reg);
    send_buf[index++] = GET_U16_HI_BYTE(num);
    send_buf[index++] = GET_U16_LOW_BYTE(num);

    send_buf[index++] = static_cast<uint8_t>(num*2);

    for(uint16_t i = 0; i < num; i++)
    {
        send_buf[index++] = GET_U16_HI_BYTE(data[i]);
        send_buf[index++] = GET_U16_LOW_BYTE(data[i]);
    }

    uint16_t crc_val = modbus_crc_return_with_table(send_buf, index);
    send_buf[index++] = GET_U16_LOW_BYTE(crc_val);
    send_buf[index++] = GET_U16_HI_BYTE(crc_val);

    if(serial_opt_obj->write(reinterpret_cast<const char *>(send_buf), static_cast<qint64>(index)) < 0)
    {
        qDebug() << "modbus send error.";
        return false;
    }

    WAIT_RESPONSE_DATA_Typedef_t wait;
    wait.id = slave_id;
    wait.cmd = MODBUS_SEND_CMD;
    wait.reg = reg;
    wait.reg_num = num;
    wait.start_time = QDateTime::currentSecsSinceEpoch();
    modbus_wait_list.append(wait);

    /*即刻解析*/
    decode_modbus_frame_start();
    return true;
}

/**
 * @brief modbus_module::modbus_read_data_m
 * @param slave_id
 * @param reg
 * @param num
 * @return
 */
bool modbus_module::modbus_read_data_m(uint8_t slave_id, uint16_t reg, uint16_t num)
{
    if(send_buf == nullptr || serial_opt_obj == nullptr || run_state == false)
    {
        return false;
    }

    uint16_t index = 0;

    send_buf[index++] = slave_id;
    send_buf[index++] = MODBUS_READ_CMD;

    send_buf[index++] = GET_U16_HI_BYTE(reg);
    send_buf[index++] = GET_U16_LOW_BYTE(reg);
    send_buf[index++] = GET_U16_HI_BYTE(num);
    send_buf[index++] = GET_U16_LOW_BYTE(num);

    uint16_t crc_val = modbus_crc_return_with_table(send_buf, index);
    send_buf[index++] = GET_U16_LOW_BYTE(crc_val);
    send_buf[index++] = GET_U16_HI_BYTE(crc_val);
    if(serial_opt_obj->write(reinterpret_cast<const char *>(send_buf), static_cast<qint64>(index)) < 0)
    {
        qDebug() << "modbus read error.";
        return false;
    }

    WAIT_RESPONSE_DATA_Typedef_t wait;
    wait.id = slave_id;
    wait.cmd = MODBUS_READ_CMD;
    wait.reg = reg;
    wait.reg_num = num;
    wait.start_time = QDateTime::currentSecsSinceEpoch();
    modbus_wait_list.append(wait);

    /*即刻解析*/
    decode_modbus_frame_start();
    return true;
}

/**
 * @brief modbus CRC
 *
 * @param Data
 * @param GenPoly
 * @param CrcData
 * @return uint16_t
 */
uint16_t modbus_module::modbus_crc_cal(uint16_t Data ,uint16_t GenPoly ,uint16_t CrcData)
{
  uint16_t TmpI;
  Data *= 2;
  for(TmpI = 8; TmpI > 0; TmpI--)
  {
    Data = Data / 2;
    if ((Data ^ CrcData) & 1)
      CrcData = (CrcData / 2) ^ GenPoly;
    else
      CrcData /= 2;
  }
  return CrcData;
}

/**
 * @brief modbusCRC value
 *
 * @param data
 * @param data_len
 * @return uint16_t
 */
uint16_t modbus_module::modbus_crc_return(uint8_t *data, uint16_t data_len)
{
  uint16_t temp;
  uint16_t crc_ret = 0xFFFF;
  for (temp = 0; temp < data_len; temp++)
  {
    crc_ret = modbus_crc_cal(data[temp], 0xA001, crc_ret);
  }
  return crc_ret;
}

/**
 * @brief modbusCRC calc with table
 *
 * @param data data
 * @param data_len data len
 * @return uint16_t
 */
uint16_t modbus_module::modbus_crc_return_with_table(uint8_t *data, uint16_t data_len)
{
  uint8_t ucCRCHi = 0xFF;
  uint8_t ucCRCLo = 0xFF;
  int iIndex;

  while(data_len--)
  {
    iIndex = ucCRCLo ^ *(data++);
    //
    //
    ucCRCLo = static_cast<uint8_t>((ucCRCHi ^ auchCRCHi[iIndex]));
    ucCRCHi = auchCRCLo[iIndex];
  }
  return static_cast<uint16_t>(( ucCRCHi << 8 | ucCRCLo ));
}

/**
 * @brief get crc result
 *
 * @param msg data
 * @param len data len
 * @return true ok
 */
bool modbus_module::modbus_get_crc_result(uint8_t *msg ,uint16_t len)
{
  uint8_t CRC_value_L,CRC_value_H,CRC_value_L_temp,CRC_value_H_temp;
  uint16_t crc_ret = 0;
  crc_ret = modbus_crc_return(msg, len);
  CRC_value_L_temp = *(msg + len);
  CRC_value_H_temp = *(msg + len + 1);
  CRC_value_L = static_cast<uint8_t>(crc_ret &0x00FF);
  CRC_value_H = static_cast<uint8_t>((crc_ret>>8)&0x00FF);
  if(CRC_value_L == CRC_value_L_temp && CRC_value_H == CRC_value_H_temp)
  {
    return true;
  }
  else
  {
    return false;
  }
}

modbus_module::MODBUS_RETUN_RES_Typedef_t modbus_module::modbus_decode_frame(WAIT_RESPONSE_DATA_Typedef_t &wait)
{
    QCoreApplication::processEvents();

    uint32_t buf_len = 0;

    while(1)
    {
        /*检测超时*/
        if((QDateTime::currentSecsSinceEpoch() - wait.start_time) > RESPONSE_TIMEOUT_MAX)
        {
            serial_opt_obj->CQ_Buf_Obj->CQ_emptyData(cq);
            return RES_TIMEOUT;
        }

        /*检测帧长*/
        buf_len = serial_opt_obj->CQ_Buf_Obj->CQ_skipInvaildU8Header(cq, wait.id);
        if(buf_len < MODBUS_FRAME_SIZE_MIN)
        {
            continue;
        }

        /*校验功能码*/
        uint8_t cmd = serial_opt_obj->CQ_Buf_Obj->CQ_ManualGet_Offset_Data(cq, 1);
        if(wait.cmd != cmd)
        {
            serial_opt_obj->CQ_Buf_Obj->CQ_emptyData(cq);
            return RES_ERROR;
        }

        switch(cmd)
        {
            case MODBUS_SEND_CMD:
            {
                uint16_t reg = 0, reg_num = 0;
                /*二次校验长度*/
                if(buf_len < MODBUS_FRAME_SEND_SIZE_MIN)
                {
                    continue;
                }

                /*校验寄存器*/
                reg = serial_opt_obj->CQ_Buf_Obj->CQ_ManualGet_Offset_Data(cq, 2);
                reg <<= 8;
                reg += serial_opt_obj->CQ_Buf_Obj->CQ_ManualGet_Offset_Data(cq, 3);
                reg_num = serial_opt_obj->CQ_Buf_Obj->CQ_ManualGet_Offset_Data(cq, 4);
                reg_num <<= 8;
                reg_num += serial_opt_obj->CQ_Buf_Obj->CQ_ManualGet_Offset_Data(cq, 5);
                if(reg != wait.reg || reg_num != wait.reg_num)
                {
                    serial_opt_obj->CQ_Buf_Obj->CQ_emptyData(cq);
                    return RES_ERROR;
                }

                /*校验CRC*/
                serial_opt_obj->CQ_Buf_Obj->CQ_ManualGetData(cq, modbus_frame, MODBUS_FRAME_SEND_SIZE_MIN);
                serial_opt_obj->CQ_Buf_Obj->CQ_emptyData(cq);
                if(modbus_get_crc_result(modbus_frame, MODBUS_FRAME_SEND_SIZE_MIN-2) == false)
                {
                    return RES_ERROR;
                }
                return RES_SET_OK;
            }
            case MODBUS_READ_CMD:
            {
                uint8_t data_size = serial_opt_obj->CQ_Buf_Obj->CQ_ManualGet_Offset_Data(cq, 2);
                uint16_t frame_len = data_size+5;
                frame_len = frame_len > 256?256:frame_len;

                /*二次校验长度*/
                if(buf_len < frame_len)
                {
                    continue;
                }

                /*校验CRC*/
                serial_opt_obj->CQ_Buf_Obj->CQ_ManualGetData(cq, modbus_frame, frame_len);
                serial_opt_obj->CQ_Buf_Obj->CQ_emptyData(cq);
                if(modbus_get_crc_result(modbus_frame, frame_len-2) == false)
                {
                    return RES_ERROR;
                }
                return RES_READ_OK;
            }
            default:
                serial_opt_obj->CQ_Buf_Obj->CQ_emptyData(cq);
                return RES_ERROR;
        }
    }
}

/**
 * @brief modbus_module::decode_modbus_frame_start
 */
void modbus_module::decode_modbus_frame_start()
{
    if(run_state == false)
    {
        Timer->stop();
        modbus_wait_list.clear();
        serial_opt_obj->CQ_Buf_Obj->CQ_emptyData(cq);
    }
    if(modbus_wait_list.isEmpty() == true)
    {
        return;
    }

    WAIT_RESPONSE_DATA_Typedef_t wait = modbus_wait_list.front();

    MODBUS_RETUN_RES_Typedef_t ret = modbus_decode_frame(wait);
    switch(ret)
    {
        case RES_SET_OK:
            emit signal_master_modbus_set_ok(wait.id, wait.reg, wait.reg_num);
            modbus_wait_list.removeFirst();
            break;
        case RES_READ_OK:
            emit signal_master_modbus_read_ok(wait.id, wait.reg, wait.reg_num, modbus_frame+3);
            modbus_wait_list.removeFirst();
            break;
        case RES_TIMEOUT:
            emit signal_master_modbus_timeout_error();
            modbus_wait_list.removeFirst();
            break;
        case RES_ERROR:
            emit signal_master_modbus_unknow_error();
            modbus_wait_list.removeFirst();
            break;
        default:
            break;
    }
}

/**
 * @brief modbus_module::slot_timer_timeout
 */
void modbus_module::slot_timer_timeout()
{
//    if(run_state == false)
//    {
//        Timer->stop();
//        modbus_wait_list.clear();
//        serial_opt_obj->CQ_Buf_Obj->CQ_emptyData(cq);
//    }
//    if(modbus_wait_list.isEmpty() == true)
//    {
//        return;
//    }

//    WAIT_RESPONSE_DATA_Typedef_t wait = modbus_wait_list.front();

//    MODBUS_RETUN_RES_Typedef_t ret = modbus_decode_frame(wait);
//    switch(ret)
//    {
//        case RES_SET_OK:
//            emit signal_master_modbus_set_ok(wait.id, wait.reg, wait.reg_num);
//            modbus_wait_list.removeFirst();
//            break;
//        case RES_READ_OK:
//            emit signal_master_modbus_read_ok(wait.id, wait.reg, wait.reg_num, modbus_frame+3);
//            modbus_wait_list.removeFirst();
//            break;
//        case RES_TIMEOUT:
//            emit signal_master_modbus_timeout_error();
//            modbus_wait_list.removeFirst();
//            break;
//        case RES_ERROR:
//            emit signal_master_modbus_unknow_error();
//            modbus_wait_list.removeFirst();
//            break;
//        default:
//            break;
//    }
}
/* ---------------------------- end of file ----------------------------------*/
