#pragma once

#include "gilgamesh/core/defines.h"

#include "gilgamesh/resources/texture2d.h"
#include "gilgamesh/resources/shader.h"

#include <string>

namespace gilg {

// Resource manager functions
///////////////////////////////////////////////////////////////
b8 init_resource_manager();
void shutdown_resource_manager();

GILG_API void resource_add_texture(const std::string& name, const std::string& path);
GILG_API void resource_add_shader(const std::string& name, const std::string& vert_path, const std::string& frag_path);

GILG_API const texture2d resource_get_texture(const std::string& id);
GILG_API const shader resource_get_shader(const std::string& id);

GILG_API b8 resource_remove_texture(const std::string& id);
GILG_API b8 resource_remove_shader(const std::string& id);
///////////////////////////////////////////////////////////////

}
