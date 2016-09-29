#include "game/game.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include <LZ/maths.h>
#include <LZ/display.h>
#include <LZ/camera.h>

using namespace lz::maths;

int main(int argc, char **argv)
{
	lz::display *display = new lz::display("THUG !", 1280, 720);
	lz::shader 	*shader = new lz::shader("data/shaders/main.vert", "data/shaders/main.frag");
	lz::camera	*camera = new lz::camera(vec3(0, 0, 0));

	Game 		*game = new Game();
	double x;
	double y;
	double dx;
	double dy;

	while (!display->isClosed())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1, 0.3, 0.7, 1);

		if (glfwGetMouseButton(display->getWindow(), 0))
		{
			glfwGetCursorPos(display->getWindow(), &x, &y);
			dx = x - display->getWidth() / 2;
			dy = y - display->getHeight() / 2;
			std::cout << dx << " - " << dy << std::endl;
			glfwSetCursorPos(display->getWindow(), (double) (display->getWidth() / 2), (double) (display->getHeight() / 2));
		}

		camera->update();
		camera->perspective(70.0, display->getWidth(), display->getHeight(), 0.1, 1000.0);
		game->update();

		shader->bind();
		shader->setUniform((char*)"projectionMatrix", camera->getProjectionMatrix());
		shader->setUniform((char*)"viewMatrix", camera->getViewMatrix());
		game->render(shader, camera);

		display->update();
		if (display->wasResized())
			glViewport(0, 0, display->getWidth(), display->getHeight());
	}

	delete display;
	delete game;

	return (0);
}
