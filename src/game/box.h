#ifndef BOX_H
# define BOX_H

# include <LZ/maths.h>
# include <LZ/transform.h>
# include <LZ/shader.h>
# include <LZ/physics.h>
# include <LZ/mesh.h>
# include <GL/glew.h>
# include <LZ/buffers.h>

class Box
{
private:
	lz::Transform m_transform;
	lz::maths::vec3 m_force;
	GLuint m_vao, m_vbo, m_nbo, m_ibo;
	GLfloat m_vertices[6 * 4 * 3] = {
		-1, -1, -1,
		1, -1, -1,
		1, -1, 1,
		-1, -1, 1,

		-1, 1, -1,
		1, 1, -1,
		1, 1, 1,
		-1, 1, 1,

		-1, -1, -1,
		1, -1, -1,
		1, 1, -1,
		-1, 1, -1,

		-1, -1, 1,
		1, -1, 1,
		1, 1, 1,
		-1, 1, 1,

		-1, -1, -1,
		-1, 1, -1,
		-1, 1, 1,
		-1, -1, 1,

		1, -1, -1,
		1, 1, -1,
		1, 1, 1,
		1, -1, 1
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
		0, 2, 1, 0, 3, 2,
		4, 5, 6, 4, 6, 7,
		8, 9, 10, 8, 10, 11,
		12, 14, 13, 12, 15, 14,
		16, 17, 18, 16, 18, 19,
		20, 22, 21, 20, 23, 22
	};

	lz::Mesh 	*m_mesh;
	btRigidBody *m_rigidBody;

public:
	Box(lz::Transform transform, float mass);
	~Box();

	void update();
	void render(lz::Shader *shader);

	inline btRigidBody *getBody() { return (m_rigidBody); }
};

#endif
