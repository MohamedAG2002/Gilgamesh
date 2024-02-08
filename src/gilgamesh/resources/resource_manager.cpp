#include "resource_manager.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/core/logger.h"
#include "gilgamesh/core/gilg_asserts.h"
#include "gilgamesh/resources/texture2d.h"

#include <string>
#include <unordered_map>

namespace gilg {

// Resource manager type
///////////////////////////////////////////////////////////////
struct resource_manager 
{
  std::unordered_map<std::string, texture2d*> textures2d;
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

texture2d* resource_get_texture(const std::string& id)
{
  GILG_ASSERT_MSG(rsrc_man.textures2d.find(id) != rsrc_man.textures2d.end(), "Could not retrieve texture2d since it doesn't exist");
  return rsrc_man.textures2d[id];
}

b8 resource_remove_texture(const std::string& id)
{
  GILG_ASSERT_MSG(rsrc_man.textures2d.find(id) != rsrc_man.textures2d.end(), "Could not remove texture2d since it doesn't exist");

  unload_texture2d(rsrc_man.textures2d[id]);
  rsrc_man.textures2d.erase(id);
  return true;
}
///////////////////////////////////////////////////////////////

}
