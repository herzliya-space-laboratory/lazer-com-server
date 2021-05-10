#pragma once
#include "serialComm.h"
#include <termios.h>

namespace LazerComm
{
    class linuxSerial : public serialComm
    {
        private:
            int datarate;
            int serialPort;
            char* portName;
            termios port;
            
            int configPort();
        public:
            linuxSerial(int datarate, char* portName) : datarate(datarate), portName(portName) { }

            virtual int establishConnection() override;


            virtual int sendData(unsigned char *data, int size) override;

            virtual int readData(unsigned char* readBuff, int size) override;

    };
}

