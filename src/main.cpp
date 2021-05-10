#include "logger.h"
#include "linuxSerial.h"
#include "sgp4Tracker.h"
    #include <chrono>

using namespace LazerComm;


int main()
{
    logger::init("./logs/", "lazer-comm");
        
    satTracker *tracker = new sgp4Tracker();
    tracker->createObserver(32.222096, 34.824090, 36);
    char *tle[3] = 
    {
        (char*)"AO-07",
        (char*)"1 07530U 74089B   21126.44715632 -.00000031  00000-0  91837-4 0  9994",
        (char*)"2 07530 101.8511 100.9995 0012611 102.2423  13.7053 12.53648604126706"
    };

    tracker->createTleObj(tle);

    double az = tracker->getCurrentAzimuth();
    double el = tracker->getCurrentElevation();

    LazerComm_LOG_INFO("az: " << az << ", el: " << el);
    return 0;
}