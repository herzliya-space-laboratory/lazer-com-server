#include "closeLoop.h"
#include <stdlib.h>

namespace LazerComm
{
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
            serialManger->establishConnection("")
        }  

        void closeLoop::setTracker(satTracker *Tracker)
        {
            tracker = Tracker;
        }

        void closeLoop::closeLoop::run()
        {
            while (true)
            {

            }
        }

        

        void closeLoop::close()
        {
            free(serialManger);
            free(tracker);
        }

    
}