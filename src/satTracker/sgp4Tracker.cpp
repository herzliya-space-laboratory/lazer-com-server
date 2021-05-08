#include "sgp4Tracker.h"
#include "logger.h"

void sgp4Tracker::createObserver(double lon, double lat, double alt){
    observer = new Observer(lon, lat, alt);
}

void sgp4Tracker::createTleObj(char** tle){
    
    this->tle = new Tle(tle[0], tle[1], tle[2]);
}

double sgp4Tracker::getCurrentAzimuth(){
    DateTime time = DateTime::Now();
    SGP4 sgp4(*tle);
    Eci eci = sgp4.FindPosition(time);
    CoordTopocentric topo = observer->GetLookAngle(eci);
    LAZER_COMM_LOG_INFO(time << "\n " << topo << "\n ");
    return topo.azimuth;
}

double sgp4Tracker::getCurrentElevation(){
    DateTime time = DateTime::Now();
    SGP4 sgp4(*tle);
    Eci eci = sgp4.FindPosition(time);
    CoordTopocentric topo = observer->GetLookAngle(eci);
    LAZER_COMM_LOG_INFO(time << " " << topo << " ");
    return topo.elevation;
}
