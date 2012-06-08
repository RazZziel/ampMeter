#-------------------------------------------------
#
# Project created by QtCreator 2012-02-11T21:04:26
#
#-------------------------------------------------

QT       += core gui qwt
QT += qwt
TARGET = ampMeter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ampplot.cpp \
    randomdata.cpp \
    constantdata.cpp \
    mb4205.cpp

HEADERS  += mainwindow.h \
    ampplot.h \
    datasource.h \
    randomdata.h \
    constantdata.h \
    mb4205.h \
    serialportinfo.h \
    serialport.h

FORMS    += mainwindow.ui



win32 {

    LIBS += -LC:/Users/a/dev/qwt-build-Release/lib/
    LIBS += -lqwt
    LIBS += -LC:/Users/a/dev/serialport-build-Release/src/release
    LIBS += -lSerialPort

    #LIBS += -L/C:/Users/a/dev/ampMeter/lib/win32/ -lqserialdevice

    #LIBS += -LC:/Users/a/dev/ampMeter/lib/win32/SerialPort.a
    #LIBS += -L/C:/Users/a/dev/ampMeter/lib/win32 -lSerialPort

    INCLUDEPATH += C:/Users/a/dev/ampMeter
    INCLUDEPATH += C:/Users/a/dev/Qwt-6.0.1/src
    INCLUDEPATH += C:/Users/a/dev/Qwt-6.0.1/include
    INCLUDEPATH += C:/Users/a/dev/serialport/src
    INCLUDEPATH += C:/Users/a/dev/serialport/include

    DEFINES  = _TTY_WIN_

}

unix {

    LIBS    +=  -lqwt
    LIBS += -L/home/imasdetres/dev/ampMeter
    LIBS += -lSerialPort

    INCLUDEPATH += /usr/include/qwt
    INCLUDEPATH += /home/imasdetres/dev/ampMeter

    QMAKE_LFLAGS += -Wl,-rpath,\\$\$ORIGIN/lib/:\\$\$ORIGIN/../lib/

    DEFINES   = _TTY_POSIX_

}
