#include "satTracker.h"

Observer satTracker::createObserver(double lon, double lat, double alt){
    Observer obs = Observer(lon, lat, alt);
    return obs; 
}

Tle satTracker::createTleObj(char* tle1, char* tle2, char* tle3){
    Tle tle = Tle(tle1, tle2, tle3);
    return tle;
}

double satTracker::getAzimuth(DateTime time, Observer obs, Tle tle){
    SGP4 sgp4(tle);
    Eci eci = sgp4.FindPosition(time);
    CoordTopocentric topo = obs.GetLookAngle(eci);
    CoordGeodetic geo = eci.ToGeodetic();
    std::cout << time << " " << topo << " " << geo << std::endl;
}

double satTracker::getElevation(DateTime time, Observer obs, Tle tle){
    printf("hello");
}
