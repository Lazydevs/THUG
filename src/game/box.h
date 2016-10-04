#ifndef BOX_H
# define BOX_H

# include <LZ/maths.h>
# include <LZ/transform.h>
# include <LZ/shader.h>
# include <GL/glew.h>

class Box
{
private:
	lz::transform m_transform;
	lz::maths::vec3 m_force;
	GLuint m_vao, m_vbo, m_nbo, m_ibo;
	GLfloat m_vertices[6 * 4 * 3] = {
		0, 0, 0,
		1, 0, 0,
		1, 0, 1,
		0, 0, 1,

		0, 1, 0,
		1, 1, 0,
		1, 1, 1,
		0, 1, 1,

		0, 0, 0,
		1, 0, 0,
		1, 1, 0,
		0, 1, 0,

		0, 0, 1,
		1, 0, 1,
		1, 1, 1,
		0, 1, 1,

		0, 0, 0,
		0, 1, 0,
		0, 1, 1,
		0, 0, 1,

		1, 0, 0,
		1, 1, 0,
		1, 1, 1,
		1, 0, 1
	};
	GLfloat m_normals[6 * 4 * 3] = {
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,

		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,

		0, 0, -1,
		0, 0, -1,
		0, 0, -1,
		0, 0, -1,

		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,

		-1, 0, 0,
		-1, 0, 0,
		-1, 0, 0,
		-1, 0, 0,

		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0
	};
	GLuint m_indices[6 * 6] = {
		0, 1, 2, 0, 2, 3,
		4, 5, 6, 4, 6, 7,
		8, 9, 10, 8, 10, 11,
		12, 13, 14, 12, 14, 15,
		16, 17, 18, 16, 18, 19,
		20, 21, 22, 20, 22, 23
	};

public:
	Box(lz::transform transform);
	Box(lz::transform transform, lz::maths::vec3 force);
	~Box();

	void update();
	void render(lz::shader *shader);

	inline void setForce(lz::maths::vec3 force) { m_force = force; }
};

#endif
