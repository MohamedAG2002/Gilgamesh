#include "resource_manager.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/core/logger.h"
#include "gilgamesh/core/gilg_asserts.h"
#include "gilgamesh/resources/texture2d.h"
#include "gilgamesh/resources/shader.h"

#include <string>
#include <unordered_map>

namespace gilg {

// Resource manager type
///////////////////////////////////////////////////////////////
struct resource_manager 
{
  std::unordered_map<std::string, texture2d*> textures2d;
  std::unordered_map<std::string, shader*> shaders;
};

static resource_manager rsrc_man;
///////////////////////////////////////////////////////////////

// Resource manager functions
///////////////////////////////////////////////////////////////
b8 init_resource_manager()
{
  GILG_LOG_INFO("Resource manager was successfully initialized");

  return true;
}

void shutdown_resource_manager()
{
  // Unloading textures
  for(auto& [key, value] : rsrc_man.textures2d)
    unload_texture2d(value); 
  rsrc_man.textures2d.clear();

  // Unloading shaders
  for(auto& [key, value] : rsrc_man.shaders)
    unload_shader(value);
  rsrc_man.shaders.clear();

  GILG_LOG_INFO("Resource manager was successfully shutdown");
}

void resource_add_texture(const std::string& name, const std::string& path)
{
  GILG_ASSERT_MSG(rsrc_man.textures2d.find(name) == rsrc_man.textures2d.end(), "Texture2D already exists");
  rsrc_man.textures2d[name] = load_texture2d(path);
}

void resource_add_texture(const std::string& name, u32 width, u32 height, texture_format format, void* pixels)
{
  GILG_ASSERT_MSG(rsrc_man.textures2d.find(name) == rsrc_man.textures2d.end(), "Texture2D already exists");
  rsrc_man.textures2d[name] = load_texture2d(width, height, format, pixels);
}

void resource_add_shader(const std::string& name, const std::string& vert_path, const std::string& frag_path)
{
  GILG_ASSERT_MSG(rsrc_man.shaders.find(name) == rsrc_man.shaders.end(), "Shader already exists");
  rsrc_man.shaders[name] = load_shader(vert_path, frag_path);
}

texture2d* resource_get_texture(const std::string& id)
{
  GILG_ASSERT_MSG(rsrc_man.textures2d.find(id) != rsrc_man.textures2d.end(), "Could not retrieve texture2d since it doesn't exist");
  return rsrc_man.textures2d[id];
}

shader* resource_get_shader(const std::string& id)
{
  GILG_ASSERT_MSG(rsrc_man.shaders.find(id) != rsrc_man.shaders.end(), "Could not retrieve shader since it doesn't exist");
  return rsrc_man.shaders[id];
}

b8 resource_remove_texture(const std::string& id)
{
  GILG_ASSERT_MSG(rsrc_man.textures2d.find(id) != rsrc_man.textures2d.end(), "Could not remove texture2d since it doesn't exist");

  rsrc_man.textures2d.erase(id);
  return true;
}

b8 resource_remove_shader(const std::string& id)
{
  GILG_ASSERT_MSG(rsrc_man.shaders.find(id) != rsrc_man.shaders.end(), "Could not remove shader since it doesn't exist");

  rsrc_man.shaders.erase(id);
  return true;
}
///////////////////////////////////////////////////////////////

}
