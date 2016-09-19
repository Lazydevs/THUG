#version 330

in vec3 v_position;

out vec4 out_color;

void main()
{
	out_color = vec4(normalize(v_position), 1.0);
}
