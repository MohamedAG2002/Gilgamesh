#include "game.h"

int main()
{
  gilg::app_desc app = {
    .width  = 800, 
    .height = 600,
    .title  = "Gilgamesh",

    .init_func       = init_game, 
    .update_func     = update_game, 
    .render_func     = render_game, 
    .shutdown_func   = shutdown_game,
  };
  
  if(!gilg::init_engine(app))
    printf("ERROR: failed to create engine\n");

  gilg::run_engine();
  gilg::shutdown_engine();
}
