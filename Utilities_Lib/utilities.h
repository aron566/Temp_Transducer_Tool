/**
 *  @file utilities.h
 *
 *  @date 2021-05-28
 *
 *  @author aron566
 *
 *  @brief None
 *
 *  @version V1.0
 */
#ifndef UTILITIES_H
#define UTILITIES_H
/** Includes -----------------------------------------------------------------*/
#include <stdint.h> /**< need definition of uint8_t */
#include <stddef.h> /**< need definition of NULL    */
#include <stdbool.h>/**< need definition of BOOL    */
#include <stdio.h>  /**< if need printf             */
#include <stdlib.h>
#include <string.h>
/** Private includes ---------------------------------------------------------*/
#include "Utilities_global.h"
#include "serial_opt/serial_opt.h"
#include "ini_parser/IniParser.h"
#include "serial_port_plotter/serial_port_plotter.hpp"
/** Private defines ----------------------------------------------------------*/

/** Exported typedefines -----------------------------------------------------*/

/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/
/**
 * @brief The Utilities class
 */
class UTILITIES_EXPORT Utilities: public QObject
{
    Q_OBJECT
public:
    explicit Utilities(QObject *parent = nullptr);

    ~Utilities();

public:
    /**
     * @brief serial_port_plotter_window_show
     */
    void serial_port_plotter_window_show();
public:
    /*串口操作接口*/
    serial_opt *serial_obj = nullptr;

    /*ini文件解析*/
    IniParser *IniParser_obj = nullptr;

    /*多通道曲线绘制*/
    serial_port_plotter *serial_port_plotter_obj = nullptr;
};

#endif // UTILITIES_H
/******************************** End of file *********************************/
