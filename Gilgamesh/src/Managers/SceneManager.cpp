#include "Gilgamesh/Managers/SceneManager.hpp"
#include "Gilgamesh/Scene/Scene2D.hpp"
#include "Gilgamesh/Events/EventFuncs.hpp"
#include "Gilgamesh/Managers/EventManager.hpp"
#include "Gilgamesh/Core/Defines.hpp"
#include "Gilgamesh/GilgPCH.hpp"

#include <string>
#include <unordered_map>

namespace gilg { // beginning of gilg
 
SceneManager::SceneManager()
{
  ListenToEvent([&](const std::string&& scnName){
    currentScene = scenes[scnName];     
  });
}

Scene2D* CreateScene(SceneManager& scnMgr, const std::string&& sceneName)
{
  Scene2D* scn = new Scene2D();
  scnMgr.scenes[sceneName] = scn;
  
  // Assign the current scene to the new created scene if the newly created 
  // scene is the first scene to be added 
  if(scnMgr.scenes.size() == 1)
    scnMgr.currentScene = scnMgr.scenes[sceneName];

  return scn;
}

Scene2D* GetScene(SceneManager& scnMgr, const std::string&& sceneName)
{
  return scnMgr.scenes[sceneName];
}

void UpdateScenes(SceneManager& scnMgr, F32 dt)
{
  UpdateScene2D(scnMgr.currentScene, dt);
}

void RenderScenes(SceneManager& scnMgr)
{
  RenderScene2D(scnMgr.currentScene);
}

void UnloadScenes(SceneManager& scnMgr)
{
  for(auto[key, value] : scnMgr.scenes)
  {
    UnloadScene2D(value);
    delete value;
  }

  scnMgr.scenes.clear();
}

} // end of gilg
