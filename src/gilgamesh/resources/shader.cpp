#include "shader.h"
#include "core/defines.h"
#include "core/logger.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/gl.h>

#include <string>
#include <sstream>
#include <fstream>

namespace gilg {

// Private functions
////////////////////////////////////////////////////////////////////////
const std::string read_shader(const char* path)
{
  std::stringstream ss;
  std::ifstream file(path);

  if(!file.is_open())
  {
    GILG_LOG_ERROR("Could not open shader file at \'%s\'", path); 
    return ss.str().c_str();
  }

  ss << file.rdbuf();

  file.close();

  return ss.str().c_str();
}

void check_compile_error(const shader& shader, const u32 shader_id)
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

void check_linker_error(const shader& shader)
{
  int success;
  char log_info[512];

  glGetProgramiv(shader.program, GL_COMPILE_STATUS, &success); 

  if(!success) 
  {
    glGetProgramInfoLog(shader.program, 512, nullptr, log_info);
    printf("[SHADER-ERROR]: %s\n", log_info);
  }
}

unsigned int get_uniform_location(const shader& shader, const char* name)
{
  u32 uni_loc = 0;

  uni_loc = glGetUniformLocation(shader.program, name);
  if(uni_loc == -1)
    printf("[SHADER-ERROR]: Could not find variable \'%s\' in the shader\n", name);

  return uni_loc;
}
////////////////////////////////////////////////////////////////////////

// Shader functions
////////////////////////////////////////////////////////////////////////
shader load_shader(const std::string& vert_path, const std::string& frag_path)
{
  shader shdr;

  // Vertex shader
  std::string vert_str = read_shader(vert_path.c_str());
  const char* vert_src = vert_str.c_str(); 
  shdr.vert = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(shdr.vert, 1, &vert_src, 0);
  glCompileShader(shdr.vert);
  check_compile_error(shdr, shdr.vert);

  // Fragment shader
  std::string frag_str = read_shader(frag_path.c_str());
  const char* frag_src = frag_str.c_str(); 
  shdr.frag = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(shdr.frag, 1, &frag_src, 0);
  glCompileShader(shdr.frag);
  check_compile_error(shdr, shdr.frag);

  // Program linking
  shdr.program = glCreateProgram();
  glAttachShader(shdr.program, shdr.vert);
  glAttachShader(shdr.program, shdr.frag);
  glLinkProgram(shdr.program);
  check_linker_error(shdr);

  // Detach and delete shaders since they are useless now
  glDetachShader(shdr.program, shdr.vert);
  glDetachShader(shdr.program, shdr.frag);
  glDeleteShader(shdr.vert);
  glDeleteShader(shdr.frag);

  return shdr;
}

void unload_shader(shader& shader)
{

}

void bind_shader(shader& shader)
{
  glUseProgram(shader.program);
}

void set_shader_int(shader& shader, const std::string& name, i32 value)
{
  glUniform1i(get_uniform_location(shader, name.c_str()), value);
}

void set_shader_float(shader& shader, const std::string& name, f32 value)
{
  glUniform1f(get_uniform_location(shader, name.c_str()), value);
}

void set_shader_mat4(shader& shader, const std::string& name, const glm::mat4& value)
{
  glUniformMatrix4fv(get_uniform_location(shader, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void set_shader_vec3(shader& shader, const std::string& name, const glm::vec3& value)
{
  glUniform3f(get_uniform_location(shader, name.c_str()), value.x, value.y, value.z);
}
////////////////////////////////////////////////////////////////////////

}
