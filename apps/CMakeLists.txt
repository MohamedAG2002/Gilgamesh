cmake_minimum_required(VERSION 3.27)
project(testbed)

set(CMAKE_PREFIX_PATH "/home/mohamed/Dev/C++/GilgameshEngine/")
set(CMAKE_BUILD_TYPE Debug)
set(TESTBED_SRC_DIR ${CMAKE_SOURCE_DIR})

set(GILG_HEADER_DIR ${CMAKE_PREFIX_PATH}/src)
set(GILG_LIBS_DIR ${CMAKE_PREFIX_PATH}/libs/include)
set(GILG_LIB ${CMAKE_PREFIX_PATH}/build/libgilgamesh.a)

find_library(glfw glfw REQUIRED)

set(TEST_SRC
  # Core test
  ${TESTBED_SRC_DIR}/basic_app/game.cpp
  ${TESTBED_SRC_DIR}/basic_app/main.cpp
)

add_executable(${PROJECT_NAME} ${TEST_SRC})

file(COPY ${CMAKE_PREFIX_PATH}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(${PROJECT_NAME} PUBLIC ${GILG_HEADER_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${GILG_LIBS_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC ${GILG_LIB} ${glfw})
