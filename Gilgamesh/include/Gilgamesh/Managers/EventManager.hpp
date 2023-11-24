#pragma once

#include "Gilgamesh/Events/EventFuncs.hpp"
#include "Gilgamesh/GilgPCH.hpp"

#include <algorithm>
#include <type_traits>

namespace gilg { // beginning gilg

struct EventManager
{
  std::vector<OnSceneChange> sceneEvents;
};

// Extern variable declaration
extern EventManager evntMgr;

/* EventDispatcher functions */
///////////////////////////////////////////////////////////////
// Add and assign the new event(of the same type) the function pointer given
template<typename T>
void ListenToEvent(T&& func)
{
  // Deduce the type of the template T given in compile time
  if constexpr (std::is_same<T, OnSceneChange>::value)
    evntMgr.sceneEvents.push_back(static_cast<OnSceneChange>(func));
}

// Fire/call all events of the same function type, passing in the given parametars
template<typename T, typename... Args>
void DispatchEvent(Args&&... args)
{
  auto call_fn = [&](const T& fn) {
    if(fn)
      fn(std::forward<Args>(args)...);
  };

  // Deduce the type of the template T given in compile time
  if constexpr (std::is_same<T, OnSceneChange>::value)
    std::for_each(evntMgr.sceneEvents.begin(), 
                  evntMgr.sceneEvents.end(), 
                  call_fn);
}

void UnloadEvents();

} // end gilg
