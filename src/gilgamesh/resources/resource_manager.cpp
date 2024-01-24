#include "resource_manager.h"
#include "core/defines.h"
#include "core/logger.h"
#include "core/gilg_asserts.h"
#include "resources/texture2d.h"
#include "resources/shader.h"
#include "math/gilg_random.h"

#include <string>
#include <unordered_map>

namespace gilg {

// Resource manager type
///////////////////////////////////////////////////////////////
struct resource_manager 
{
  std::unordered_map<resource_id, texture2d> textures2d;
  std::unordered_map<resource_id, shader> shaders;
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

resource_id resource_add_texture(const std::string& path)
{
  resource_id id = random_ulong();
  rsrc_man.textures2d[id] = load_texture2d(path);

  return id;
}

resource_id resource_add_shader(const std::string& vert_path, const std::string& frag_path)
{
  resource_id id = random_ulong();
  rsrc_man.shaders[id] = load_shader(vert_path, frag_path);

  return id;
}

texture2d resource_get_texture(const resource_id& id)
{
  if (rsrc_man.textures2d.find(id) == nullptr)
    GILG_ASSERT_MSG(false, "Could not retrieve texture2d since it doesn't exist");

  return rsrc_man.textures2d[id];
}

shader resource_get_shader(const resource_id& id)
{
  if (rsrc_man.shaders.find(id) == nullptr)
    GILG_ASSERT_MSG(false, "Could not retrieve shader since it doesn't exist");
  
  return rsrc_man.shaders[id];
}

b8 resource_remove_texture(const resource_id& id)
{
  if (rsrc_man.textures2d.find(id) == nullptr)
  {
    GILG_ASSERT_MSG(false, "Could not remove texture2d since it doesn't exist");
    return false;
  }

  rsrc_man.textures2d.erase(id);
  return true;
}

b8 resource_remove_shader(const resource_id& id)
{
  if (rsrc_man.shaders.find(id) == nullptr)
  {
    GILG_ASSERT_MSG(false, "Could not remove shader since it doesn't exist");
    return false;
  }

  rsrc_man.shaders.erase(id);
  return true;
}
///////////////////////////////////////////////////////////////

}
