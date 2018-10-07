#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec4 Color;

out VS_OUT {
    vec4 Color;
} vs_out;

void main() {
    vs_out.Color = Color;
    gl_Position = vec4(Position, 1);
}