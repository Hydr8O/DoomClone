#version 330 core

in vec2 tex_coord;

out vec4 out_color;


uniform sampler2D ourTexture;
uniform sampler2D ourTexture2;
void main() {
    out_color = mix(texture(ourTexture, tex_coord), texture(ourTexture2, vec2(-tex_coord.x, tex_coord.y)), 0.5);
};
