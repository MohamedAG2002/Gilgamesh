#include "logger.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/core/event.h"

#include <string>
#include <cstdarg>
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

void log_info(log_level level, const char* msg, ...)
{
  u8 lvl_index = (u8)level;
  const char* levels[] = {"NONE", "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"};
 
  char out_msg[32000];
  va_list list; 
  va_start(list, msg);
  vsnprintf(out_msg, 32000, msg, list); 
  va_end(list);

  printf("[GILG-%s]: %s\n", levels[lvl_index], out_msg);

  if(level == FATAL)
    dispatch_event(GILG_EVENT_APP_QUIT, event_desc{});
}
//////////////////////////////////////////////////////

}
