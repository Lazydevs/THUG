#ifndef DISPLAY_H
# define DISPLAY_H

# include <iostream>
# include <GL/glew.h>
# include <GLFW/glfw3.h>
// # define NK_INCLUDE_FIXED_TYPES
// # define NK_INCLUDE_STANDARD_IO
// # define NK_INCLUDE_STANDARD_VARARGS
// # define NK_INCLUDE_DEFAULT_ALLOCATOR
// # define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
// # define NK_INCLUDE_FONT_BAKING
// # define NK_INCLUDE_DEFAULT_FONT
// # define NK_IMPLEMENTATION
// # define NK_GLFW_GL3_IMPLEMENTATION
// # include <NK/nuklear.h>
// # include <NK/nuklear_init.h>

namespace lz
{
	class Display
	{
	private:
	    GLFWwindow *m_window;
		// struct nk_context *m_nkCtx;
		// struct nk_font_atlas *m_nkAtlas;

	    std::string m_title;

	    int m_width;
	    int m_height;

	    int m_last_width;
	    int m_last_height;

	    bool m_resized;
	    bool m_closed;

	    void create(const char *title, int width, int height);

	public:
	    Display(const char *title, int width, int height);
	    ~Display();

	    void update();

	    void setTitle(const char* title);
	    const char *getTitle();

	    inline GLFWwindow *getWindow() { return m_window; };

	    inline int getWidth() { return m_width; };
	    inline int getHeight() { return m_height; };

	    inline bool wasResized() { return m_resized; };
	    inline bool isClosed() { return m_closed; };

		// inline struct nk_context *getNkContext() { return m_nkCtx; }
		// inline struct nk_font_atlas *getNkAtlas() { return m_nkAtlas; }
	};
}
#endif
