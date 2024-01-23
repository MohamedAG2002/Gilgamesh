#version 460 core 

// Layouts 
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTextureCoords;

// Outputs
out vec2 texture_coords;

void main() 
{
  texture_coords = aTextureCoords;
  gl_Position = vec4(aPos, 1.0f);
}
