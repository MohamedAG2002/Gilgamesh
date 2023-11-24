#include "Gilgamesh/Gilgamesh.hpp"

int main()
{
  gilg::Application app(800, 600, "Testbed");
  gilg::RunApp(app);
  gilg::UnloadApp(app);
}
