#include "core/application.h"
#include "core/defines.h"
#include "core/gilg_asserts.h"
#include "core/logger.h"
#include "core/memory_alloc.h"
#include "core/window.h"
#include "core/event.h"
#include "core/input.h"
#include "resources/resource_manager.h"

namespace gilg {

// Application type 
///////////////////////////////////////////////
struct application
{
  b8 is_running;
  renderer ren;
};

static application app;
///////////////////////////////////////////////

// Private functions
///////////////////////////////////////////////
void update_app()
{
}

void render_app()
{
  pre_renderer(app.ren);
  begin_renderer(app.ren, color(1.0f, 0.5f, 0.3f, 1.0f));

  end_renderer(app.ren);
}
///////////////////////////////////////////////

// Callbacks
///////////////////////////////////////////////
bool app_exit_callback(event_type type, event_desc desc)
{
  if(type == GILG_EVENT_WINDOW_CLOSED)
  {
    app.is_running = false;
    dispatch_event(GILG_EVENT_APP_QUIT, event_desc{}); 

    // Event was handled
    return true;
  } 

  // Event was not handled. Move one to the next event
  return false;
}
///////////////////////////////////////////////

// App functions
///////////////////////////////////////////////
void create_app(const i32 window_width, const i32 window_height, const std::string& window_title)
{
  // Logger init 
  GILG_ASSERT_MSG(init_logger() == true, "Failed to initialize logger"); 
  
  // Event system init 
  if(!init_events())
    GILG_LOG_ERROR("Failed to initialize event system");

  // Memory allocater init 
  if(!init_memory_allocater())
    GILG_LOG_FATAL("Failed to initialize memory allocater");

  // Window init 
  if(!create_window(window_width, window_height, window_title))
    GILG_LOG_FATAL("Failed to create window");

  // Input init 
  if(!init_input())
    GILG_LOG_ERROR("Failed to initialize input system");
  
  // App init
  app.is_running = true;
  app.ren = create_renderer();

  // Resource Manager init 
  if(!init_resource_manager())
    GILG_LOG_ERROR("Could not initialize resource manager");

  // Listen to events
  listen_to_event(GILG_EVENT_WINDOW_CLOSED, app_exit_callback);
}

void destroy_app()
{
  shutdown_resource_manager();

  destroy_renderer(app.ren);

  shutdown_input();

  destroy_window();

  shutdown_memory_allocater();
  shutdown_events(); 
  shutdown_logger();
}

void run_app()
{
  while(app.is_running && !window_closed())
  {
    update_app();
    render_app();

    update_window();
  }
}
///////////////////////////////////////////////

}
