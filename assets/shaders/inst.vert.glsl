#version 460 core 

// Layouts
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTextureCoords;
layout (location = 2) in mat4 aModel;

// Outputs
out VS_OUT 
{
  vec2 texture_coords;
} vs_out;

// Uniform block
layout(std140, binding = 0) uniform matrices 
{
  mat4 u_view_projection;
};

void main() 
{
  vs_out.texture_coords = aTextureCoords;

  gl_Position = u_view_projection * aModel * vec4(aPos, 1.0f);
}
