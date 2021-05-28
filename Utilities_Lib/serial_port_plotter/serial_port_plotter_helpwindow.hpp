/**
 *  @file serial_port_plotter_HelpWindow.h
 *
 *  @date 2021-05-28
 *
 *  @author aron566
 *
 *  @brief None
 *
 *  @version V1.0
 */
#ifndef SERIAL_PORT_PLOTTER_HELPWINDOW_HPP
#define SERIAL_PORT_PLOTTER_HELPWINDOW_HPP
/** Includes -----------------------------------------------------------------*/
#include <stdint.h> /**< need definition of uint8_t */
#include <stddef.h> /**< need definition of NULL    */
#include <stdbool.h>/**< need definition of BOOL    */
#include <stdio.h>  /**< if need printf             */
#include <stdlib.h>
#include <string.h>
/** Private includes ---------------------------------------------------------*/
#include <QDialog>
#include "ui_serial_port_plotter_HelpWindow.h"
/** Private defines ----------------------------------------------------------*/

/** Exported typedefines -----------------------------------------------------*/

/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/

namespace Ui {
    class serial_port_plotter_HelpWindow;
}

class serial_port_plotter_HelpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit serial_port_plotter_HelpWindow(QWidget *parent = 0);
    ~serial_port_plotter_HelpWindow();

private:
    Ui::serial_port_plotter_HelpWindow *ui;
};

#endif // HELPWINDOW_HPP
/******************************** End of file *********************************/
