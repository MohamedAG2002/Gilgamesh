#pragma once

#include "Gilgamesh/Core/Defines.hpp"

#include <random>

namespace gilg { // beginning gilg

namespace util { // beginning util

template<typename T>
GILG_API T GetRandomNumber()
{
  std::random_device rndDevice;
  std::default_random_engine rndEngine(rndDevice());
  std::uniform_int_distribution<T> uniformDist;

  return uniformDist(rndEngine);
}

} // end util

} // end gilg
