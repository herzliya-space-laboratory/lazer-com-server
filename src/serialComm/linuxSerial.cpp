#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <termios.h>

#include "linuxSerial.h"
#include "logger.h"



int linuxSerial::openPort(char *portName, struct termios *tty){
    int serial_port = open(portName, O_RDWR);

    if (serialPort < 0){ LAZER_COMM_LOG_INFO("an error while open serial port"); }
    configPort(tty);
    serialPort = serial_port;
    return 1;
}


int linuxSerial::configPort(struct termios *port){
    port->c_cflag &= ~PARENB;
    port->c_cflag &= ~CSTOPB;
    port->c_cflag |= CS8;
    port->c_cflag &= ~CRTSCTS;
    port->c_cflag |= CREAD | CLOCAL;
    port->c_lflag &= ~ICANON;
    port->c_lflag &= ~ECHONL;
    port->c_lflag &= ~ISIG;
    port->c_iflag &= ~(IXON | IXOFF | IXANY);
    port->c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);
    port->c_oflag &= ~OPOST;
    port->c_oflag &= ~ONLCR;
    port->c_cc[VTIME] = 10; //wait up to 10 deciseconds until returning
    cfsetispeed(port, datarate);
    cfsetospeed(port, datarate);

    if (tcsetattr(serialPort, TCSANOW, port) != 0){
         LAZER_COMM_LOG_INFO("an error while saving termios attributes");
         return -1;
        }

    return 0; 
}

int linuxSerial::sendData(unsigned char *data){
    write(serialPort, data, sizeof(data));
    return 1;
}

int linuxSerial::readData(int serialPort, char* readBuff){
    int num_of_bytes = read(serialPort, &readBuff, sizeof(readBuff));
    return num_of_bytes;
}
 
int linuxSerial::establishConnection(char *portName){
    struct termios tty;
    if (tcgetattr(serialPort, &tty) != 0){printf("h");}
    openPort(portName, &tty);
    return 1;
}
