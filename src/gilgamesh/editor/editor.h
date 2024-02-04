#pragma once

#include "gilgamesh/core/defines.h"
#include "gilgamesh/graphics/renderer.h"

#include <glm/glm.hpp>

namespace gilg {

// Editor functions
/////////////////////////////////////////////////////
b8 editor_init();
void editor_shutdown();
void editor_begin();
void editor_end();

void editor_debug_info();
void editor_renderer_info(render_data& data);
void editor_camera_panel(camera3d& cam);
void editor_entities_panel(glm::vec2& pos, glm::vec2& size, color& color);
/////////////////////////////////////////////////////

}
