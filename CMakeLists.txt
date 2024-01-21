cmake_minimum_required(VERSION 3.27.0)
project(gilgamesh)

# Setting project variables
######################################
set(GILG_LIBRARY_TYPE SHARED)
set(GILG_BUILD_TYPE Debug)
set(GILG_SOURCE_PATH ${CMAKE_SOURCE_DIR}/gilgamesh/src)
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
  ${GILG_SOURCE_PATH}/main.cpp
)

set(LIBS_SOURCES
  ${GILG_LIBS_PATH}/src/stb_image/stb_image.cpp
  ${GILG_LIBS_PATH}/src/glad/gl.c
)
######################################

add_executable(${PROJECT_NAME} ${LIBS_SOURCES} ${GILG_SOURCES})

target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${GILG_LIBS_PATH}/include)
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${GILG_SOURCE_PATH})

target_link_libraries(${PROJECT_NAME} PUBLIC
  ${glfw}  
)
