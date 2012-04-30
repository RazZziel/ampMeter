#-------------------------------------------------
#
# Project created by QtCreator 2012-02-11T21:04:26
#
#-------------------------------------------------

QT       += core gui qwt

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
    mb4205.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/include/qwt
LIBS    +=  -lqwt



LIBS += -L/home/imasdetres/dev/ampMeter
LIBS += -lSerialPort
#LIBS += -lqserialdevice
#LIBS += -lserialportinfo


INCLUDEPATH += /home/imasdetres/dev/ampMeter

DEFINES   = _TTY_POSIX_
