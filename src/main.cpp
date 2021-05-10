#include "logger.h"
#include "serialComm.h"
#include "linuxSerial.h"

#include "satTracker.h"
#include "sgp4Tracker.h"

#include "closeLoop.h"
using namespace LazerComm;


int main()
{
    logger::init("./logs/", "lazer-comm");
    serialComm *ardunoSerial = new linuxSerial(9600, (char *)"/dev/ttyACM0"); 
    satTracker *tracker = new sgp4Tracker();

    ardunoSerial->establishConnection();
    tracker->createObserver(32.222096, 34.824090, 36);
    char *tle[3] = 
    {
        (char*)"AO-07",
        (char*)"1 07530U 74089B   21126.44715632 -.00000031  00000-0  91837-4 0  9994",
        (char*)"2 07530 101.8511 100.9995 0012611 102.2423  13.7053 12.53648604126706"
    };

    tracker->createTleObj(tle);

    closeLoop::init(tracker, ardunoSerial);
    closeLoop::run();
    closeLoop::close();

    return 0;
}