#include "logger.h"

using namespace Lazer_comm;


int main()
{

    logger::init("./logs/", "lazer-comm");
    LAZER_COMM_LOG_INFO("hello world");
    return 0;
}