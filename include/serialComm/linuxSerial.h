#pragma once
#include "serialComm.h"

namespace LazerComm
{
    class linuxSerial : public serialComm
    {
        private:
            int datarate;
            int serialPort;
            char* portName;
            termios* port;
            
            int openPort(char *portName, struct termios *tty);
            int configPort(termios *port);
        public:
            linuxSerial(int datarate, char* portName) : datarate(datarate), portName(portName) {}

            virtual int establishConnection(char *portName) override;


            virtual int sendData(unsigned char *data) override;

            virtual int readData(char* readBuff) override;

    };
}

