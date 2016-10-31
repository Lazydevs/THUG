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

class Game
{
private:
	lz::physics::PhysicsWorld *m_physicsWorld;
	Box *m_groundBox;
	std::vector<Sphere*> m_boxes;
	bool m_mousePressed;

public:
	Game();
	~Game();

	void update(lz::Input *input, lz::Camera *camera);
	void render(lz::Shader *shader);
};

#endif
