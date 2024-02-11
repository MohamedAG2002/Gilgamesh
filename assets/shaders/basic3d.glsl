@type vertex
#version 460 core 

// Layouts 
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTextureCoords;

// Outputs 
out VS_OUT 
{
  vec2 texture_coords;
} vs_out;

// Uniforms 
layout(std140, binding = 0) uniform matrices 
{
  mat4 u_view_projection;
};
uniform mat4 u_model;

void main() 
{
  vs_out.texture_coords = aTextureCoords;
  gl_Position = u_view_projection * u_model * vec4(aPos, 1.0f);
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

uniform vec4 u_color;
uniform sampler2D u_texture;

void main() 
{
  frag_color = texture(u_texture, fs_in.texture_coords);
}
