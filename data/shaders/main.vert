#version 330

layout(location = 0) in vec3 in_position;

out vec3 v_position;
out vec3 viewPosition;
out vec3 worldPosition;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

void main()
{
	v_position = in_position;
	viewPosition = (viewMatrix * modelMatrix * vec4(in_position, 1.0)).xyz;
	worldPosition = (modelMatrix * vec4(in_position, 1.0)).xyz;
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_position, 1.0);
}
