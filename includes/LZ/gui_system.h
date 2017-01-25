#ifndef GUI_SYSTEM
# define GUI_SYSTEM

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

# include <LZ/display.h>
# include <string.h>

# include <NK/nuklear.h>
# include <NK/nuklear_init.h>

namespace lz
{
	class GuiSystem
	{
	private:
		struct nk_context *m_context;
		struct nk_font_atlas *m_atlas;
	public:
		GuiSystem(Display d);
		inline struct nk_context *getContext() { return m_context; }
		inline struct nk_font_atlas *getNkAtlas() { return m_atlas; }
	};
}

#endif
