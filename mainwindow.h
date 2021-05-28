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
/** Private includes ---------------------------------------------------------*/
#include <QMainWindow>
#include <utilities.h>
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

private slots:
    /**
     * @brief on_set_pushButton_clicked
     */
    void on_set_pushButton_clicked();

    /**
     * @brief on_pushButton_clicked
     */
    void on_get_temp_compensation_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    Utilities *Utilities_obj = nullptr;
};

#endif // MAINWINDOW_H
/******************************** End of file *********************************/
