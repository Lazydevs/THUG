#include "box.h"
#include <iostream>

Box::Box(lz::transform transform, float mass)
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

	
	btTransform t;
	t.setIdentity();
	t.setOrigin(btVector3(m_transform.getPosition().x, m_transform.getPosition().y, m_transform.getPosition().z));
	t.setRotation(btQuaternion(m_transform.getRotation().x, m_transform.getRotation().y, m_transform.getRotation().z, m_transform.getRotation().w));
	
	btBoxShape *boxShape = new btBoxShape(btVector3(transform.getScale().x, transform.getScale().y, transform.getScale().z));
	btVector3 inertia(0, 0, 0);
	if (mass != 0)
		boxShape->calculateLocalInertia(mass, inertia);
	btDefaultMotionState *motionState = new btDefaultMotionState(t);
	btRigidBody::btRigidBodyConstructionInfo bodyInfo(mass, motionState, boxShape, inertia);
	m_rigidBody = new btRigidBody(bodyInfo);

	if (mass != 0)
	{
		m_rigidBody->applyCentralForce(btVector3(m_transform.getForward().x * 500, m_transform.getForward().y * 500, m_transform.getForward().z * 500));
		m_rigidBody->setFriction(2);
	}
}

Box::~Box()
{
	delete m_rigidBody;
}

void Box::update()
{
	btTransform t;
	m_rigidBody->getMotionState()->getWorldTransform(t);
	m_transform.setPosition(vec3(t.getOrigin().getX(), t.getOrigin().getY(), t.getOrigin().getZ()));
	m_transform.setRotation(quat(t.getRotation().getX(), t.getRotation().getY(), t.getRotation().getZ(), t.getRotation().getW()));
}

void Box::render(lz::shader *shader)
{
	shader->setUniform((char *)"modelMatrix", m_transform.toMatrix());
	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
