#include "core/event.h"
#include "core/logger.h"

#include <unordered_map>
#include <vector>

namespace gilg {

// Globals
//////////////////////////////////////////////
static std::unordered_map<event_type, std::vector<event_func>> events_poll;
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

  for(auto& [key, value] : events_poll)
    value.clear();
  
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
