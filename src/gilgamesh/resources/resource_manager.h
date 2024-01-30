#pragma once

#include "gilgamesh/core/defines.h"

#include "gilgamesh/resources/texture2d.h"
#include "gilgamesh/resources/shader.h"

#include <string>

namespace gilg {

// Typedefs
///////////////////////////////////////////////////////////////
typedef u64 resource_id;
///////////////////////////////////////////////////////////////

// Resource manager functions
///////////////////////////////////////////////////////////////
b8 init_resource_manager();
void shutdown_resource_manager();

GILG_API resource_id resource_add_texture(const std::string& path);
GILG_API resource_id resource_add_shader(const std::string& vert_path, const std::string& frag_path);

GILG_API texture2d resource_get_texture(const resource_id& id);
GILG_API shader resource_get_shader(const resource_id& id);

GILG_API b8 resource_remove_texture(const resource_id& id);
GILG_API b8 resource_remove_shader(const resource_id& id);
///////////////////////////////////////////////////////////////

}
