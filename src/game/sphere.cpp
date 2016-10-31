#include "sphere.h"
#include <iostream>
#include <LZ/error.h>

using namespace lz;

Sphere::Sphere(Transform transform, float mass)
{
	m_transform = transform;
	ObjLoader *obj = new ObjLoader((char *)"data/models/ball.obj");
	m_mesh = obj->getMesh();
	//delete obj;
	//m_mesh->create();
	
	btTransform t;
	t.setIdentity();
	t.setOrigin(btVector3(m_transform.getPosition().x, m_transform.getPosition().y, m_transform.getPosition().z));
	t.setRotation(btQuaternion(m_transform.getRotation().x, m_transform.getRotation().y, m_transform.getRotation().z, m_transform.getRotation().w));
	
	btSphereShape *boxShape = new btSphereShape(transform.getScale().x);
	btVector3 inertia(0, 0, 0);
	if (mass != 0)
		boxShape->calculateLocalInertia(mass, inertia);
	btDefaultMotionState *motionState = new btDefaultMotionState(t);
	btRigidBody::btRigidBodyConstructionInfo bodyInfo(mass, motionState, boxShape, inertia);
	m_rigidBody = new btRigidBody(bodyInfo);

	if (mass != 0)
	{
		m_rigidBody->applyCentralForce(btVector3(m_transform.getForward().x * 500, m_transform.getForward().y * 500, m_transform.getForward().z * 500));
		m_rigidBody->setFriction(15);
	}
}

Sphere::~Sphere()
{
	delete m_rigidBody;
	delete m_mesh;
}

void Sphere::update()
{
	btTransform t;
	m_rigidBody->getMotionState()->getWorldTransform(t);
	m_transform.setPosition(vec3(t.getOrigin().getX(), t.getOrigin().getY(), t.getOrigin().getZ()));
	m_transform.setRotation(quat(t.getRotation().getX(), t.getRotation().getY(), t.getRotation().getZ(), t.getRotation().getW()));
}

void Sphere::render(Shader *shader)
{
	shader->setUniform((char *)"modelMatrix", m_transform.toMatrix());
	m_mesh->draw();
}
