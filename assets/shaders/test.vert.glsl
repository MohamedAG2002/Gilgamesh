#version 460 core 

// Layouts 
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTextureCoords;

// Outputs
out vec2 texture_coords;

// Uniform block
layout(std140, binding = 0) uniform matrices 
{
  mat4 u_view_projection;
};

// Uniforms 
uniform mat4 u_model;

void main() 
{
  texture_coords = aTextureCoords;
  
  gl_Position = u_view_projection * u_model * vec4(aPos, 1.0f);
}
