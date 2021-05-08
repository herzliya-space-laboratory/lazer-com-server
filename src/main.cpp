#include "logger.h"
#include "linuxSerial.h"
#include "satTracker.h"

using namespace Lazer_comm;


int main()
{
    logger::init("./logs/", "lazer-comm");
    LAZER_COMM_LOG_INFO("hello world");
    //serialComm serial = new linuxSerial(9600);
    //serial.establishConnection("/dev/ttyACM0");
    //serial.sendSerial("hello");

    satTracker tracker = satTracker();
    Observer obs = tracker.createObserver(32.222096, 34.824090, 36);
    char* tle1 = "AO-07";
    char* tle2 = "1 07530U 74089B   21126.44715632 -.00000031  00000-0  91837-4 0  9994";
    char* tle3 = "2 07530 101.8511 100.9995 0012611 102.2423  13.7053 12.53648604126706";
    Tle tle = tracker.createTleObj(tle1,tle2,tle3);

    DateTime time = tle.Epoch().AddMinutes(1);
    tracker.getAzimuth(time, obs, tle);

    
    return 0;
}