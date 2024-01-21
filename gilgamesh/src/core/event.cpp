#include "core/event.h"
#include "core/logger.h"

#include <vector>

namespace gilg {

// Globals
//////////////////////////////////////////////
static std::vector<std::vector<event_func>> events_poll;
//////////////////////////////////////////////

// Event functions
//////////////////////////////////////////////
bool init_events()
{
  GILG_LOG_INFO("Event system successfully initialized");

  return true;
}

void shutdown_events()
{
  GILG_LOG_INFO("Event system successfully initialized");

  for(auto& pool : events_poll)
    pool.clear();
  
  events_poll.clear();
}

void listen_to_event(event_type type, event_func func)
{
  events_poll[type].push_back(func);
}

bool dispatch_event(event_type type, event_desc desc)
{
  for(auto& event : events_poll[type])
  {
    if(event(type, desc))
      return true;
  }

  return false;
}
////////////////////////////////////////////// 

}
