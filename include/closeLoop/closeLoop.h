#include "satTracker.h"
#include "serialComm.h"


namespace LazerComm
{
    class closeLoop
    {
        private:
            static satTracker *tracker;
            static serialComm *serialManger;

        public:
            static void init(satTracker *tracker, serialComm *serialManger);
            static void setSerialManger(serialComm *serialManger);
            static void setTracker(satTracker *tracker);
            static void run();
            static void close();
    };
    
}