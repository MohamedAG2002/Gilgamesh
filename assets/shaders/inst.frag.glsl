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
  frag_color = texture(tex, fs_in.texture_coords);
}
