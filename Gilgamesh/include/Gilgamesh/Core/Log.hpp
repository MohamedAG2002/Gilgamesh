#pragma once

#include "Defines.hpp"

namespace gilg { // beginning of gilg

#define GILG_LOG_WARNING_EABLED 1
#define GILG_LOG_INFO_ENABLED   1

// Only enable trace and debug logging on debug builds
#if GILG_RELEASE == 1
#define GILG_LOG_DEBUG_ENABLED 0
#define GILG_LOG_TRACE_ENABLED 0
#else 
#define GILG_LOG_DEBUG_ENABLED 1
#define GILG_LOG_TRACE_ENABLED 1
#endif

enum class LogLevel 
{
  NONE    = 0,
  TRACE   = 1,
  DEBUG   = 2,
  INFO    = 3,
  WARNING = 4,
  ERROR   = 5,
  FATAL   = 6
};

bool InitLogger();
void UnloadLogger();
void LogAssertion(const String& expr, const String& msg, const String& fileName, U16 line);
void LogInfo(LogLevel level, const char* msg, ...);

// Trace log when available
#if GILG_LOG_TRACE_ENABLED == 1
#define GILG_LOG_TRACE(msg, ...) LogInfo(LogLevel::TRACE, msg, ##__VA_ARGS__)
#else 
#define GILG_LOG_TRACE()
#endif

// Debug log when available
#if GILG_LOG_DEBUG_ENABLED == 1
#define GILG_LOG_DEBUG(msg, ...) LogInfo(LogLevel::DEBUG, msg, ##__VA_ARGS__)
#else 
#define GILG_LOG_DEBUG()
#endif

// Info log when available
#if GILG_LOG_INFO_ENABLED == 1
#define GILG_LOG_INFO(msg, ...) LogInfo(LogLevel::INFO, msg, ##__VA_ARGS__)
#else 
#define GILG_LOG_INFO()
#endif

// Warning log when available
#if GILG_LOG_WARNING_EABLED == 1
#define GILG_LOG_WARNING(msg, ...) LogInfo(LogLevel::WARNING, msg, ##__VA_ARGS__)
#else 
#define GILG_LOG_WARNING()
#endif

// Error and fatal logging
#define GILG_LOG_ERROR(msg, ...) LogInfo(LogLevel::ERROR, msg, ##__VA_ARGS__)
#define GILG_LOG_FATAL(msg, ...) LogInfo(LogLevel::FATAL, msg, ##__VA_ARGS__)

} // end of gilg
