#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec4 Color;
layout (location = 2) in vec2 Uv;

uniform float Timer;
uniform mat4 Transform;
uniform mat4 View;
uniform mat4 Projection;

out VS_OUT {
    vec4 Color;
    vec2 Uv;
} vs_out;

void main() {
    vs_out.Color = Color;
    vs_out.Uv = Uv;
    gl_Position = Projection * View * Transform * vec4(Position * vec3(1, -1, 1), 1);
}