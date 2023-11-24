#pragma once

#include "Entity.hpp"
#include "Gilgamesh/GilgPCH.hpp"
#include "Gilgamesh/Components/Transform2D.hpp"
#include "Gilgamesh/Components/Components.hpp"
#include "Gilgamesh/Managers/EventManager.hpp"
#include "Gilgamesh/Managers/AssetManager.hpp"
#include "Gilgamesh/Graphics/Renderer2D.hpp"

#include <utility>

namespace gilg { // beginning gilg

struct Scene2D 
{
  // Members
  AssetManager astMgr;
  Renderer2D renderer;

  // CTOR
  Scene2D();

  // Components
  std::unordered_map<Entity, Transform2D> transforms;  
  std::unordered_map<Entity, Shape2D> shapes;  
};

// Scene functions
void UpdateScene2D(Scene2D* scn, F32 dt);
void RenderScene2D(Scene2D* scn);
void UnloadScene2D(Scene2D* scn);

// Entity functions
Entity AddEntity(Scene2D* scn);
void RemoveEntity(Scene2D* scn, Entity entt);

// Component functions
template<typename Comp>
bool HasComponent(Scene2D* scn, Entity entt)
{
  if constexpr (std::is_same<Comp, Transform2D>::value) 
    return scn->transforms.find(entt) != nullptr;
  else if constexpr (std::is_same<Comp, Shape2D>::value) 
    return scn->shapes.find(entt) != nullptr;
      
  return false;
}

template<typename Comp, typename ...Args>
void AddComponent(Scene2D* scn, Entity entt, Args** ...args)
{
  GILG_ASSERT_MSG(!HasComponent<Comp>(scn, entt), "Failed to add component as Entity already has it");

  if constexpr (std::is_same<Comp, Transform2D>::value) 
    scn->transforms[entt] = Transform2D(std::forward<Args>(args)...); 
  else if constexpr (std::is_same<Comp, Shape2D>::value) 
    scn->shapes[entt] = Shape2D(std::forward<Args>(args)...); 
}

template<typename Comp>
void RemoveComponent(Scene2D* scn, Entity entt)
{
  GILG_ASSERT_MSG(!HasComponent<Comp>(scn, entt), "Failed to remove component as Entity does not have it");
  
  if constexpr (std::is_same<Comp, Transform2D>::value) 
    scn->transforms.erase(entt);
  else if constexpr (std::is_same<Comp, Shape2D>::value) 
    scn->shapes.erase(entt);
}

template<typename Comp>
Comp GetComponent(Scene2D* scn, Entity entt)
{
  GILG_ASSERT_MSG(!HasComponent<Comp>(scn, entt), "Failed to retrieve component as Entity does not have it");
  
  if constexpr (std::is_same<Comp, Transform2D>::value) 
    return scn->transforms[entt];
  else if constexpr (std::is_same<Comp, Shape2D>::value) 
    return scn->shapes[entt];
  
  return Comp{};
}

} // end gilg
