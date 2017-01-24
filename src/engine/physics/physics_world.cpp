#include <LZ/physics.h>
#include <LZ/maths.h>

using namespace lz;
using namespace maths;
using namespace physics;

PhysicsWorld::PhysicsWorld(vec3 gravity)
{
    m_broadphase = new btDbvtBroadphase();
    m_collisionConfiguration = new btDefaultCollisionConfiguration();
    m_dispatcher = new btCollisionDispatcher(m_collisionConfiguration);
    m_solver = new btSequentialImpulseConstraintSolver;
    m_dynamicsWorld = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver, m_collisionConfiguration);
    m_dynamicsWorld->setGravity(btVector3(gravity.x, gravity.y, gravity.z));
}

PhysicsWorld::~PhysicsWorld()
{
    delete m_broadphase;
    delete m_collisionConfiguration;
    delete m_dispatcher;
    delete m_solver;
    delete m_dynamicsWorld;
}

void PhysicsWorld::addBody(btRigidBody *body)
{
    m_dynamicsWorld->addRigidBody(body);
}

void PhysicsWorld::removeBody(btRigidBody *body)
{
    m_dynamicsWorld->removeCollisionObject(body);
}

void PhysicsWorld::update(float step)
{
    m_dynamicsWorld->stepSimulation(step);
}