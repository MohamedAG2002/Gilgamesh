#version 460 core 

// Outputs 
out vec4 frag_color;

// Inputs
in VS_OUT 
{
  vec4 out_color; 
  vec2 tex_coords;
} fs_in;

void main() 
{
  frag_color = fs_in.out_color;
}
