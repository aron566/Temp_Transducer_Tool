/********************************************************************************
** Form generated from reading UI file 'serial_port_plotter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAL_PORT_PLOTTER_H
#define UI_SERIAL_PORT_PLOTTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot/qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_serial_port_plotter
{
public:
    QAction *actionConnect;
    QAction *actionPause_Plot;
    QAction *actionDisconnect;
    QAction *actionClear;
    QAction *actionHow_to_use;
    QAction *actionRecord_stream;
    QAction *actionExit_Window;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *controlsLayout;
    QGroupBox *PortControlsBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPort;
    QComboBox *comboPort;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelBaud;
    QComboBox *comboBaud;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelData;
    QComboBox *comboData;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelParity;
    QComboBox *comboParity;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelStop;
    QComboBox *comboStop;
    QGroupBox *PlotControlsBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *plotControlsLayout;
    QHBoxLayout *horizontalLayout_10;
    QLabel *pointsLabel;
    QSpinBox *spinPoints;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelYStep;
    QSpinBox *spinYStep;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QSpinBox *spinAxesMin;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QSpinBox *spinAxesMax;
    QPushButton *pushButton_AutoScale;
    QListWidget *listWidget_Channels;
    QPushButton *pushButton_ResetVisible;
    QPushButton *savePNGButton;
    QSpacerItem *verticalSpacer;
    QGroupBox *gridGroupBox;
    QGridLayout *TextControlsBox;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_TextEditHide;
    QPushButton *pushButton_ShowallData;
    QGridLayout *gridLayout_4;
    QSplitter *splitter;
    QCustomPlot *plot;
    QTextEdit *textEdit_UartWindow;
    QSpacerItem *horizontalSpacer;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *serial_port_plotter)
    {
        if (serial_port_plotter->objectName().isEmpty())
            serial_port_plotter->setObjectName(QString::fromUtf8("serial_port_plotter"));
        serial_port_plotter->resize(1002, 743);
        serial_port_plotter->setMinimumSize(QSize(840, 620));
        actionConnect = new QAction(serial_port_plotter);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/serial_port_plotter/play_nor.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/serial_port_plotter/play_nor.png"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QString::fromUtf8(":/serial_port_plotter/play_dis.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/serial_port_plotter/play_dis.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon.addFile(QString::fromUtf8(":/serial_port_plotter/play_act.png"), QSize(), QIcon::Active, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/serial_port_plotter/play_act.png"), QSize(), QIcon::Active, QIcon::On);
        icon.addFile(QString::fromUtf8(":/serial_port_plotter/play_act.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/serial_port_plotter/play_act.png"), QSize(), QIcon::Selected, QIcon::On);
        actionConnect->setIcon(icon);
        actionPause_Plot = new QAction(serial_port_plotter);
        actionPause_Plot->setObjectName(QString::fromUtf8("actionPause_Plot"));
        actionPause_Plot->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/serial_port_plotter/pause_nor.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/serial_port_plotter/pause_nor.png"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/serial_port_plotter/pause_dis.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/serial_port_plotter/pause_dis.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/serial_port_plotter/pause_act.png"), QSize(), QIcon::Active, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/serial_port_plotter/pause_act.png"), QSize(), QIcon::Active, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/serial_port_plotter/pause_act.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/serial_port_plotter/pause_act.png"), QSize(), QIcon::Selected, QIcon::On);
        actionPause_Plot->setIcon(icon1);
        actionDisconnect = new QAction(serial_port_plotter);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        actionDisconnect->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/serial_port_plotter/stop_nor.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/serial_port_plotter/stop_nor.png"), QSize(), QIcon::Normal, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/serial_port_plotter/stop_dis.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/serial_port_plotter/stop_dis.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/serial_port_plotter/stop_act.png"), QSize(), QIcon::Active, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/serial_port_plotter/stop_act.png"), QSize(), QIcon::Active, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/serial_port_plotter/stop_act.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/serial_port_plotter/stop_act.png"), QSize(), QIcon::Selected, QIcon::On);
        actionDisconnect->setIcon(icon2);
        actionClear = new QAction(serial_port_plotter);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        actionClear->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/serial_port_plotter/clear_nor.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/serial_port_plotter/clear_nor.png"), QSize(), QIcon::Normal, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/serial_port_plotter/clear_dis.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/serial_port_plotter/clear_dis.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/serial_port_plotter/clear_act.png"), QSize(), QIcon::Active, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/serial_port_plotter/clear_act.png"), QSize(), QIcon::Active, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/serial_port_plotter/clear_act.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/serial_port_plotter/clear_act.png"), QSize(), QIcon::Selected, QIcon::On);
        actionClear->setIcon(icon3);
        actionHow_to_use = new QAction(serial_port_plotter);
        actionHow_to_use->setObjectName(QString::fromUtf8("actionHow_to_use"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/serial_port_plotter/help_nor.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/serial_port_plotter/help_nor.png"), QSize(), QIcon::Normal, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/serial_port_plotter/help_dis.png"), QSize(), QIcon::Disabled, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/serial_port_plotter/help_dis.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/serial_port_plotter/help_act.png"), QSize(), QIcon::Active, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/serial_port_plotter/help_act.png"), QSize(), QIcon::Active, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/serial_port_plotter/help_act.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/serial_port_plotter/help_act.png"), QSize(), QIcon::Selected, QIcon::On);
        actionHow_to_use->setIcon(icon4);
        actionRecord_stream = new QAction(serial_port_plotter);
        actionRecord_stream->setObjectName(QString::fromUtf8("actionRecord_stream"));
        actionRecord_stream->setCheckable(true);
        actionRecord_stream->setChecked(false);
        actionRecord_stream->setEnabled(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/line_icon_set/document.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QString::fromUtf8(":/icons/line_icon_set_text/document.png"), QSize(), QIcon::Normal, QIcon::On);
        icon5.addFile(QString::fromUtf8(":/icons/line_icon_set/document.png"), QSize(), QIcon::Disabled, QIcon::Off);
        actionRecord_stream->setIcon(icon5);
        actionRecord_stream->setVisible(true);
        actionExit_Window = new QAction(serial_port_plotter);
        actionExit_Window->setObjectName(QString::fromUtf8("actionExit_Window"));
        actionExit_Window->setCheckable(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/serial_port_plotter/icons/lynny-2x/Left Arrow 2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QString::fromUtf8(":/serial_port_plotter/icons/lynny-2x_white/Left Arrow 2.png"), QSize(), QIcon::Normal, QIcon::On);
        actionExit_Window->setIcon(icon6);
        centralWidget = new QWidget(serial_port_plotter);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        controlsLayout = new QVBoxLayout();
        controlsLayout->setSpacing(6);
        controlsLayout->setObjectName(QString::fromUtf8("controlsLayout"));
        PortControlsBox = new QGroupBox(centralWidget);
        PortControlsBox->setObjectName(QString::fromUtf8("PortControlsBox"));
        PortControlsBox->setFlat(false);
        PortControlsBox->setCheckable(false);
        gridLayout = new QGridLayout(PortControlsBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton = new QPushButton(PortControlsBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelPort = new QLabel(PortControlsBox);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        labelPort->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(labelPort);

        comboPort = new QComboBox(PortControlsBox);
        comboPort->setObjectName(QString::fromUtf8("comboPort"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboPort->sizePolicy().hasHeightForWidth());
        comboPort->setSizePolicy(sizePolicy);
        comboPort->setMinimumSize(QSize(69, 0));
        comboPort->setMaximumSize(QSize(69, 16777215));

        horizontalLayout->addWidget(comboPort);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelBaud = new QLabel(PortControlsBox);
        labelBaud->setObjectName(QString::fromUtf8("labelBaud"));
        labelBaud->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(labelBaud);

        comboBaud = new QComboBox(PortControlsBox);
        comboBaud->setObjectName(QString::fromUtf8("comboBaud"));
        sizePolicy.setHeightForWidth(comboBaud->sizePolicy().hasHeightForWidth());
        comboBaud->setSizePolicy(sizePolicy);
        comboBaud->setMinimumSize(QSize(69, 0));
        comboBaud->setMaximumSize(QSize(69, 16777215));
        comboBaud->setEditable(true);

        horizontalLayout_2->addWidget(comboBaud);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelData = new QLabel(PortControlsBox);
        labelData->setObjectName(QString::fromUtf8("labelData"));
        labelData->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(labelData);

        comboData = new QComboBox(PortControlsBox);
        comboData->setObjectName(QString::fromUtf8("comboData"));
        sizePolicy.setHeightForWidth(comboData->sizePolicy().hasHeightForWidth());
        comboData->setSizePolicy(sizePolicy);
        comboData->setMinimumSize(QSize(69, 0));
        comboData->setMaximumSize(QSize(69, 16777215));

        horizontalLayout_3->addWidget(comboData);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelParity = new QLabel(PortControlsBox);
        labelParity->setObjectName(QString::fromUtf8("labelParity"));
        labelParity->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(labelParity);

        comboParity = new QComboBox(PortControlsBox);
        comboParity->setObjectName(QString::fromUtf8("comboParity"));
        sizePolicy.setHeightForWidth(comboParity->sizePolicy().hasHeightForWidth());
        comboParity->setSizePolicy(sizePolicy);
        comboParity->setMinimumSize(QSize(69, 0));
        comboParity->setMaximumSize(QSize(69, 16777215));

        horizontalLayout_4->addWidget(comboParity);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelStop = new QLabel(PortControlsBox);
        labelStop->setObjectName(QString::fromUtf8("labelStop"));
        labelStop->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(labelStop);

        comboStop = new QComboBox(PortControlsBox);
        comboStop->setObjectName(QString::fromUtf8("comboStop"));
        sizePolicy.setHeightForWidth(comboStop->sizePolicy().hasHeightForWidth());
        comboStop->setSizePolicy(sizePolicy);
        comboStop->setMinimumSize(QSize(69, 0));
        comboStop->setMaximumSize(QSize(69, 16777215));

        horizontalLayout_5->addWidget(comboStop);


        verticalLayout_3->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        controlsLayout->addWidget(PortControlsBox);

        PlotControlsBox = new QGroupBox(centralWidget);
        PlotControlsBox->setObjectName(QString::fromUtf8("PlotControlsBox"));
        gridLayout_2 = new QGridLayout(PlotControlsBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        plotControlsLayout = new QVBoxLayout();
        plotControlsLayout->setSpacing(6);
        plotControlsLayout->setObjectName(QString::fromUtf8("plotControlsLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pointsLabel = new QLabel(PlotControlsBox);
        pointsLabel->setObjectName(QString::fromUtf8("pointsLabel"));
        pointsLabel->setMinimumSize(QSize(50, 0));
        pointsLabel->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_10->addWidget(pointsLabel);

        spinPoints = new QSpinBox(PlotControlsBox);
        spinPoints->setObjectName(QString::fromUtf8("spinPoints"));
        spinPoints->setMinimumSize(QSize(69, 0));
        spinPoints->setMaximumSize(QSize(69, 16777215));
        spinPoints->setMinimum(0);
        spinPoints->setMaximum(999999999);
        spinPoints->setSingleStep(10);
        spinPoints->setValue(1000);

        horizontalLayout_10->addWidget(spinPoints);


        plotControlsLayout->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        labelYStep = new QLabel(PlotControlsBox);
        labelYStep->setObjectName(QString::fromUtf8("labelYStep"));
        labelYStep->setMinimumSize(QSize(50, 0));
        labelYStep->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_9->addWidget(labelYStep);

        spinYStep = new QSpinBox(PlotControlsBox);
        spinYStep->setObjectName(QString::fromUtf8("spinYStep"));
        spinYStep->setMinimumSize(QSize(69, 0));
        spinYStep->setMaximumSize(QSize(69, 16777215));
        spinYStep->setMinimum(1);
        spinYStep->setMaximum(10000);
        spinYStep->setSingleStep(1);
        spinYStep->setValue(10);

        horizontalLayout_9->addWidget(spinYStep);


        plotControlsLayout->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label = new QLabel(PlotControlsBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 0));
        label->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_7->addWidget(label);

        spinAxesMin = new QSpinBox(PlotControlsBox);
        spinAxesMin->setObjectName(QString::fromUtf8("spinAxesMin"));
        spinAxesMin->setMinimumSize(QSize(69, 0));
        spinAxesMin->setMaximumSize(QSize(69, 16777215));
        spinAxesMin->setMinimum(-65536);
        spinAxesMin->setMaximum(65536);
        spinAxesMin->setSingleStep(10);
        spinAxesMin->setValue(-100);

        horizontalLayout_7->addWidget(spinAxesMin);


        plotControlsLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_2 = new QLabel(PlotControlsBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_8->addWidget(label_2);

        spinAxesMax = new QSpinBox(PlotControlsBox);
        spinAxesMax->setObjectName(QString::fromUtf8("spinAxesMax"));
        spinAxesMax->setMinimumSize(QSize(69, 0));
        spinAxesMax->setMaximumSize(QSize(69, 16777215));
        spinAxesMax->setMinimum(-65536);
        spinAxesMax->setMaximum(65536);
        spinAxesMax->setSingleStep(10);
        spinAxesMax->setValue(100);

        horizontalLayout_8->addWidget(spinAxesMax);


        plotControlsLayout->addLayout(horizontalLayout_8);

        pushButton_AutoScale = new QPushButton(PlotControlsBox);
        pushButton_AutoScale->setObjectName(QString::fromUtf8("pushButton_AutoScale"));
        pushButton_AutoScale->setSizeIncrement(QSize(0, 8));

        plotControlsLayout->addWidget(pushButton_AutoScale);

        listWidget_Channels = new QListWidget(PlotControlsBox);
        listWidget_Channels->setObjectName(QString::fromUtf8("listWidget_Channels"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget_Channels->sizePolicy().hasHeightForWidth());
        listWidget_Channels->setSizePolicy(sizePolicy1);
        listWidget_Channels->setMinimumSize(QSize(0, 0));
        listWidget_Channels->setMaximumSize(QSize(150, 16777215));
        listWidget_Channels->setLayoutDirection(Qt::LeftToRight);
        listWidget_Channels->setAutoScroll(false);
        listWidget_Channels->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget_Channels->setAlternatingRowColors(true);
        listWidget_Channels->setSelectionBehavior(QAbstractItemView::SelectItems);
        listWidget_Channels->setTextElideMode(Qt::ElideMiddle);
        listWidget_Channels->setResizeMode(QListView::Adjust);
        listWidget_Channels->setModelColumn(0);
        listWidget_Channels->setSelectionRectVisible(true);

        plotControlsLayout->addWidget(listWidget_Channels);

        pushButton_ResetVisible = new QPushButton(PlotControlsBox);
        pushButton_ResetVisible->setObjectName(QString::fromUtf8("pushButton_ResetVisible"));

        plotControlsLayout->addWidget(pushButton_ResetVisible);

        savePNGButton = new QPushButton(PlotControlsBox);
        savePNGButton->setObjectName(QString::fromUtf8("savePNGButton"));

        plotControlsLayout->addWidget(savePNGButton);


        gridLayout_2->addLayout(plotControlsLayout, 0, 0, 1, 1);


        controlsLayout->addWidget(PlotControlsBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        controlsLayout->addItem(verticalSpacer);

        gridGroupBox = new QGroupBox(centralWidget);
        gridGroupBox->setObjectName(QString::fromUtf8("gridGroupBox"));
        gridGroupBox->setMinimumSize(QSize(0, 80));
        TextControlsBox = new QGridLayout(gridGroupBox);
        TextControlsBox->setSpacing(6);
        TextControlsBox->setContentsMargins(11, 11, 11, 11);
        TextControlsBox->setObjectName(QString::fromUtf8("TextControlsBox"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_TextEditHide = new QPushButton(gridGroupBox);
        pushButton_TextEditHide->setObjectName(QString::fromUtf8("pushButton_TextEditHide"));
        pushButton_TextEditHide->setCheckable(true);
        pushButton_TextEditHide->setChecked(false);

        verticalLayout->addWidget(pushButton_TextEditHide);

        pushButton_ShowallData = new QPushButton(gridGroupBox);
        pushButton_ShowallData->setObjectName(QString::fromUtf8("pushButton_ShowallData"));
        pushButton_ShowallData->setCheckable(true);

        verticalLayout->addWidget(pushButton_ShowallData);


        TextControlsBox->addLayout(verticalLayout, 0, 0, 1, 1);


        controlsLayout->addWidget(gridGroupBox);


        gridLayout_3->addLayout(controlsLayout, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy2);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        splitter->setFont(font);
        splitter->setFrameShape(QFrame::NoFrame);
        splitter->setOrientation(Qt::Vertical);
        splitter->setOpaqueResize(true);
        splitter->setHandleWidth(5);
        splitter->setChildrenCollapsible(false);
        plot = new QCustomPlot(splitter);
        plot->setObjectName(QString::fromUtf8("plot"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy3);
        plot->setMinimumSize(QSize(0, 400));
        splitter->addWidget(plot);
        textEdit_UartWindow = new QTextEdit(splitter);
        textEdit_UartWindow->setObjectName(QString::fromUtf8("textEdit_UartWindow"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textEdit_UartWindow->sizePolicy().hasHeightForWidth());
        textEdit_UartWindow->setSizePolicy(sizePolicy4);
        textEdit_UartWindow->setMinimumSize(QSize(0, 150));
        splitter->addWidget(textEdit_UartWindow);

        gridLayout_4->addWidget(splitter, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 0, 1, 1, 1);

        serial_port_plotter->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(serial_port_plotter);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        serial_port_plotter->setStatusBar(statusBar);
        toolBar = new QToolBar(serial_port_plotter);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setMovable(false);
        toolBar->setAllowedAreas(Qt::TopToolBarArea);
        toolBar->setFloatable(false);
        serial_port_plotter->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionConnect);
        toolBar->addAction(actionPause_Plot);
        toolBar->addAction(actionDisconnect);
        toolBar->addSeparator();
        toolBar->addAction(actionClear);
        toolBar->addSeparator();
        toolBar->addAction(actionHow_to_use);
        toolBar->addSeparator();
        toolBar->addAction(actionRecord_stream);
        toolBar->addAction(actionExit_Window);
        toolBar->addSeparator();

        retranslateUi(serial_port_plotter);

        QMetaObject::connectSlotsByName(serial_port_plotter);
    } // setupUi

    void retranslateUi(QMainWindow *serial_port_plotter)
    {
        serial_port_plotter->setWindowTitle(QApplication::translate("serial_port_plotter", "MainWindow", nullptr));
        actionConnect->setText(QApplication::translate("serial_port_plotter", "Connect", nullptr));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("serial_port_plotter", "Connect to COM port", nullptr));
#endif // QT_NO_TOOLTIP
        actionPause_Plot->setText(QApplication::translate("serial_port_plotter", "Pause", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPause_Plot->setToolTip(QApplication::translate("serial_port_plotter", "Pause plot", nullptr));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setText(QApplication::translate("serial_port_plotter", "Disconnect", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("serial_port_plotter", "Disconnect COM port", nullptr));
#endif // QT_NO_TOOLTIP
        actionClear->setText(QApplication::translate("serial_port_plotter", "Clear", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClear->setToolTip(QApplication::translate("serial_port_plotter", "Clear plot data", nullptr));
#endif // QT_NO_TOOLTIP
        actionHow_to_use->setText(QApplication::translate("serial_port_plotter", "How to use", nullptr));
        actionRecord_stream->setText(QApplication::translate("serial_port_plotter", "Record stream", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRecord_stream->setToolTip(QApplication::translate("serial_port_plotter", "Record the incoming data to a .csv file ( shortcut : s )", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionRecord_stream->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        actionExit_Window->setText(QApplication::translate("serial_port_plotter", "Exit Window", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit_Window->setToolTip(QApplication::translate("serial_port_plotter", "Exit Window", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionExit_Window->setShortcut(QApplication::translate("serial_port_plotter", "Esc", nullptr));
#endif // QT_NO_SHORTCUT
        PortControlsBox->setTitle(QApplication::translate("serial_port_plotter", "PORT CONTROLS", nullptr));
        pushButton->setText(QApplication::translate("serial_port_plotter", "Refresh", nullptr));
        labelPort->setText(QApplication::translate("serial_port_plotter", "PORT", nullptr));
        labelBaud->setText(QApplication::translate("serial_port_plotter", "BAUD", nullptr));
        labelData->setText(QApplication::translate("serial_port_plotter", "DATA", nullptr));
        labelParity->setText(QApplication::translate("serial_port_plotter", "PARITY", nullptr));
        labelStop->setText(QApplication::translate("serial_port_plotter", "STOP", nullptr));
        PlotControlsBox->setTitle(QApplication::translate("serial_port_plotter", "PLOT CONTROLS", nullptr));
        pointsLabel->setText(QApplication::translate("serial_port_plotter", "POINTS", nullptr));
        labelYStep->setText(QApplication::translate("serial_port_plotter", "Y STEP", nullptr));
        label->setText(QApplication::translate("serial_port_plotter", "MIN", nullptr));
        label_2->setText(QApplication::translate("serial_port_plotter", "MAX", nullptr));
        pushButton_AutoScale->setText(QApplication::translate("serial_port_plotter", "AutoScale Yaxis", nullptr));
        pushButton_ResetVisible->setText(QApplication::translate("serial_port_plotter", "Reset All Visible", nullptr));
        savePNGButton->setText(QApplication::translate("serial_port_plotter", "Save PNG", nullptr));
        gridGroupBox->setTitle(QApplication::translate("serial_port_plotter", "TEXT CONTROLS", nullptr));
        pushButton_TextEditHide->setText(QApplication::translate("serial_port_plotter", "Hide TextBox", nullptr));
        pushButton_ShowallData->setText(QApplication::translate("serial_port_plotter", "Show All Incoming Data", nullptr));
        toolBar->setWindowTitle(QApplication::translate("serial_port_plotter", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serial_port_plotter: public Ui_serial_port_plotter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_PORT_PLOTTER_H
