#pragma once
#include "serialComm.h"


class linuxSerial : public serialComm
{
    private:
        int datarate;
        int serialPort;

    public:
        linuxSerial(int datarate) : datarate(datarate){}

        virtual int establishConnection(char *portName) override;

        virtual int openPort(char *portName, struct termios *tty) override;

        virtual int configPort(termios *port) override;

        virtual int sendData(unsigned char *data) override;

        virtual int readData(int serialPort, char* readBuff) override;

};

