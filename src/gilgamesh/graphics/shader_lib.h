#pragma once

#include "gilgamesh/core/defines.h"
#include "gilgamesh/resources/shader.h"

#include <string>

namespace gilg {

// Shader Lib functions
///////////////////////////////////////////////////
// Handles the initialization of the shader library. It takes a 
// path to where all of the shaders exist. Any subsequent shader that 
// will be added to the library will be prefixed with this path. 
b8 shader_lib_init(const std::string& path_prefix);

// Handles the shutdown of the shader library and frees any memory 
// it has allocated prior.
void shader_lib_shutdown();

// Add a shader to the library given an ID to identify the shader with 
// (to retrieve it later) and the name of the shader file. 
// NOTE: This function takes the name of the shader file and 
// NOT the full path to the shader. Just the name with the extension
void shader_lib_add(const std::string& id, const std::string& shader_file);

// Removes the shader from the library. Returns true if the removal was 
// successful and false otherwise 
b8 shader_lib_remove(const std::string& id);

// Retrieves the shader from the library given its id. 
// NOTE: The function will assert if the shader it is looking for 
// does not exist. Make sure to give it the right ID.
shader* shader_lib_get(const std::string& id);
///////////////////////////////////////////////////

}
