#version 460 core 

// Layouts 
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTextureCoords;

// Outputs
out VS_OUT 
{
  vec4 out_color; 
  vec2 tex_coords;
} vs_out;

void main() 
{
  vs_out.out_color  = aColor;
  vs_out.tex_coords = aTextureCoords;

  gl_Position = vec4(aPos, 1.0f);
}
