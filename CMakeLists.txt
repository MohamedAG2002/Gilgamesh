cmake_minimum_required(VERSION 3.27.0)
project(Gilgamesh)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # For the LSP
set(CMAKE_BUILD_TYPE Debug) # For gdb
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/lib/)

set(GILG_LIBRARY_TYPE SHARED)
set(GILG_SOURCE_PATH ${CMAKE_SOURCE_DIR}/Gilgamesh/src)
set(GILG_INCLUDE_PATH ${CMAKE_SOURCE_DIR}/Gilgamesh/include)

find_library(glfw glfw REQUIRED)

set(GILG_SOURCES
  # Core 
  ${GILG_SOURCE_PATH}/Core/Application.cpp
  ${GILG_SOURCE_PATH}/Core/Window.cpp
  ${GILG_SOURCE_PATH}/Core/Log.cpp

  # Managers 
  ${GILG_SOURCE_PATH}/Managers/AssetManager.cpp
  ${GILG_SOURCE_PATH}/Managers/EventManager.cpp
  ${GILG_SOURCE_PATH}/Managers/SceneManager.cpp

  # Graphics
  ${GILG_SOURCE_PATH}/Graphics/Renderer2D.cpp
  ${GILG_SOURCE_PATH}/Graphics/Color.cpp

  # Scene 
  ${GILG_SOURCE_PATH}/Scene/Scene2D.cpp

  # Components
  ${GILG_SOURCE_PATH}/Components/Transform2D.cpp
)

add_library(${PROJECT_NAME} ${GILG_LIBRARY_TYPE} ${GILG_SOURCES})

# Making sure the asset folder is in the final build
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_precompile_headers(${PROJECT_NAME} PUBLIC ${GILG_INCLUDE_PATH}/Gilgamesh/GilgPCH.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib/include/)
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${GILG_INCLUDE_PATH})

target_link_libraries(${PROJECT_NAME} PUBLIC
  ${glfw}  
)
