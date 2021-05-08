#include <CoordTopocentric.h>
#include <CoordGeodetic.h>
#include <Observer.h>
#include <SGP4.h>
#include "tracker.h"


class sgp4Tracker : public tracker{
    private:
        Observer *observer;
        Tle *tle;
    public:
        virtual void createObserver(double lon, double lat, double alt) override;

        virtual void createTleObj(char** tle) override;

        virtual double getCurrentAzimuth() override;

        virtual double getCurrentElevation() override;
};

