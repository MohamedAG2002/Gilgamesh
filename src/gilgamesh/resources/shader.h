#pragma once

#include "gilgamesh/core/defines.h"

#include <glm/glm.hpp>

#include <string>

namespace gilg {

struct shader_src 
{
  std::string vert_src, frag_src;
};

struct shader 
{
  u32 program, vert, frag;
};

// Shader functions
////////////////////////////////////////////////////////////////////////
shader* load_shader(const std::string& path);
void unload_shader(shader* shdr);

void bind_shader(const shader* shader);

void set_shader_int(const shader* shader, const std::string& name, const i32 value);
void set_shader_float(const shader* shader, const std::string& name, const f32 value);

void set_shader_mat4(const shader* shader, const std::string& name, const glm::mat4& value);
void set_shader_vec3(const shader* shader, const std::string& name, const glm::vec3& value);
void set_shader_vec4(const shader* shader, const std::string& name, const glm::vec4& value);

void set_shader_int_arr(const shader* shader, const std::string& name, const int* arr, const usizei count);
void set_shader_mat4_arr(const shader* shader, const std::string& name, const glm::mat4* arr, const usizei count);
void set_shader_vec3_arr(const shader* shader, const std::string& name, const glm::vec3* arr, const usizei count);
void set_shader_vec4_arr(const shader* shader, const std::string& name, const glm::vec4* arr, const usizei count);
////////////////////////////////////////////////////////////////////////

}
