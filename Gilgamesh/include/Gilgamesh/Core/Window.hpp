#pragma once

#include "Gilgamesh/GilgPCH.hpp"

#include <GLFW/glfw3.h>

namespace gilg { // beginning of gilg

typedef GLFWwindow* Window;

Window CreateWindow(U32 width, U32 height, const String& title);
bool IsWindowRunning(Window window);
void UnloadWindow(Window window);

GILG_API Vec2I GetWindowSize(Window window);

} // end of gilg
