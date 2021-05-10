#include "closeLoop.h"
#include <stdlib.h>
#include <glm/glm.hpp>
#include "logger.h"

namespace LazerComm
{
    union AzimuthAndElevation
    {
        glm::tvec2<double> AzAndEl;

        struct {
            double azimuth;
            double elevation;
        };

        unsigned char buffer[2 *sizeof(double)];
    };
    
    satTracker *closeLoop::tracker;
    serialComm *closeLoop::serialManger;

    void closeLoop::init(satTracker *Tracker, serialComm *SerialManger)
    {
        tracker = Tracker;
        serialManger = SerialManger;
    }

    void closeLoop::setSerialManger(serialComm *SerialManger)
    {
        serialManger = SerialManger;
    }  

    void closeLoop::setTracker(satTracker *Tracker)
    {
        tracker = Tracker;
    }

    void closeLoop::run()
    {
        AzimuthAndElevation serialAzimuthAndElevation;
        AzimuthAndElevation satAzimuthAndElevation;
        AzimuthAndElevation deltaAzimuthAndElevation;
        while (true)
        {
            serialManger->readData(serialAzimuthAndElevation.buffer, 2 * sizeof(double));

            satAzimuthAndElevation.AzAndEl = tracker->getCurrentAzimuthAndElevation();


            deltaAzimuthAndElevation.AzAndEl = satAzimuthAndElevation.AzAndEl - serialAzimuthAndElevation.AzAndEl;

            serialManger->sendData(deltaAzimuthAndElevation.buffer, 2 * sizeof(double));
        }
    }

    

    void closeLoop::close()
    {
        free(serialManger);
        free(tracker);
    }    
}