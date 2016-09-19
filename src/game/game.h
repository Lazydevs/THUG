#ifndef GAME_H
# define GAME_H

# include <LZ/shader.h>

class Game
{
private:

public:
	Game();
	~Game();

	void update();
	void render(lz::shader *shader);
};

#endif
