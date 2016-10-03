#version 330

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec3 in_normal;

out vec3 v_position;
out vec3 v_normal;
out vec3 worldPosition;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

void main()
{
	v_position = in_position;
	v_normal = normalize((modelMatrix * vec4(in_normal, 0.0)).xyz);
	worldPosition = (modelMatrix * vec4(in_position, 1.0)).xyz;
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_position, 1.0);
}
