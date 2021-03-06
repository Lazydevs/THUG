#include <LZ/mesh.h>
#include <LZ/buffers.h>
#include <LZ/error.h>
#include <stdio.h>

using namespace lz;

Mesh::Mesh(GLfloatBuffer positions, GLfloatBuffer normals, GLuintBuffer indices, int size)
{
	m_positions = positions;
	m_normals = normals;
	m_indices = indices;
	m_size = size;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_nbo);
	glDeleteBuffers(1, &m_ibo);
}

void Mesh::create()
{
	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_nbo);
	glGenBuffers(1, &m_ibo);

	glBindVertexArray(m_vao);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, m_positions.size, m_positions.buffer, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_nbo);
	glBufferData(GL_ARRAY_BUFFER, m_normals.size, m_normals.buffer, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size, m_indices.buffer, GL_STATIC_DRAW);

	glBindVertexArray(0);
}

void Mesh::draw()
{
	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, m_size, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}