#include "game/game.h"
#include <GLFW/glfw3.h>
#include <LZ/maths.h>
#include <LZ/display.h>
#include <LZ/camera.h>
#include <LZ/input.h>
#include <LZ/timer.h>

using namespace lz::maths;

int main(int argc, char **argv)
{
	lz::display display = lz::display("THUG !", 1280, 720);
	lz::shader 	shader  = lz::shader("data/shaders/main.vert", "data/shaders/main.frag");
	lz::camera	camera  = lz::camera(vec3(0, 0, 0));
	lz::input	input   = lz::input(display.getWindow());

	Game 		*game = new Game();

	double updatedTime = 0;
	lz::timer	timer = lz::timer();
	int frames;
	int ticks;

	while (!display.isClosed())
	{
		if (timer.elapsed() - updatedTime >= 16.666666666667)
		{
			camera.control(&input, 0.1);
			game->update(&input, &camera);
			updatedTime += 16.666666666667;
			ticks++;
			if (ticks % 60 == 0)
			{
				std::cout << "fps: " << frames << std::endl;
				frames = 0;
				ticks = 0;
			}
		}
		else
		{
			input.updateMouseMovement(&display);
			camera.update();
			camera.mouseLook(&input, 0.35);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			camera.perspective(70.0, display.getWidth(), display.getHeight(), 0.1, 1000.0);
			shader.bind();
			shader.setUniform((char*)"projectionMatrix", camera.getProjectionMatrix());
			shader.setUniform((char*)"viewMatrix", camera.getViewMatrix());

			game->render(&shader);

			display.update();
			if (display.wasResized())
				glViewport(0, 0, display.getWidth(), display.getHeight());
			frames++;	
		}
	}

	delete game;
	return (0);
}
