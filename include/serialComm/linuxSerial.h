#pragma once
#include "serialComm.h"

namespace LazerComm
{
    class linuxSerial : public serialComm
    {
        private:
            int datarate;
            int serialPort;
            
            int openPort(char *portName, struct termios *tty);
            int configPort(termios *port);
        public:
            linuxSerial(int datarate) : datarate(datarate){}

            virtual int establishConnection(char *portName) override;


            virtual int sendData(unsigned char *data) override;

            virtual int readData(int serialPort, char* readBuff) override;

    };
}

