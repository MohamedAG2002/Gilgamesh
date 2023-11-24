#pragma once 

#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning gilg
 
using OnSceneChange = std::function<void(const std::string&&)>;
//using OnEntityCreation = std::function<void(Entity& entt)>;
//using OnEntityDestruction = std::function<void(Entity& entt)>;
//using OnEntityCollision = std::function<void(const std::string& entt_tag1, const std::string& entt_tag2)>;
//using OnSoundPlay = std::function<void(const U64& soundID)>;
//using OnMusicPlay = std::function<void(const U64& musicID)>;
//using OnMusicStop = std::function<void(const U64& musicID)>;
//using OnTimerStart = std::function<void(Entity entt)>;
//using OnTimerStop = std::function<void(Entity entt)>;

} // end gilg
