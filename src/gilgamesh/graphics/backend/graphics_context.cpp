#include "graphics/backend/graphics_context.h"
#include "graphics/backend/vertex_array.h"
#include "core/gilg_asserts.h"
#include "graphics/color.h"
#include "core/defines.h"
#include "core/window.h"

#include <glm/glm.hpp>
#include <glad/gl.h>

namespace gilg {

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
  glm::vec2 size = window_size();
  glViewport(0, 0, size.x, size.y);
  
  // Enable some OpenGL functionalities
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_STENCIL_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // Set the current context
  glfwMakeContextCurrent(window_handle());

  return true;
}

void destroy_gcontext()
{
  GILG_LOG_INFO("Destroyed graphics context");
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

void gcontext_draw_vertex(const draw_mode mode, vertex_array& va)
{
  bind_vertex_array(va); 

  glDrawArrays((u32)mode, 0, va.vbo.count);
}

void gcontext_draw_index(const draw_mode mode, vertex_array& va)
{
  bind_vertex_array(va); 
  
  glDrawElements((u32)mode, va.ebo.count, GL_UNSIGNED_INT, 0);
}
////////////////////////////////////////////////////////////

}
