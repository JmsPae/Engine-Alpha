#version 330 core

out vec4 Color;

in VS_OUT {
    vec4 Color;
    vec2 Uv;
} fs_in;

uniform sampler2D Texture;

void main() {
    Color = vec4(fs_in.Color) * texture(Texture, fs_in.Uv);
}