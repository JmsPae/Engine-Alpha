#version 330 core

out vec4 Color;

in VS_OUT {
    vec4 Color;
} fs_in;

void main() {
    Color = fs_in.Color;
}