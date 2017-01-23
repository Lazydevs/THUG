#ifndef SPACESHIP_H
# define SPACESHIP_H

# include <LZ/maths.h>
# include <LZ/transform.h>
# include <LZ/shader.h>
# include <LZ/mesh.h>
# include <LZ/resources.h>

#include "../entity.h"

class Spaceship : public Entity 
{
public:
	Spaceship(long id, Transform trs);
	~Spaceship();

	void update();
	void render(Shader *shader);
};

#endif