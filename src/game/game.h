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

class Game
{
private:
	EntityManager				*m_entityManager;


	bool						m_mousePressed;
	Box							*m_groundBox;
	lz::physics::PhysicsWorld	*m_physicsWorld;
	lz::Camera					*m_camera;
	lz::Input					*m_input;

public:
	Game(lz::Input *input, lz::Camera *camera);
	~Game();

	void update();
	void render(lz::Shader *shader);
};

#endif
