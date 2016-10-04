#version 330
#define LIGHT_COUNT 5

in vec3 v_position;
in vec3 v_normal;

in vec3 worldPosition;
out vec4 out_color;

struct s_light
{
	vec3 pos;
	vec3 color;
};

s_light lights[LIGHT_COUNT];

void main()
{
	lights[0].pos = vec3(5, 1.5, 5);
	lights[0].color = vec3(1, 0.6, 0.3);

	lights[1].pos = vec3(25, 1.5, 5);
	lights[1].color = vec3(1, 1, 1);

	vec3 light = vec3(0, 0, 0);

	for (int i = 0; i < 2; i++)
	{
		float diffuseFactor = dot(normalize(lights[i].pos - worldPosition), v_normal);
		float lightDistance = distance(worldPosition, lights[i].pos);
		float lightFactor = max(1.0 / lightDistance * diffuseFactor, 0);
		light += lights[i].color * lightFactor;
	}

	out_color = vec4(light + vec3(0.5, 0.7, 1) * 0.1, 1);
}
