#ifndef GAME_H
# define GAME_H

# include <LZ/shader.h>
# include <GL/glew.h>

class Game
{
private:
	GLuint vao, vbo, ibo;
public:
	Game();
	~Game();

	void update();
	void render(lz::shader *shader);
};

#endif
