cmake_minimum_required(VERSION 3.27.0)
project(gilgamesh)

# Setting project variables
######################################
set(GILG_LIBRARY_TYPE STATIC)
set(GILG_BUILD_TYPE Debug)
set(GILG_SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/gilgamesh)
set(GILG_HEADER_PATH ${CMAKE_SOURCE_DIR}/src/)
set(GILG_LIBS_PATH ${CMAKE_SOURCE_DIR}/libs)
######################################

# Setting CMake variables
######################################
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE ${GILG_BUILD_TYPE}) 
######################################

# Finding libraries
######################################
find_library(glfw glfw REQUIRED)
find_package(spdlog REQUIRED)
######################################

# Sources
######################################
set(GILG_SOURCES
  # Core 
  ${GILG_SOURCE_PATH}/core/engine.cpp
  ${GILG_SOURCE_PATH}/core/window.cpp
  ${GILG_SOURCE_PATH}/core/logger.cpp
  ${GILG_SOURCE_PATH}/core/memory_alloc.cpp
  ${GILG_SOURCE_PATH}/core/event.cpp
  ${GILG_SOURCE_PATH}/core/input.cpp
  ${GILG_SOURCE_PATH}/core/clock.cpp

  # Math 
  ${GILG_SOURCE_PATH}/math/gilg_random.cpp
  ${GILG_SOURCE_PATH}/math/transform.cpp
  ${GILG_SOURCE_PATH}/math/math_utils.cpp

  # Graphics backend
  ${GILG_SOURCE_PATH}/graphics/backend/graphics_context.cpp
  ${GILG_SOURCE_PATH}/graphics/backend/vertex_array.cpp
  ${GILG_SOURCE_PATH}/graphics/backend/uniform_buffer.cpp

  # Graphics
  ${GILG_SOURCE_PATH}/graphics/renderer.cpp
  ${GILG_SOURCE_PATH}/graphics/renderer2d.cpp
  ${GILG_SOURCE_PATH}/graphics/renderer_queue.cpp
  ${GILG_SOURCE_PATH}/graphics/camera3d.cpp
  ${GILG_SOURCE_PATH}/graphics/shader_lib.cpp
  
  # Resources
  ${GILG_SOURCE_PATH}/resources/resource_manager.cpp
  ${GILG_SOURCE_PATH}/resources/shader.cpp
  ${GILG_SOURCE_PATH}/resources/texture2d.cpp
  ${GILG_SOURCE_PATH}/resources/mesh.cpp
 
  # Editor
  ${GILG_SOURCE_PATH}/editor/editor.cpp
)

set(IMGUI_SOURCES
  ${GILG_LIBS_PATH}/src/imgui/imgui.cpp 
  ${GILG_LIBS_PATH}/src/imgui/imgui_demo.cpp 
  ${GILG_LIBS_PATH}/src/imgui/imgui_draw.cpp 
  ${GILG_LIBS_PATH}/src/imgui/imgui_tables.cpp 
  ${GILG_LIBS_PATH}/src/imgui/imgui_widgets.cpp 
  
  ${GILG_LIBS_PATH}/src/imgui/imgui_impl_glfw.cpp 
  ${GILG_LIBS_PATH}/src/imgui/imgui_impl_opengl3.cpp 
)

set(LIBS_SOURCES
  ${GILG_LIBS_PATH}/src/stb_image/stb_image.cpp
  ${GILG_LIBS_PATH}/src/glad/gl.c
  ${IMGUI_SOURCES}
)
######################################

# Linking
######################################
add_library(${PROJECT_NAME} ${GILG_LIBRARY_TYPE} ${LIBS_SOURCES} ${GILG_SOURCES})

target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${GILG_LIBS_PATH}/include)
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${GILG_HEADER_PATH})

target_link_libraries(${PROJECT_NAME} PRIVATE
  ${glfw}  
  spdlog::spdlog_header_only
)
######################################

# Copying assets
######################################
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
######################################
