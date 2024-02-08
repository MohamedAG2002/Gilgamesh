#include "shader.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/core/logger.h"
#include "gilgamesh/core/memory_alloc.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/gl.h>

#include <string>
#include <cstring>
#include <fstream>

namespace gilg {

// Private functions
////////////////////////////////////////////////////////////////////////
static shader_src read_shader(const std::string& path)
{
  std::string str;
  std::fstream file(path, std::ios::in);
  shader_src src;

  if(!file.is_open())
  {
    GILG_LOG_ERROR("Could not open shader file at \'%s\'", path.c_str()); 
    return shader_src{};
  }

  // Get the size of the file and resize the result string accordingly
  file.seekg(0, std::ios::end);
  str.resize(file.tellg());

  // Start from the beginning again
  file.seekg(std::ios::beg);

  // Read the contents of the file into the string and close the file afterwards
  file.read(&str[0], str.size());
  file.close();

  usizei vert_iden_size = strlen("@type vertex");
  usizei frag_iden_size = strlen("@type fragment");
  usizei vert_pos = str.find("@type vertex");
  usizei frag_pos = str.find("@type fragment");

  // No vertex identifier found
  if(vert_pos == std::string::npos)
    GILG_LOG_ERROR("[SHADER-ERROR]: No vertex identifier found in shader \'%s\'", path.c_str());

  // No fragment identifier found
  if(frag_pos == std::string::npos)
    GILG_LOG_ERROR("[SHADER-ERROR]: No fragment identifier found in shader \'%s\'", path.c_str());

  src.vert_src = str.substr(vert_pos + vert_iden_size, frag_pos - vert_iden_size);
  src.frag_src = str.substr(frag_pos + frag_iden_size);

  return src;
}

static void check_compile_error(const u32 shader_id)
{
  int success;
  char log_info[512];

  glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success); 

  if(!success) 
  {
    glGetShaderInfoLog(shader_id, 512, nullptr, log_info);
    printf("[SHADER-ERROR]: %s\n", log_info);
  }
}

static void check_linker_error(const shader* shader)
{
  int success;
  char log_info[512];

  glGetProgramiv(shader->program, GL_COMPILE_STATUS, &success); 

  if(!success) 
  {
    glGetProgramInfoLog(shader->program, 512, nullptr, log_info);
    printf("[SHADER-ERROR]: %s\n", log_info);
  }
}

static unsigned int get_uniform_location(const shader* shader, const char* name)
{
  u32 uni_loc = 0;

  uni_loc = glGetUniformLocation(shader->program, name);
  if(uni_loc == -1)
    GILG_LOG_ERROR("[SHADER-ERROR]: Could not find variable \'%s\' in the shader\n", name);

  return uni_loc;
}
////////////////////////////////////////////////////////////////////////

// Shader functions
////////////////////////////////////////////////////////////////////////
shader* load_shader(const std::string& path)
{
  shader* shdr = (shader*)alloc_memory(sizeof(shader));
  shader_src sources = read_shader(path);

  // Vertex shader
  const char* vert_src = sources.vert_src.c_str(); 
  shdr->vert = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(shdr->vert, 1, &vert_src, 0);
  glCompileShader(shdr->vert);
  check_compile_error(shdr->vert);

  // Fragment shader
  const char* frag_src = sources.frag_src.c_str(); 
  shdr->frag = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(shdr->frag, 1, &frag_src, 0);
  glCompileShader(shdr->frag);
  check_compile_error(shdr->frag);

  // Program linking
  shdr->program = glCreateProgram();
  glAttachShader(shdr->program, shdr->vert);
  glAttachShader(shdr->program, shdr->frag);
  glLinkProgram(shdr->program);
  check_linker_error(shdr);

  // Detach and delete shaders since they are useless now
  glDetachShader(shdr->program, shdr->vert);
  glDetachShader(shdr->program, shdr->frag);
  glDeleteShader(shdr->vert);
  glDeleteShader(shdr->frag);

  return shdr;
}

void unload_shader(shader* shdr)
{
  free_memory(shdr, sizeof(shader));
}

void bind_shader(const shader* shader)
{
  glUseProgram(shader->program);
}

void set_shader_int(const shader* shader, const std::string& name, i32 value)
{
  glUniform1i(get_uniform_location(shader, name.c_str()), value);
}

void set_shader_float(const shader* shader, const std::string& name, f32 value)
{
  glUniform1f(get_uniform_location(shader, name.c_str()), value);
}

void set_shader_mat4(const shader* shader, const std::string& name, const glm::mat4& value)
{
  glUniformMatrix4fv(get_uniform_location(shader, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void set_shader_vec3(const shader* shader, const std::string& name, const glm::vec3& value)
{
  glUniform3f(get_uniform_location(shader, name.c_str()), value.x, value.y, value.z);
}

void set_shader_vec4(const shader* shader, const std::string& name, const glm::vec4& value)
{
  glUniform4f(get_uniform_location(shader, name.c_str()), value.x, value.y, value.z, value.w);
}

void set_shader_int_arr(const shader* shader, const std::string& name, const int* arr, const usizei count)
{
  glUniform1iv(get_uniform_location(shader, name.c_str()), count, arr);
}

void set_shader_mat4_arr(const shader* shader, const std::string& name, const glm::mat4* arr, const usizei count)
{
  for(int i = 0; i < count; i++)
  {
    std::string index_str = name + "[" + std::to_string(i) + "]";
    glm::mat4 value = arr[i];

    glUniformMatrix4fv(get_uniform_location(shader, index_str.c_str()), 1, GL_FALSE, glm::value_ptr(value));
  }
}

void set_shader_vec3_arr(const shader* shader, const std::string& name, const glm::vec3* arr, const usizei count)
{
  for(int i = 0; i < count; i++)
  {
    std::string index_str = name + "[" + std::to_string(i) + "]";
    glm::vec3 value = arr[i];

    glUniform3f(get_uniform_location(shader, index_str.c_str()), value.x, value.y, value.z);
  }
}

void set_shader_vec4_arr(const shader* shader, const std::string& name, const glm::vec4* arr, const usizei count)
{
  for(int i = 0; i < count; i++)
  {
    std::string index_str = name + "[" + std::to_string(i) + "]";
    glm::vec4 value = arr[i];

    glUniform4f(get_uniform_location(shader, index_str.c_str()), value.x, value.y, value.z, value.w);
  }
}
////////////////////////////////////////////////////////////////////////

}
