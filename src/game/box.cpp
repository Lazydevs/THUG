#include "box.h"

Box::Box(lz::transform transform)
{
	m_transform = transform;

	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_nbo);
	glGenBuffers(1, &m_ibo);

	glBindVertexArray(m_vao);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_nbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_normals), m_normals, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
}


Box::Box(lz::transform transform, lz::maths::vec3 force)
{
	m_transform = transform;
	m_force = force;

	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_nbo);
	glGenBuffers(1, &m_ibo);

	glBindVertexArray(m_vao);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_vertices), m_vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_nbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_normals), m_normals, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_indices), m_indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
}

Box::~Box()
{

}

void Box::update()
{
	if(m_transform.getPosition().y > 1){
		m_force.add(0, -10, 0);
		m_transform.translate(m_force, 0.0005);
	}
}

void Box::render(lz::shader *shader)
{
	shader->setUniform((char *)"modelMatrix", m_transform.toMatrix());
	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
