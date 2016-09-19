#version 330

layout(location = 0) in vec3 in_position;

out vec3 v_position;

uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;

void main()
{
	v_position = in_position;
	gl_Position = projectionMatrix * modelViewMatrix * vec4(in_position, 1.0);
}
