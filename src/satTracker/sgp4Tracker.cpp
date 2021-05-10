#include "sgp4Tracker.h"
#include "logger.h"

#include <glm/glm.hpp>

namespace LazerComm
{
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
        return topo.azimuth;
    }

    double sgp4Tracker::getCurrentElevation(){
        DateTime time = DateTime::Now();
        SGP4 sgp4(*tle);
        Eci eci = sgp4.FindPosition(time);
        CoordTopocentric topo = observer->GetLookAngle(eci);
        return topo.elevation;
    }

    glm::tvec2<double> sgp4Tracker::getCurrentAzimuthAndElevation(){
        DateTime time = DateTime::Now();
        SGP4 sgp4(*tle);
        Eci eci = sgp4.FindPosition(time);
        CoordTopocentric topo = observer->GetLookAngle(eci);
        return glm::tvec2<double>(topo.azimuth, topo.elevation);
    }
}