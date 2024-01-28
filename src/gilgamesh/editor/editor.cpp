#include "editor.h"
#include "core/defines.h"
#include "core/logger.h"
#include "core/window.h"

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
}

void editor_begin()
{
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGui::ShowDemoWindow();
}

void editor_end()
{
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
/////////////////////////////////////////////////////

}