#include "logger.h"
#include "defines.h"

#include <string>
#include <cstdio>

namespace gilg {

// Logger functions 
//////////////////////////////////////////////////////
b8 init_logger(void)
{
  GILG_LOG_INFO("Logger system successfully initialized");

  return true;
}

void shutdown_logger(void)
{ 
  GILG_LOG_INFO("Logger system successfully shutdown");
}

void log_assertion(const std::string& expr, const std::string& msg, const std::string& file_name, const u16 line_num)
{
  printf("[GILG ASSERTION FAILED]: %s\n", msg.c_str());
  printf("      [EXPR]: %s\n", expr.c_str());
  printf("      [FILE]: %s\n", file_name.c_str());
  printf("      [LINE]: %i\n", line_num);
}

void log_info(log_level level, const std::string& msg, ...)
{ 
  u8 log_index = (u8)level;
  const char* levels[] = { "NONE", "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"};

  printf("[GILG-%s]: %s\n", levels[log_index], msg.c_str());
}
//////////////////////////////////////////////////////

}
