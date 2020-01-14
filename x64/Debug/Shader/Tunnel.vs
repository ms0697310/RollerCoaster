#version 430 core
uniform mat4 ModelViewMatrix;
uniform mat4 ProjectionMatrix;

layout (location = 0) in vec4 position;
layout (location = 1) in vec3 normal;

out vec3 vs_worldpos;
out vec3 vs_normal;

void main(void)
{
	vec4 position = ProjectionMatrix * ModelViewMatrix * position;
	gl_Position = position;
	vs_worldpos = position.xyz;
	vs_normal = mat3(ModelViewMatrix) * normal;
}