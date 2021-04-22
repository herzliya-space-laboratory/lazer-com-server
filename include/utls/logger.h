#pragma once

#include <glog/logging.h>
#include <string>

#define LAZER_COMM_LOG_INFO(toLog) LOG(INFO) << toLog;
#define LAZER_COMM_LOG_WARNING(toLog) LOG(WARNING) << toLog;
#define LAZER_COMM_LOG_ERROR(toLog) LOG(ERROR) << toLog;
#define LAZER_COMM_LOG_FATAL(toLog) LOG(FATAL) << toLog;
#define LAZER_COMM_CONDTION_LOG_INFO(toLog, condition) LOG_IF(INFO, condition) << toLog;
#define LAZER_COMM_CONDTION_LOG_WARNING(toLog, condition) LOG_IF(WARNING, condition) << toLog;
#define LAZER_COMM_CONDTION_LOG_ERROR(toLog, condition) LOG_IF(ERROR, condition) << toLog;
#define LAZER_COMM_CONDTION_LOG_FATAL(toLog, condition) LOG_IF(FATAL, condition) << toLog;


namespace Lazer_comm
{
    class logger
    {
        public:
            static void init(const std::string& pathToLogs, const std::string& projectName);
            static void close();
    };

}

