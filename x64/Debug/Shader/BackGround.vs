#version 330 core
layout (location = 0) in vec4 aPos;

out vec3 TexCoords;

uniform mat4 ModelViewMatrix;
uniform mat4 ProjectionMatrix;

void main()
{
    TexCoords = aPos.xyz;
    gl_Position = ProjectionMatrix * ModelViewMatrix * aPos;
}  