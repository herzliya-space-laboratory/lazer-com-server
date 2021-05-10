#pragma once

namespace LazerComm
{
    class serialComm
    {
        public:
            virtual int establishConnection() = 0;

            virtual int sendData(unsigned char *data, int size) = 0;
            
            virtual int readData(unsigned char* readBuff, int size) = 0;
    };
}

