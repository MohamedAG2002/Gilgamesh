#include <gilgamesh.h>

#include <cstdio>

struct game 
{
  int width, height;
  std::string title;

  glm::vec3 target;
  gilg::camera3d cam;
};

game init_game();
void update_game(game& game);
void render_game(game& game);
void shutdown_game(game& game);

int main()
{
  game some_game = init_game();

  while(!gilg::window_closed())
  {
    update_game(some_game);
    render_game(some_game);
  }

  shutdown_game(some_game);
}

game init_game()
{
  game game;
  game.width = 800;
  game.height = 600;
  game.title = "Gilgamesh Engine";
  
  if(!gilg::init_engine(game.width, game.height, game.title))
    printf("ERROR: failed to create engine\n");
  
  game.target = glm::vec3(0.0f, 0.0f, -3.0f);
  game.cam = gilg::create_camera3d(gilg::GILG_CAM_FREE, glm::vec3(-10.0f, 0.0f, -4.0f), &game.target, 45.0f); 

  return game;
}

void update_game(game& game)
{
  gilg::update_camera3d(game.cam);
  gilg::move_camera3d(game.cam);

  gilg::update_engine();
}

void render_game(game& game)
{
  gilg::begin_renderer(game.cam);
  gilg::clear_renderer(gilg::color(0.1f, 0.1f, 0.1f, 1.0f));

  gilg::end_renderer();
}

void shutdown_game(game& game)
{
  gilg::shutdown_engine();
}
