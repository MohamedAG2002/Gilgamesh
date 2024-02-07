#pragma once

#include "gilgamesh/core/defines.h"

#include <glm/glm.hpp>

namespace gilg {

// Vertex type
/////////////////////////////////////////
struct vertex 
{
  glm::vec3 position;
  glm::vec2 texture_coords;
};
/////////////////////////////////////////

// Vertex 2d struct
/////////////////////////////////////////
struct vertex2d 
{
  glm::vec3 position; 
  glm::vec4 color;
  glm::vec2 texture_coords;
  f32 texture_index;
};
/////////////////////////////////////////

}
