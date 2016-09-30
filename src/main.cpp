#include "game/game.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include <LZ/maths.h>
#include <LZ/display.h>
#include <LZ/camera.h>
#include <LZ/input.h>

using namespace lz::maths;

int main(int argc, char **argv)
{
	lz::display *display = new lz::display("THUG !", 1280, 720);
	lz::shader 	*shader = new lz::shader("data/shaders/main.vert", "data/shaders/main.frag");
	lz::camera	*camera = new lz::camera(vec3(0, 0, 0));
	lz::input	*input = new lz::input();

	Game 		*game = new Game();

	while (!display->isClosed())
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		input->update(display);

		camera->update();
		camera->perspective(70.0, display->getWidth(), display->getHeight(), 0.1, 1000.0);
		camera->control(input, 0.01, 0.35);
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
	delete camera;

	return (0);
}
