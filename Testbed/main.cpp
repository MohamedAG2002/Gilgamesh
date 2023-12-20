#include "Gilgamesh/Gilgamesh.hpp"

int main()
{
  // Init stage
  gilg::InitApp(800, 600, "Testbed");

  // Frame stage
  gilg::RunApp();

  // Shutdown stage
  gilg::UnloadApp();
}
