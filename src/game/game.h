#ifndef GAME_H
# define GAME_H

# include <LZ/shader.h>
# include <LZ/camera.h>
# include <LZ/transform.h>
# include <LZ/physics.h>
# include <GL/glew.h>
# include <iostream>
# include <vector>

# include "box.h"

class Game
{
private:
	lz::physics::PhysicsWorld *m_physicsWorld;
	Box *m_groundBox;
	std::vector<Box*> m_boxes;
	bool m_mousePressed;

public:
	Game();
	~Game();

	void update(lz::input *input, lz::camera *camera);
	void render(lz::shader *shader);
};

#endif
