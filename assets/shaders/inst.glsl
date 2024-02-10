@type vertex
#version 460 core 

// Layouts
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTextureCoords;
layout (location = 3) in mat4 aModel;

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

@type fragment 
#version 460 core 

// Outputs 
out vec4 frag_color;

// Inputs 
in VS_OUT 
{
  vec2 texture_coords;
} fs_in;

// Uniforms 
uniform sampler2D tex;

void main() 
{
  frag_color = vec4(1.0f);
}
