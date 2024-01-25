cmake_minimum_required(VERSION 3.27.0)
project(gilgamesh)

# Setting project variables
######################################
set(GILG_LIBRARY_TYPE STATIC)
set(GILG_BUILD_TYPE Debug)
set(GILG_SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/gilgamesh/)
set(GILG_LIBS_PATH ${CMAKE_SOURCE_DIR}/libs)
######################################

# Setting CMake variables
######################################
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE ${GILG_BUILD_TYPE}) 
######################################

# Finding libraries
######################################
find_library(glfw glfw REQUIRED)
######################################

# Sources
######################################
set(GILG_SOURCES
  # Core 
  ${GILG_SOURCE_PATH}/core/application.cpp
  ${GILG_SOURCE_PATH}/core/window.cpp
  ${GILG_SOURCE_PATH}/core/logger.cpp
  ${GILG_SOURCE_PATH}/core/memory_alloc.cpp
  ${GILG_SOURCE_PATH}/core/event.cpp
  ${GILG_SOURCE_PATH}/core/input.cpp
  ${GILG_SOURCE_PATH}/main.cpp

  # Math 
  ${GILG_SOURCE_PATH}/math/gilg_random.cpp

  # Graphics backend
  ${GILG_SOURCE_PATH}/graphics/backend/graphics_context.cpp
  ${GILG_SOURCE_PATH}/graphics/backend/vertex_array.cpp

  # Graphics
  ${GILG_SOURCE_PATH}/graphics/renderer.cpp
  ${GILG_SOURCE_PATH}/graphics/renderer_queue.cpp
  ${GILG_SOURCE_PATH}/graphics/camera3d.cpp
  
  # Resources
  ${GILG_SOURCE_PATH}/resources/resource_manager.cpp
  ${GILG_SOURCE_PATH}/resources/shader.cpp
  ${GILG_SOURCE_PATH}/resources/texture2d.cpp
)

set(LIBS_SOURCES
  ${GILG_LIBS_PATH}/src/stb_image/stb_image.cpp
  ${GILG_LIBS_PATH}/src/glad/gl.c
)
######################################

# Linking
######################################
#add_library(${PROJECT_NAME} ${GILG_LIBRARY_TYPE} ${LIBS_SOURCES} ${GILG_SOURCES})
add_executable(${PROJECT_NAME} ${GILG_SOURCES} ${LIBS_SOURCES})

target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${GILG_LIBS_PATH}/include)
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${GILG_SOURCE_PATH})

target_link_libraries(${PROJECT_NAME} PUBLIC
  ${glfw}  
)
######################################

# Copying assets
######################################
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
######################################
