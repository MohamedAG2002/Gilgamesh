#include "Gilgamesh/Managers/EventManager.hpp"
#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning gilg

EventManager evntMgr;

void UnloadEvents()
{
  evntMgr.sceneEvents.clear();
}

} // end gilg
