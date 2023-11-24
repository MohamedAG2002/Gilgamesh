cmake_minimum_required(VERSION 3.27.0)
project(testbed)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ../Gilgamesh/include)
target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/libGilgamesh.so)
