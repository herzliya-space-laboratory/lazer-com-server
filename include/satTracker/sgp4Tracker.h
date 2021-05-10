#pragma once

#include <CoordTopocentric.h>
#include <CoordGeodetic.h>
#include <Observer.h>
#include <SGP4.h>
#include <glm/glm.hpp>

#include "satTracker.h"

namespace LazerComm
{
    class sgp4Tracker : public satTracker{
        private:
            Observer *observer;
            Tle *tle;
        public:
            virtual void createObserver(double lon, double lat, double alt) override;

            virtual void createTleObj(char** tle) override;

            virtual double getCurrentAzimuth() override;

            virtual double getCurrentElevation() override;
            virtual glm::tvec2<double> getCurrentAzimuthAndElevation() override;
 
    };
}
