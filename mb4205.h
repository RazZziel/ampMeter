#ifndef MB4205_H
#define MB4205_H

#include <QObject>
#include "serialport.h"
#include "serialportinfo.h"
#include "datasource.h"
#include <QTimer>
#include <QSettings>

class mb4205 : public DataSource
{
    Q_OBJECT
public:
    mb4205();
    void startRead();
    void stopRead();



public slots:
    void timerEvent(QTimerEvent *e);

private:
    SerialPort _serialPort;
    int _timer;
    void MyTimer();
    QTimer *_timerq;

};

#endif // MB4205_H
