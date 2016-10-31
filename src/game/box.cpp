#include "box.h"
#include <iostream>

using namespace lz;

Box::Box(Transform transform, float mass)
{
	m_transform = transform;

	GLfloatBuffer vertices = {sizeof(m_vertices), m_vertices};
	GLfloatBuffer normals = {sizeof(m_normals), m_normals};
	GLuintBuffer indices = {sizeof(m_indices), m_indices};
	
	ObjLoader obj((char *)"data/models/ball.obj");//new Mesh(vertices, normals, indices, 6*6);
	m_mesh = obj.getMesh();
	m_mesh->create();
	
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
	delete m_mesh;
}

void Box::update()
{
	btTransform t;
	m_rigidBody->getMotionState()->getWorldTransform(t);
	m_transform.setPosition(vec3(t.getOrigin().getX(), t.getOrigin().getY(), t.getOrigin().getZ()));
	m_transform.setRotation(quat(t.getRotation().getX(), t.getRotation().getY(), t.getRotation().getZ(), t.getRotation().getW()));
}

void Box::render(Shader *shader)
{
	shader->setUniform((char *)"modelMatrix", m_transform.toMatrix());
	m_mesh->draw();
}
