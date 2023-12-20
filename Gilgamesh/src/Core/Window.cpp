#include "Gilgamesh/Core/Window.hpp"
#include "Gilgamesh/GilgPCH.hpp"

#include <GLFW/glfw3.h>

namespace gilg { // beginning of gilg

Window CreateWindow(U32 width, U32 height, const String& title)
{
  glfwInit();
  
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  Window window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr); 
  GILG_ASSERT_MSG(window != nullptr, "Failed to create window");
 
  return window;
}

bool IsWindowRunning(Window window)
{
  return !glfwWindowShouldClose(window);
}

void UnloadWindow(Window window)
{
  glfwDestroyWindow(window);
  glfwTerminate();
}

Vec2I GetWindowSize(Window window)
{
  Vec2I size;
  
  glfwGetWindowSize(window, &size.x, &size.y);

  return size;
}

} // end of gilg
