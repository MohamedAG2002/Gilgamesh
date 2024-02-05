#include "engine.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/core/gilg_asserts.h"
#include "gilgamesh/core/logger.h"
#include "gilgamesh/core/memory_alloc.h"
#include "gilgamesh/core/window.h"
#include "gilgamesh/core/event.h"
#include "gilgamesh/core/input.h"
#include "gilgamesh/core/clock.h"
#include "gilgamesh/graphics/renderer.h"
#include "gilgamesh/graphics/renderer2d.h"

#include "gilgamesh/resources/resource_manager.h"

namespace gilg {

// Globals
///////////////////////////////////////////////
static app_desc s_app;
///////////////////////////////////////////////

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
b8 init_engine(const app_desc& app)
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
  if(!create_window(app.width, app.height, app.title))
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

  // Renderer2D init 
  if(!create_renderer2d())
  {
    GILG_LOG_FATAL("Failed to create Renderer2D");
    return false;
  }
  
  // Listen to events
  listen_to_event(GILG_EVENT_WINDOW_CLOSED, app_exit_callback);
 
  // Making sure all of the required functions are given
  GILG_ASSERT_MSG(app.init_func, "Application init function was not supplied");
  GILG_ASSERT_MSG(app.update_func, "Application update function was not supplied");
  GILG_ASSERT_MSG(app.render_func, "Application render function was not supplied");
  GILG_ASSERT_MSG(app.shutdown_func, "Application shutdown function was not supplied");
  
  // App init 
  s_app = app; 
  s_app.init_func();
  
  GILG_LOG_INFO("Engine was successfully intialized");
  return true;
}

void shutdown_engine()
{
  // App shutdown 
  /////////////////////////////
  s_app.shutdown_func(); 
  /////////////////////////////

  // Engine systems shutdown 
  /////////////////////////////
  shutdown_resource_manager();

  destroy_renderer2d();
  destroy_renderer();

  shutdown_input();

  destroy_window();

  shutdown_memory_allocater();
  shutdown_events(); 
  shutdown_logger();
  /////////////////////////////
}

void run_engine()
{
  while(!window_closed()) 
  {
    s_app.render_func();

    update_clock();

    s_app.update_func();
    
    update_input(); 
    update_window();
  }
}
//////////////////////////////////////////

}
