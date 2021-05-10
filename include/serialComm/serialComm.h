
namespace LazerComm
{
    class serialComm
    {
        public:
            virtual int establishConnection(char *portName) = 0;

            virtual int sendData(unsigned char *data) = 0;
            
            virtual int readData(int serialPort, char* readBuff) = 0;
    };
}

