
class tracker{

    public:
        virtual void createObserver(double lon, double lat, double alt) = 0;

        virtual void createTleObj(char** tle) = 0;

        virtual double getCurrentAzimuth() = 0;

        virtual double getCurrentElevation() = 0;

};