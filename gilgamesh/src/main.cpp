#include "core/application.h"

int main(void)
{
  gilg::create_app(800, 600, "Gilgamesh Engine");
  gilg::run_app();
  gilg::destroy_app();

  return 0;
}
