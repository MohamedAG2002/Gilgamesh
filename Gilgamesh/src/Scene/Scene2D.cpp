#include "Gilgamesh/Scene/Scene2D.hpp"
#include "Gilgamesh/Scene/Entity.hpp"
#include "Gilgamesh/Components/Transform2D.hpp"
#include "Gilgamesh/Managers/EventManager.hpp"
#include "Gilgamesh/Managers/AssetManager.hpp"
#include "Gilgamesh/Graphics/Renderer2D.hpp"
#include "Gilgamesh/Graphics/Color.hpp"
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
  Render2DClear(scn->renderer, Color::Blue);
  Render2DBegin(scn->renderer);

  RenderRectangle(scn->renderer, Vec2(10.0f, 10.0f), Vec2(32.0f, 32.0f), Color::Black);

  Render2DEnd(scn->renderer);
}

void UnloadScene2D(Scene2D* scn)
{
  scn->transforms.clear();
  scn->shapes.clear();
  
  UnloadAssets(scn->astMgr);
  UnloadRender2D(scn->renderer);
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
