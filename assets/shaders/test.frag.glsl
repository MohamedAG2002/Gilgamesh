#version 460 core 

// Outputs 
out vec4 frag_color;

// Inputs 
in vec2 texture_coords;

// Uniforms 
uniform sampler2D tex;

void main() 
{
  frag_color = vec4(1.0f);
}
