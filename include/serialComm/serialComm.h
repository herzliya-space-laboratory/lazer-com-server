class serialComm{
    public:
        virtual int establishConnection()=0;

        virtual int openPort()=0;
        
        virtual int sendData()=0;
        
        virtual int readData()=0;


        virtual int configPort()=0;
};

