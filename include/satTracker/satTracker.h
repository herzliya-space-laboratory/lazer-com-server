#include <CoordTopocentric.h>
#include <CoordGeodetic.h>
#include <Observer.h>
#include <SGP4.h>

#include "tracker.h"


class satTracker : tracker{
    public:

        Observer createObserver(double lon, double lat, double alt);

        Tle createTleObj(char* tle1, char* tle2, char* tle3);

        double getAzimuth(DateTime time, Observer obs, Tle tle);

        double getElevation(DateTime time, Observer obs, Tle tle);
};

