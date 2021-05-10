#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <termios.h>

#include "linuxSerial.h"
#include "logger.h"



namespace LazerComm
{
    int linuxSerial::configPort()
    {
        port.c_cflag &= ~PARENB;
        port.c_cflag &= ~CSTOPB;
        port.c_cflag |= CS8;
        port.c_cflag &= ~CRTSCTS;
        port.c_cflag |= CREAD | CLOCAL;
        port.c_lflag &= ~ICANON;
        port.c_lflag &= ~ECHONL;
        port.c_lflag &= ~ISIG;
        port.c_iflag &= ~(IXON | IXOFF | IXANY);
        port.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);
        port.c_oflag &= ~OPOST;
        port.c_oflag &= ~ONLCR;
        port.c_cc[VTIME] = 10; //wait up to 10 deciseconds until returning
        cfsetispeed(&port, datarate);
        cfsetospeed(&port, datarate);

        if (tcsetattr(serialPort, TCSANOW, &port) != 0)
        {
            LazerComm_LOG_ERROR("an error while saving termios attributes");
            return -1;
        }

        return 0; 
        
    }

    int linuxSerial::sendData(unsigned char *data, int size)
    {
        write(serialPort, data, size);
        return 1;
    }

    int linuxSerial::readData(unsigned char* readBuff, int size)
    {
        int num_of_bytes = read(serialPort, &readBuff, size);
        return num_of_bytes;
    }
    
    int linuxSerial::establishConnection()
    {
        serialPort = open(portName, O_RDWR);

        LazerComm_CONDTION_LOG_ERROR("an error while open serial port", serialPort < 0);
        LazerComm_CONDTION_LOG_ERROR("error with tcgetattr" + std::to_string(errno), tcgetattr(serialPort, &port) != 0);

        configPort();
        return 0;
    }
}