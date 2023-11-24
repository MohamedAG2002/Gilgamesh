#include "Gilgamesh/Scene/Scene2D.hpp"
#include "Gilgamesh/Scene/Entity.hpp"
#include "Gilgamesh/Components/Transform2D.hpp"
#include "Gilgamesh/Managers/EventManager.hpp"
#include "Gilgamesh/Managers/AssetManager.hpp"
#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning gilg

Scene2D::Scene2D()
{
  PushBackFont(astMgr, "assets/font/IosevkaNerdFont-Bold.ttf");
}

void UpdateScene2D(Scene2D* scn, F32 dt)
{

}

void RenderScene2D(Scene2D* scn)
{
}

void UnloadScene2D(Scene2D* scn)
{
  scn->transforms.clear();
  scn->shapes.clear();
  
  UnloadAssets(scn->astMgr);
}

Entity AddEntity(Scene2D* scn)
{
  Entity entt = util::GetRandomNumber<U64>(); 

  // Every entity should be created with a transform
  scn->transforms[entt] = Transform2D(Vec2(0.0f, 0.0f));

  return entt;
}

void RemoveEntity(Scene2D* scn, Entity entt)
{
  // Removing every instance of the entity in the scene
  RemoveComponent<Transform2D>(scn, entt);
}

} // end gilg
