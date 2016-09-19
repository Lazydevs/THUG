#include "game/game.h"
#include <LZ/display.h>

int main(int argc, char **argv)
{
	lz::display *display = new lz::display("THUG !", 1280, 720);
	Game *game = new Game();

	while (!display->is_closed())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1, 0, 1, 1);


		display->update();
		if (display->was_resized())
			glViewport(0, 0, display->get_width(), display->get_height());
	}

	delete display;
	delete game;

	return (0);
}
