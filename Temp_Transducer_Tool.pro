QT       += core gui
QT       += printsupport
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    modbus_mode.cpp

HEADERS += \
    mainwindow.h \
    modbus_mode.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix|win32: LIBS += -L$$PWD/Utilities_Lib/ -lUtilities

INCLUDEPATH += $$PWD/Utilities_Lib \
            $$PWD/Utilities_Lib/serial_port_plotter \
            $$PWD/Utilities_Lib/serial_opt \
            $$PWD/Utilities_Lib/ini_parser

DEPENDPATH += $$PWD/Utilities_Lib
