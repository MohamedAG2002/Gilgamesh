#include "clock.h"
#include "core/defines.h"
#include "core/logger.h"
#include "core/window.h"

namespace gilg {

// Clock type
////////////////////////////////////////
struct clock 
{
  i32 frame_count;
  f64 last_frame, delta_time;
  f64 prev_time, current_time, fps;
};

static clock clock;
////////////////////////////////////////

// Clock functions
////////////////////////////////////////
void init_clock()
{
  GILG_LOG_INFO("Clock system was successfully initialized");
}

void update_clock()
{
  // Calculate delta time
  //////////////////////////////////////////////////
  clock.delta_time = get_time() - clock.last_frame;
  clock.last_frame = get_time();
  //////////////////////////////////////////////////
  
  // Calculate FPS
  //////////////////////////////////////////////////
  clock.frame_count++;
  clock.current_time = get_time();

  if((clock.current_time - clock.prev_time) >= 1.0f)
  {
    clock.fps = clock.frame_count;
    clock.frame_count = 0;
    clock.prev_time = clock.current_time;
  }
  //////////////////////////////////////////////////
}

f64 clock_delta_time()
{
  return clock.delta_time;
}

f64 clock_fps()
{
  return clock.fps;
}
////////////////////////////////////////

}
