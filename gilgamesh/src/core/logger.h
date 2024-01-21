#pragma once

#include "defines.h"

#include <string>

namespace gilg {

#define GILG_LOG_INFO_ENABLED  1
#define GILG_LOG_WARN_ENABLED  1

// Only enable trac and debug logging in debug builds
#if GILG_DEBUG == 1 
#define GILG_LOG_TRACE_ENABLED  1
#define GILG_LOG_DEBUG_ENABLED  1
#else 
#define GILG_LOG_TRACE_ENABLED  0
#define GILG_LOG_DEBUG_ENABLED  0
#endif

enum log_level
{
  NONE  = 0, 
  TRACE = 1, 
  DEBUG = 2, 
  INFO  = 3, 
  WARN  = 4, 
  ERROR = 5, 
  FATAL = 6, 
};

// Logger functions 
//////////////////////////////////////////////////////
b8 init_logger(void);
void shutdown_logger(void);
void log_assertion(const std::string& expr, const std::string& msg, const std::string& file_name, const u16 line_num);
void log_info(log_level level, const std::string& msg, ...);
//////////////////////////////////////////////////////

// Trace log when available
#if GILG_LOG_TRACE_ENABLED == 1
#define GILG_LOG_TRACE(msg, ...) log_info(TRACE, msg, ##__VA_ARGS__)
#else 
#define GILG_LOG_TRACE()
#endif

// Debug log when available
#if GILG_LOG_DEBUG_ENABLED == 1
#define GILG_LOG_DEBUG(msg, ...) log_info(DEBUG, msg, ##__VA_ARGS__)
#else 
#define GILG_LOG_DEBUG()
#endif

// Info log when available
#if GILG_LOG_INFO_ENABLED == 1
#define GILG_LOG_INFO(msg, ...) log_info(INFO, msg, ##__VA_ARGS__)
#else 
#define GILG_LOG_INFO()
#endif

// Warning log when available
#if GILG_LOG_WARN_ENABLED == 1
#define GILG_LOG_WARNING(msg, ...) log_info(WARN, msg, ##__VA_ARGS__)
#else 
#define GILG_LOG_WARNING()
#endif

// Error and fatal logging
#define GILG_LOG_ERROR(msg, ...) log_info(ERROR, msg, ##__VA_ARGS__)
#define GILG_LOG_FATAL(msg, ...) log_info(FATAL, msg, ##__VA_ARGS__)

}
