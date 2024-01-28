#pragma once

#include "core/defines.h"

#include <glm/glm.hpp>

#include <string>

namespace gilg {

struct shader 
{
  u32 program, vert, frag;
};

// Shader functions
////////////////////////////////////////////////////////////////////////
shader load_shader(const std::string& vert_path, const std::string& frag_path);
void unload_shader(shader& shader);

void bind_shader(const shader& shader);

void set_shader_int(shader& shader, const std::string& name, i32 value);
void set_shader_float(shader& shader, const std::string& name, f32 value);

void set_shader_mat4(shader& shader, const std::string& name, const glm::mat4& value);
void set_shader_vec3(shader& shader, const std::string& name, const glm::vec3& value);
////////////////////////////////////////////////////////////////////////

}
