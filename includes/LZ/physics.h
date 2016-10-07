#ifndef PHYSICS_H
# define PHYSICS_H

# include <btBulletDynamicsCommon.h>
# include <LZ/maths.h>

using namespace lz::maths;

namespace lz
{
    namespace physics
    {
        class PhysicsWorld
        {
        private:
            btBroadphaseInterface                   *m_broadphase;
            btDefaultCollisionConfiguration         *m_collisionConfiguration;
            btCollisionDispatcher                   *m_dispatcher;
            btSequentialImpulseConstraintSolver     *m_solver;
            btDiscreteDynamicsWorld                 *m_dynamicsWorld;
        
        public:
            PhysicsWorld(vec3 gravity);
            ~PhysicsWorld();
            
            void addBody(btRigidBody *body);
            void update(float step);
        };
    }
}

#endif