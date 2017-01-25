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

#define MAX_VERTEX_BUFFER 512 * 1024
#define MAX_ELEMENT_BUFFER 128 * 1024

# include <NK/nuklear.h>
# include <NK/nuklear_init.h>

using namespace lz::maths;

int main(int argc, char **argv)
{
	lz::Display display	= lz::Display("The Huge Unbelivable Galaxy or THUG !", 1280, 720);
	lz::Shader 	shader	= lz::Shader("data/shaders/main.vert", "data/shaders/main.frag");
	lz::Camera	camera	= lz::Camera(vec3(0, 0, 0));
	lz::Input	input	= lz::Input(display.getWindow());
	lz::Timer 	timer	= lz::Timer();

	Game 		*game = new Game(&input, &camera);


	struct nk_context *ctx;
    struct nk_color background;
	ctx = nk_glfw3_init(display.getWindow(), NK_GLFW3_INSTALL_CALLBACKS);
    struct nk_font_atlas *atlas;
    nk_glfw3_font_stash_begin(&atlas);
    nk_glfw3_font_stash_end();
	background = nk_rgb(28,48,62);

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
			nk_glfw3_new_frame();

			if (nk_begin(ctx, "Demo", nk_rect(50, 50, 230, 250),
	            NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
	            NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
	        {
	            enum {EASY, HARD};
	            static int op = EASY;
	            static int property = 20;
	            nk_layout_row_static(ctx, 30, 80, 1);
	            if (nk_button_label(ctx, "button"))
	                fprintf(stdout, "button pressed\n");

	            nk_layout_row_dynamic(ctx, 30, 2);
	            if (nk_option_label(ctx, "easy", op == EASY)) op = EASY;
	            if (nk_option_label(ctx, "hard", op == HARD)) op = HARD;

	            nk_layout_row_dynamic(ctx, 25, 1);
	            nk_property_int(ctx, "Compression:", 0, &property, 100, 10, 1);

	            nk_layout_row_dynamic(ctx, 20, 1);
	            nk_label(ctx, "background:", NK_TEXT_LEFT);
	            nk_layout_row_dynamic(ctx, 25, 1);
	            if (nk_combo_begin_color(ctx, background, nk_vec2(nk_widget_width(ctx),400))) {
	                nk_layout_row_dynamic(ctx, 120, 1);
	                background = nk_color_picker(ctx, background, NK_RGBA);
	                nk_layout_row_dynamic(ctx, 25, 1);
	                background.r = (nk_byte)nk_propertyi(ctx, "#R:", 0, background.r, 255, 1,1);
	                background.g = (nk_byte)nk_propertyi(ctx, "#G:", 0, background.g, 255, 1,1);
	                background.b = (nk_byte)nk_propertyi(ctx, "#B:", 0, background.b, 255, 1,1);
	                background.a = (nk_byte)nk_propertyi(ctx, "#A:", 0, background.a, 255, 1,1);
	                nk_combo_end(ctx);
	            }
	        }
	        nk_end(ctx);

			nk_glfw3_render(NK_ANTI_ALIASING_ON, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER);

			display.update();
			if (display.wasResized())
				glViewport(0, 0, display.getWidth(), display.getHeight());
			frames++;
		}
	}
	nk_glfw3_shutdown();
	delete game;
	return (0);
}
