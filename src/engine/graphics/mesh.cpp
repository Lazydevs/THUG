#include <LZ/mesh.h>

using namespace lz;

Mesh::Mesh(GLfloat *positions, GLfloat *normals, GLuint *indices, int size)
{
	m_positions = positions;
	m_normals = normals;
	m_indices = indices;
	m_size = size;
}

Mesh::~Mesh()
{

}

void Mesh::create()
{
	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);

	glBindVertexArray(m_vao);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_positions), m_positions, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_nbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_normals), m_normals, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
}

void Mesh::draw()
{
	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}