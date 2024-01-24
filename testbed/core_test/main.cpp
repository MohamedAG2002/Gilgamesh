#include <core/application.h>

int main()
{
  gilg::create_app(800, 600, "Core Test");
  gilg::run_app();
  gilg::destroy_app();
}
