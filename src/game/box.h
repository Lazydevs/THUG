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
	GLuint m_vao, m_vbo, m_ibo;
	GLfloat m_vertices[8 * 3] = {
		0, 0, 0,
		1, 0, 0,
		1, 0, 1,
		0, 0, 1,

		0, 1, 0,
		1, 1, 0,
		1, 1, 1,
		0, 1, 1
	};
	GLuint m_indices[6 * 6] = {
		0, 1, 2, 0, 2, 3,
		1, 5, 6, 1, 6, 2,
		5, 4, 7, 5, 7, 6,
		4, 0, 3, 4, 3, 7,
		1, 0, 4, 1, 4, 5,
		3, 2, 6, 3, 6, 7
	};

public:
	Box(lz::transform transform);
	~Box();

	void update();
	void render(lz::shader *shader);

	inline void setForce(lz::maths::vec3 force) { m_force = force; }
};

#endif
