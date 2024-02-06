#version 460 core 

// Outputs 
out vec4 frag_color;

// Inputs
in VS_OUT 
{
  vec4 out_color; 
  vec2 tex_coords;
} fs_in;

// Uniforms
uniform sampler2D u_texture;

void main() 
{
  frag_color = texture(u_texture, fs_in.tex_coords) * fs_in.out_color;
}
