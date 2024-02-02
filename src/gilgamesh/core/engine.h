#pragma once

#include "gilgamesh/core/defines.h"

#include <string>

namespace gilg {

// App function pointers
//////////////////////////////////////////
typedef void(*app_init)(void);
typedef void(*app_update)(void);
typedef void(*app_render)(void);
typedef void(*app_shutdown)(void);
//////////////////////////////////////////

// App Description struct
//////////////////////////////////////////
struct app_desc 
{
  i32 width, height; 
  std::string title; 

  app_init init_func;
  app_update update_func;
  app_render render_func;
  app_shutdown shutdown_func;
};
//////////////////////////////////////////

// Engine functions
//////////////////////////////////////////
b8 init_engine(const app_desc& app);
void shutdown_engine();
void run_engine();
//////////////////////////////////////////

}
