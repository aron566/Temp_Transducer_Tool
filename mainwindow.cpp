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
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_set_pushButton_clicked
 */
void MainWindow::on_set_pushButton_clicked()
{

}

/**
 * @brief MainWindow::on_pushButton_clicked
 */
void MainWindow::on_get_temp_compensation_pushButton_clicked()
{

}
/* ---------------------------- end of file ----------------------------------*/
