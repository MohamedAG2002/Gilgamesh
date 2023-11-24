#pragma once

#include "Gilgamesh/GilgPCH.hpp"

#include <GLFW/glfw3.h>

namespace gilg { // beginning of gilg

typedef GLFWwindow* Window;

// Extern variable declaration
extern Window window;

void CreateWindow(U32 width, U32 height, const std::string& title);
bool IsWindowRunning();
Vec2I GetWindowSize();
void ProcessWindowEvents();
void UnloadWindow();

} // end of gilg
