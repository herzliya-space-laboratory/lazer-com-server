class serialComm{
    private:
        virtual int configPort()=0;

        virtual int openPort()=0;

    public:
        virtual int establishConnection()=0;

        virtual int sendData()=0;
        
        virtual int readData()=0;

        
};

