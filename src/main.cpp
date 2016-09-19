#include "game/game.h"
#include <LZ/display.h>

int main(int argc, char **argv)
{
	lz::display *display = new lz::display("THUG !", 1280, 720);
	Game 		*game = new Game();
	lz::shader 	*shader = new lz::shader("data/shaders/main.vert", "data/shaders/main.frag");

	while (!display->is_closed())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1, 0.3, 0.7, 1);

		game->update();
		game->render(shader);

		display->update();
		if (display->was_resized())
			glViewport(0, 0, display->get_width(), display->get_height());
	}

	delete display;
	delete game;

	return (0);
}
