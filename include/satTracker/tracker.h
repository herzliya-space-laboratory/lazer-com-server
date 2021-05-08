#include <CoordTopocentric.h>
#include <CoordGeodetic.h>
#include <Observer.h>
#include <SGP4.h>

class tracker{

    public:
        virtual double getAzimuth(DateTime time, Observer obs, Tle tle) = 0;

        virtual double getElevation(DateTime time, Observer obs, Tle tle) = 0;

        virtual Observer createObserver(double lon, double lat, double alt) = 0;

        virtual Tle createTleObj(char* tle1, char* tle2, char* tle3) = 0;
};