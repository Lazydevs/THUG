#version 330

in vec3 v_position;
in vec3 viewPosition;
in vec3 worldPosition;
out vec4 out_color;

void main()
{
	vec3 color = vec3(0.7, 0.5, 0.3);
	float fog = length(viewPosition) * 0.2 + 1;
	float light = distance(worldPosition, vec3(5, 2, 5)) / 5;
	out_color = vec4(color / light / fog, 1);
}
