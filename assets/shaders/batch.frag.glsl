#version 460 core 

// Outputs 
out vec4 frag_color;

// Inputs
in VS_OUT 
{
  vec4 out_color; 
  vec2 tex_coords;
  float tex_index;
} fs_in;

// Uniforms
uniform sampler2D u_textures[32];

void main() 
{
  int index = int(fs_in.tex_index);
  frag_color = texture(u_textures[index], fs_in.tex_coords) * fs_in.out_color;
}
