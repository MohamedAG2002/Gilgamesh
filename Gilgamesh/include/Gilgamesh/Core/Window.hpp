#pragma once

#include "Gilgamesh/GilgPCH.hpp"

#include <GLFW/glfw3.h>

namespace gilg { // beginning of gilg

typedef GLFWwindow* Window;

Window CreateWindow(U32 width, U32 height, const std::string& title);
bool IsWindowRunning(Window window);
Vec2I GetWindowSize(Window window);
void ProcessWindowEvents();
void UnloadWindow(Window window);

} // end of gilg
