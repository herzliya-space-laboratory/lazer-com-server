#pragma once
#include "serialComm.h"


class linuxSerial : serialComm{
    private:
        int datarate;
        int serialPort;

    public:
        linuxSerial(int datarate) : datarate(datarate){}

        int establishConnection(char *portName);

        int openPort(char *portName, struct termios *tty);

        int configPort(struct termios *port);

        int sendData(unsigned char *data);

        int readData(int serialPort, char* readBuff);

};

