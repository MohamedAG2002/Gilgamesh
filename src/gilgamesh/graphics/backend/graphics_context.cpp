#include "graphics/backend/graphics_context.h"
#include "core/gilg_asserts.h"
#include "graphics/color.h"
#include "core/defines.h"
#include "core/window.h"

#include <glm/glm.hpp>
#include <glad/gl.h>

namespace gilg {

// Graphics context functions
////////////////////////////////////////////////////////////
graphics_context create_gcontext()
{
  GILG_LOG_INFO("Created graphics context");
  
  // GLAD init 
  GILG_ASSERT_MSG(gladLoadGL(glfwGetProcAddress), "Failed to initialize GLAD"); 

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

  return graphics_context{};
}

void destroy_gcontext(graphics_context& context)
{
  GILG_LOG_INFO("Destroyed graphics context");
}

void gcontext_clear(const graphics_context& context, const color& color)
{
  glClearColor(color.r, color.g, color.b, color.a);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void gcontext_swap(const graphics_context& context)
{
  glfwSwapBuffers(window_handle());
}

void gcontext_draw_vertex(const graphics_context& context, const draw_mode mode, const usizei vertices_count)
{
  glDrawArrays((u32)mode, 0, vertices_count);
}

void gcontext_draw_index(const graphics_context& context, const draw_mode mode, const usizei indices_count)
{
  glDrawElements((u32)mode, indices_count, GL_UNSIGNED_INT, 0);
}
////////////////////////////////////////////////////////////

}
