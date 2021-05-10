#pragma once

#include <glm/glm.hpp>

namespace LazerComm
{
    class satTracker
    {
        public:
            virtual void createObserver(double lon, double lat, double alt) = 0;

            virtual void createTleObj(char** tle) = 0;

            virtual double getCurrentAzimuth() = 0;

            virtual double getCurrentElevation() = 0;
            
            virtual glm::tvec2<double> getCurrentAzimuthAndElevation() = 0;
    };
}