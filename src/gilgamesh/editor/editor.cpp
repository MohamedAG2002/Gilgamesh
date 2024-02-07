#include "editor.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/core/logger.h"
#include "gilgamesh/core/window.h"
#include "gilgamesh/core/clock.h"
#include "gilgamesh/core/memory_alloc.h"

#include "gilgamesh/graphics/backend/graphics_context.h"
#include "gilgamesh/graphics/renderer2d.h"

#include <glm/glm.hpp>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_opengl3_loader.h>

namespace gilg {

// Editor functions
/////////////////////////////////////////////////////
b8 editor_init()
{
  // Set up ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO io = ImGui::GetIO(); (void)io;

  // Setting context flags
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; 
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

  // Dark mode WOOOOOOOAH! 
  ImGui::StyleColorsDark();

  // Setting up the glfw backend
  if(!ImGui_ImplGlfw_InitForOpenGL(window_handle(), true))
  {
    GILG_LOG_ERROR("Failed to initialize GLFW-OpenGL for ImGui");
    return false;
  }
  
  // Setting up the opengl backend
  if(!ImGui_ImplOpenGL3_Init("#version 460 core"))
  {
    GILG_LOG_ERROR("Failed to initialize OpenGL for ImGui");
    return false;
  }

  GILG_LOG_INFO("Editor was successfully initialized");
  return true;
}

void editor_shutdown()
{
  ImGui_ImplGlfw_Shutdown();
  ImGui_ImplOpenGL3_Shutdown();
  ImGui::DestroyContext();
  
  GILG_LOG_INFO("Editor was successfully shutdown");
}

void editor_begin()
{
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void editor_end()
{
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void editor_debug_info()
{
  ImGui::Begin("Debug Info");
  ImGui::Text("Version: 0.1");

  glm::vec2 mouse_pos = get_mouse_pos();
  ImGui::Text("Mouse Position: {X = %f, Y = %f}", mouse_pos.x, mouse_pos.y);
  
  f64 fps = clock_fps(); 
  ImGui::Text("FPS = %f", fps);

  usizei usage = get_current_memory_usage();
  ImGui::Text("Memory Usage = %zu", usage);

  ImGui::End();
}

void editor_renderer_info(render_data& data)
{
  ImGui::Begin("Renderer Info");
  
  context_debug_info debug_info = gcontext_debug_info();
  ImGui::Text("Vendor: %s", debug_info.vendor.c_str());
  ImGui::Text("Renderer: %s", debug_info.renderer.c_str());
  ImGui::Text("Version: %s", debug_info.version.c_str());

  usizei draw_calls = get_renderer2d_stats().draw_calls;
  usizei quads = get_renderer2d_stats().total_quads;
  ImGui::Text("2D Draw calls: %zu", draw_calls); 
  ImGui::Text("2D Total quads: %zu", quads); 
  ImGui::NewLine();

  ImGui::ColorEdit3("Background Color", &data.clear_color.r);

  ImGui::End();
}

static u8 current_cam_type = 0;
void editor_camera_panel(camera3d& cam)
{
  const char* camera_types[] = {"Free", "FPS"};

  ImGui::Begin("Camera");
  ImGui::End();
}

void editor_entities_panel(glm::vec2& pos, glm::vec2& size, color& color)
{
  ImGui::Begin("Entitites");
  ImGui::SliderFloat2("Position", &pos.r, -1.0f, 1.0f);
  ImGui::SliderFloat2("Size", &size.r, 0.0f, 1.0f);
  ImGui::ColorPicker4("Color", &color.r);
  ImGui::End();
}
/////////////////////////////////////////////////////

}
