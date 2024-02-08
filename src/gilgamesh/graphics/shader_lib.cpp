#include "gilgamesh/graphics/shader_lib.h"
#include "gilgamesh/core/gilg_asserts.h"
#include "gilgamesh/core/logger.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/resources/shader.h"

#include <unordered_map>
#include <string>

namespace gilg {

// Shader Lib struct
///////////////////////////////////////////////////
struct shader_lib 
{
  std::unordered_map<std::string, shader*> shaders;
  std::string path;
};

static shader_lib lib;
///////////////////////////////////////////////////

// Shader Lib functions
///////////////////////////////////////////////////
b8 shader_lib_init(const std::string& path_prefix)
{
  lib.path = path_prefix;
  GILG_ASSERT_MSG(!lib.path.empty(), "Empty path prefix given");

  GILG_LOG_INFO("Shader library successfully initialized");
  return true;
}

void shader_lib_shutdown()
{
  for(auto& [key, value] : lib.shaders)
    unload_shader(value);
  lib.shaders.clear();
  
  GILG_LOG_INFO("Shader library successfully shutdown");
}

void shader_lib_add(const std::string& id, const std::string& shader_file)
{
  GILG_ASSERT_MSG(lib.shaders.find(id) == lib.shaders.end(), "Shader already exists");
  lib.shaders[id] = load_shader(lib.path + shader_file);
}

b8 shader_lib_remove(const std::string& id)
{
  GILG_ASSERT_MSG(lib.shaders.find(id) != lib.shaders.end(), "Could not remove shader since it doesn't exist");

  unload_shader(lib.shaders[id]);
  lib.shaders.erase(id);
  return true;
}

shader* shader_lib_get(const std::string& id)
{
  GILG_ASSERT_MSG(lib.shaders.find(id) != lib.shaders.end(), "Could not retrieve shader since it doesn't exist");
  return lib.shaders[id];
}
///////////////////////////////////////////////////

}
