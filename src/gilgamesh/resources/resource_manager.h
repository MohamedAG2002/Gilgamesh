#pragma once

#include "gilgamesh/core/defines.h"
#include "gilgamesh/resources/texture2d.h"
#include "gilgamesh/resources/mesh.h"

#include <string>

namespace gilg {

// Resource manager functions
///////////////////////////////////////////////////////////////
b8 init_resource_manager();
void shutdown_resource_manager();

GILG_API void resource_add_texture(const std::string& name, const std::string& path);
GILG_API void resource_add_texture(const std::string& name, u32 width, u32 height, texture_format format, void* pixels);
GILG_API void resource_add_mesh(const std::string& name, const mesh_desc& desc);

GILG_API texture2d* resource_get_texture(const std::string& id);
GILG_API mesh* resource_get_mesh(const std::string& id);

GILG_API b8 resource_remove_texture(const std::string& id);
GILG_API b8 resource_remove_mesh(const std::string& id);
///////////////////////////////////////////////////////////////

}
