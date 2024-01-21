#include "core/application.h"
#include "core/defines.h"
#include "core/gilg_asserts.h"
#include "core/logger.h"
#include "core/memory_alloc.h"
#include "core/window.h"
#include "core/event.h"

// Private functions
///////////////////////////////////////////////
void update_app()
{

}

void render_app()
{
}
///////////////////////////////////////////////

namespace gilg {

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
}

void destroy_app()
{
  destroy_window();
  shutdown_memory_allocater();
  shutdown_events(); 
  shutdown_logger();
}

void run_app()
{
  while(!window_closed())
  {
    update_app();
    render_app();

    update_window();
  }
}
///////////////////////////////////////////////

}
