#pragma once

#include "Gilgamesh/Scene/Scene2D.hpp"
#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning of gilg
 
struct SceneManager
{
  Scene2D* currentScene = nullptr;
  std::unordered_map<std::string, Scene2D*> scenes; 

  SceneManager();
};

Scene2D* CreateScene(SceneManager& scnMgr, const std::string&& sceneName);
Scene2D* GetScene(SceneManager& scnMgr, const std::string&& sceneName);
void UpdateScenes(SceneManager& scnMgr, F32 dt);
void RenderScenes(SceneManager& scnMgr);
void UnloadScenes(SceneManager& scnMgr);

} // end of gilg
