#pragma once

#include <glm/glm.hpp>

namespace gilg {

typedef glm::vec4 color;

// Color consts
const color GILG_COLOR_RED           = color(1.0f, 0.0f, 0.0f, 1.0f);
const color GILG_COLOR_GREEN         = color(0.0f, 1.0f, 0.0f, 1.0f);
const color GILG_COLOR_BLUE          = color(0.0f, 0.0f, 1.0f, 1.0f);
const color GILG_COLOR_BLACK         = color(0.0f, 0.0f, 0.0f, 1.0f);
const color GILG_COLOR_WHITE         = color(1.0f);
const color GILG_COLOR_TRANSPARENT   = color(0.0f);
const color GILG_COLOR_CYAN          = color(0.0f, 1.0f, 1.0f, 1.0f);
const color GILG_COLOR_MAGENTA       = color(1.0f, 0.0f, 1.0f, 1.0f);
const color GILG_COLOR_YELLOW        = color(1.0f, 1.0f, 0.0f, 1.0f);

}
