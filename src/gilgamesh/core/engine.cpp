#include "engine.h"
#include "core/defines.h"
#include "core/gilg_asserts.h"
#include "core/logger.h"
#include "core/memory_alloc.h"
#include "core/window.h"
#include "core/event.h"
#include "core/input.h"
#include "core/clock.h"
#include "graphics/renderer.h"

#include "resources/resource_manager.h"

namespace gilg {

// Callbacks
///////////////////////////////////////////////
bool app_exit_callback(event_type type, event_desc desc)
{
  if(type == GILG_EVENT_WINDOW_CLOSED)
  {
    dispatch_event(GILG_EVENT_APP_QUIT, event_desc{}); 

    // Event was handled
    return true;
  } 

  // Event was not handled. Move one to the next event
  return false;
}
///////////////////////////////////////////////

// Engine functions
//////////////////////////////////////////
b8 init_engine(const i32 width, const i32 height, const std::string& title)
{
  // Logger init 
  GILG_ASSERT_MSG(init_logger() == true, "Failed to initialize logger"); 
  
  // Event system init 
  if(!init_events())
  {
    GILG_LOG_ERROR("Failed to initialize event system");
    return false;
  }

  // Memory allocater init 
  if(!init_memory_allocater())
  {
    GILG_LOG_FATAL("Failed to initialize memory allocater");
    return false;
  }

  // Window init 
  if(!create_window(width, height, title))
  {
    GILG_LOG_FATAL("Failed to create window");
    return false;
  }
  disable_cursor();

  // Clock init 
  init_clock();

  // Input init 
  if(!init_input())
  {
    GILG_LOG_ERROR("Failed to initialize input system");
    return false;
  }
  
  // Resource Manager init 
  if(!init_resource_manager())
  {
    GILG_LOG_ERROR("Could not initialize resource manager");
    return false;
  }

  // Renderer init 
  if(!create_renderer())
  {
    GILG_LOG_ERROR("Could not create a renderer");
    return false; 
  }
  
  // Listen to events
  listen_to_event(GILG_EVENT_WINDOW_CLOSED, app_exit_callback);
  
  GILG_LOG_INFO("Engine was successfully intialized");
  return true;
}

void shutdown_engine()
{
  shutdown_resource_manager();

  destroy_renderer();

  shutdown_input();

  destroy_window();

  shutdown_memory_allocater();
  shutdown_events(); 
  shutdown_logger();
}

void update_engine()
{
  update_clock();
  update_window();  
}
//////////////////////////////////////////

}
