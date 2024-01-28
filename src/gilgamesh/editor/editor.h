#pragma once

#include "core/defines.h"

namespace gilg {

// Editor functions
/////////////////////////////////////////////////////
b8 editor_init();
void editor_shutdown();
void editor_begin();
void editor_end();

void editor_engine_info();
void editor_renderer_info();
void editor_hierarchy_panel();
/////////////////////////////////////////////////////

}
