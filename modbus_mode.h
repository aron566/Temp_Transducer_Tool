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
    explicit modbus_mode(QObject *parent = nullptr);

public:
    bool modbus_send_data_m(uint16_t reg, uint8_t num, const uint8_t *data, uint16_t len);
    bool modbus_read_data_m(uint16_t reg, uint8_t num, uint8_t *rev_buf);
signals:

};

#endif // MODBUS_MODE_H
/******************************** End of file *********************************/
