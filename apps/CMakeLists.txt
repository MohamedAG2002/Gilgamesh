cmake_minimum_required(VERSION 3.27)
project(testbed)

set(CMAKE_PREFIX_PATH "/home/mohamed/Dev/C++/GilgameshEngine/")
set(TESTBED_SRC_DIR ${CMAKE_SOURCE_DIR})

find_library(glfw glfw REQUIRED)

set(TEST_SRC
  # Core test
  ${TESTBED_SRC_DIR}/basic_app/main.cpp
)

add_executable(${PROJECT_NAME} ${TEST_SRC})

file(COPY ${CMAKE_PREFIX_PATH}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_PREFIX_PATH}/src/gilgamesh)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_PREFIX_PATH}/libs/include)
target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_PREFIX_PATH}/build/libgilgamesh.a ${glfw})
