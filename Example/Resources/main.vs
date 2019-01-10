#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec4 Color;

uniform float Timer;
uniform mat4 Transform;
uniform mat4 View;
uniform mat4 Projection;

out VS_OUT {
    vec4 Color;
} vs_out;

void main() {
    vs_out.Color = Color;
    gl_Position = Projection * View * (Transform * vec4(Position, 1));
}