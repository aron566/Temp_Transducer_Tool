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
    modbus_module.cpp

HEADERS += \
    Utilities_Lib/Utilities_global.h \
    Utilities_Lib/ini_parser/ini.h \
    Utilities_Lib/serial_opt/CircularQueue.h \
    Utilities_Lib/serial_opt/serial_opt.h \
    Utilities_Lib/serial_port_plotter/qcustomplot/qcustomplot.h \
    Utilities_Lib/serial_port_plotter/serial_port_plotter.hpp \
    Utilities_Lib/serial_port_plotter/serial_port_plotter_helpwindow.hpp \
    Utilities_Lib/serial_port_plotter/ui_serial_port_plotter.h \
    Utilities_Lib/serial_port_plotter/ui_serial_port_plotter_helpwindow.h \
    Utilities_Lib/utilities.h \
    mainwindow.h \
    modbus_module.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resource/Utilities.qrc \
    resource/qdarkstyle/dark/style.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# 静态库
DEFINES += UTILITIES_LIBRARY

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Utilities_Lib/ -lUtilities
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Utilities_Lib/ -lUtilitiesd
else:unix: LIBS += -L$$PWD/Utilities_Lib/ -lUtilities

INCLUDEPATH += $$PWD/Utilities_Lib
DEPENDPATH += $$PWD/Utilities_Lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Utilities_Lib/libUtilities.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Utilities_Lib/libUtilitiesd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Utilities_Lib/Utilities.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Utilities_Lib/Utilitiesd.lib
else:unix: PRE_TARGETDEPS += $$PWD/Utilities_Lib/libUtilities.a
