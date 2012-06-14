#include "mb4205.h"
#include "serialport.h"
#include <QDebug>
#include <QByteArray>
#include <QTimer>
#include <QSettings>
#include <QString>

mb4205::mb4205()
{
    _time.start();
}

void mb4205::startRead()
{
    _timer = startTimer(50);
    _time.restart();
}

void mb4205::stopRead()
{
    killTimer(_timer);
}



void mb4205::MyTimer(){
    _timerq = new QTimer(this);
    connect(_timerq,SIGNAL(timeout()),this,SLOT(timerEvent(QTimerEvent*)));

    _timerq->start(600);

}

void mb4205::timerEvent(QTimerEvent *)
{

    if (!_serialPort.isOpen())
    {

        QSettings settings("./mb4205Settings.ini", QSettings::IniFormat);
        if (!settings.contains("port"))
            settings.setValue("port","COM1");
        QString port = settings.value("port", "").toString();

        // Configure SerialPort
        //9600bps start:1 data:8 stop:1 parity check:nome
        _serialPort.setPort(port);
        _serialPort.setRate(SerialPort::Rate9600);
        _serialPort.setDataBits(SerialPort::Data8);
        _serialPort.setFlowControl(SerialPort::NoFlowControl);
        _serialPort.setParity(SerialPort::NoParity);
        _serialPort.setStopBits(SerialPort::OneStop);

        if (!_serialPort.open(QIODevice::ReadOnly)){
            qWarning() << "Error: " << _serialPort.errorString();
            //QMessageBox::warning(this,"Conexion","Error de conexion");

        }
    }

    QByteArray combuffer;
    combuffer.reserve(_serialPort.readBufferSize());


    while (_serialPort.bytesAvailable()) {
        combuffer.append(_serialPort.readAll());
    }

    int i=0;
    for(i=0; i<=combuffer.size()-8; i++)
    {
        while (combuffer[i] != (char)0xfe) i++;



        QByteArray temp = combuffer.mid(i,8);
        QByteArray temp_aux = combuffer.mid(1,5);


        if(temp[temp.size()-1] == (char)0xff)
        {


            double double_dato = ((temp_aux[0]&0xF0) > 0 ? -1 : 1) * (double)( (int)(temp_aux[0]&0x0F)*10000 +
                                                                               (int)temp_aux[1]*1000 +
                                                                               (int)temp_aux[2]*100 +
                                                                               (int)temp_aux[3]*10 +
                                                                               (int)temp_aux[4] ) / 10000;
            //qDebug() << "Datos hexadecimal" << temp_aux.toHex() << double_dato;
            emit dataRead(double_dato, _time.elapsed());
        }
    }
}
