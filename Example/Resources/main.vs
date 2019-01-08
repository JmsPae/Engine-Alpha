#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec4 Color;

uniform float Timer;
uniform mat4 Transform;

out VS_OUT {
    vec4 Color;
} vs_out;

void main() {
    vs_out.Color = vec4(Color.r * sin(Timer)*0.5+0.5, Color.g * cos(Timer)*0.5+0.5, Color.b * sin(Timer)*0.5+0.5, Color.a);
    gl_Position = Transform * vec4(Position, 1);
}