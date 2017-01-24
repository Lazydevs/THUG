#ifndef GAME_H
# define GAME_H

# include <LZ/shader.h>
# include <LZ/camera.h>
# include <LZ/transform.h>
# include <LZ/physics.h>
# include <LZ/mesh.h>
# include <GL/glew.h>
# include <iostream>
# include <vector>

# include "box.h"
# include "sphere.h"
# include "entities/entity.h"
# include "entities/entity_manager.h"
# include "entities/spaceships/spaceship.h"

using namespace lz;
using namespace physics;

class Game
{
private:
	EntityManager				*m_entityManager;
	bool						m_mousePressed;
	Box							*m_groundBox;
	PhysicsWorld				*m_physicsWorld;
	Camera						*m_camera;
	Input						*m_input;

public:
	Game(Input *input, Camera *camera);
	~Game();

	void update();
	void render(Shader *shader);

	inline Camera *getCamera() { return m_camera; }
	inline PhysicsWorld *getPhysicsWorld() { return m_physicsWorld; }
};

#endif
