#include "graphics_context.h"
#include "gilgamesh/graphics/backend/vertex_array.h"
#include "gilgamesh/core/gilg_asserts.h"
#include "gilgamesh/graphics/color.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/core/window.h"

#include <glm/glm.hpp>
#include <glad/gl.h>

#include <string>

namespace gilg {

// Globals
////////////////////////////////////////////////////////////
static context_debug_info debug_info;
////////////////////////////////////////////////////////////

// Graphics context functions
////////////////////////////////////////////////////////////
b8 create_gcontext()
{
  GILG_LOG_INFO("Created graphics context");
  
  // GLAD init 
  if(!gladLoadGL(glfwGetProcAddress))
  {
    GILG_ASSERT_MSG(false, "Failed to load GLAD");
    return false;
  }

  // Set the viewport's size
  glm::vec2 size = get_window_size();
  glViewport(0, 0, size.x, size.y);
  
  // Enable some OpenGL functionalities
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_STENCIL_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // Set the current context
  glfwMakeContextCurrent(window_handle());

  // Retrieving debug info 
  debug_info = context_debug_info{
    .vendor   = (char*)glGetString(GL_VENDOR),
    .renderer = (char*)glGetString(GL_RENDERER),
    .version  = (char*)glGetString(GL_VERSION),
  };

  return true;
}

void destroy_gcontext()
{
  GILG_LOG_INFO("Destroyed graphics context");
}

const context_debug_info& gcontext_debug_info()
{
  return debug_info;
}

void gcontext_clear(const color& color)
{
  glClearColor(color.r, color.g, color.b, color.a);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void gcontext_swap()
{
  glfwSwapBuffers(window_handle());
}

void gcontext_draw_vertex(const draw_mode mode, const vertex_array& va)
{
  bind_vertex_array(va); 
  glDrawArrays((u32)mode, 0, va.vertex_buffer.count);
}

void gcontext_draw_index(const draw_mode mode, const vertex_array& va)
{
  bind_vertex_array(va); 
  glDrawElements((u32)mode, va.index_buffer.count, GL_UNSIGNED_INT, 0);
}

void gcontext_draw_vertex_inst(const draw_mode mode, vertex_array& va, usizei inst_count)
{
  bind_vertex_array(va); 
  glDrawArraysInstanced((u32)mode, 0, va.vertex_buffer.count, inst_count);
}

void gcontext_draw_index_inst(const draw_mode mode, vertex_array& va, usizei inst_count)
{
  bind_vertex_array(va); 
  glDrawElementsInstanced((u32)mode, va.index_buffer.count, GL_UNSIGNED_INT, 0, inst_count);
}
////////////////////////////////////////////////////////////

}
