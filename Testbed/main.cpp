#include "Gilgamesh/Gilgamesh.hpp"

int main()
{
  // Init stage
  gilg::Application app(800, 600, "Testbed");

  // Update/Render stage
  gilg::RunApp(app);

  // Shutdown stage
  gilg::UnloadApp(app);
}
