#include "game/game.h"
#include <GLFW/glfw3.h>
#include <LZ/maths.h>
#include <LZ/display.h>
#include <LZ/camera.h>
#include <LZ/input.h>
#include <LZ/timer.h>
#include <LZ/string_utils.h>
#include <stdlib.h>

# define NK_INCLUDE_FIXED_TYPES
# define NK_INCLUDE_STANDARD_IO
# define NK_INCLUDE_STANDARD_VARARGS
# define NK_INCLUDE_DEFAULT_ALLOCATOR
# define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
# define NK_INCLUDE_FONT_BAKING
# define NK_INCLUDE_DEFAULT_FONT
# define NK_IMPLEMENTATION
# define NK_GLFW_GL3_IMPLEMENTATION
# include <NK/nuklear.h>
# include <NK/nuklear_init.h>

using namespace lz::maths;

int main(int argc, char **argv)
{
	lz::Display display	= lz::Display("The Huge Unbelivable Galaxy or THUG !", 1280, 720);
	lz::Shader 	shader	= lz::Shader("data/shaders/main.vert", "data/shaders/main.frag");
	lz::Camera	camera	= lz::Camera(vec3(0, 0, 0));
	lz::Input	input	= lz::Input(display.getWindow());
	lz::Timer timer		= lz::Timer();

	Game 		*game = new Game(&input, &camera);

	double updatedTime	= 0;
	int frames;
	int ticks;

	frames = 0;
	ticks = 0;
	while (!display.isClosed())
	{
		if (timer.elapsed() - updatedTime >= 16.666666666667)
		{
			if (input.getKey(GLFW_KEY_ESCAPE))
				return (0);
			camera.control(&input, 0.1);
			game->update();
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

			//nk_glfw3_render(NK_ANTI_ALIASING_ON, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER);

			display.update();
			if (display.wasResized())
				glViewport(0, 0, display.getWidth(), display.getHeight());
			frames++;
		}
	}

	delete game;
	return (0);
}
