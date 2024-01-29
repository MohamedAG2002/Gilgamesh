#pragma once

#include "core/defines.h"
#include "graphics/renderer.h"

namespace gilg {

// Editor functions
/////////////////////////////////////////////////////
b8 editor_init();
void editor_shutdown();
void editor_begin();
void editor_end();

void editor_engine_info();
void editor_renderer_info(render_data& data);
void editor_info_window(render_data& data);
void editor_camera_panel(camera3d& cam);
void editor_hierarchy_panel();
/////////////////////////////////////////////////////

}
