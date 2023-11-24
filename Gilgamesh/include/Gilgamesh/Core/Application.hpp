#pragma once

#include "Gilgamesh/GilgPCH.hpp"
#include "Gilgamesh/Managers/SceneManager.hpp"

namespace gilg { // beginning of gilg
struct Application 
{
  bool isRunning;
  F32 lastFrame, deltaTime;
  SceneManager scnMgr;

  Application(U32 width, U32 height, const std::string&& title);
};

void InitAppWindow(Application& app, int width, int height, const std::string& title);
void ProcessAppEvents(Application& app);
void UpdateApp(Application& app);
void RenderApp(Application& app);
void RunApp(Application& app);
void UnloadApp(Application& app);

} // end of gilg