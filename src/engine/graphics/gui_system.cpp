#include <LZ/gui_system.h>

using namespace lz;

GuiSystem::GuiSystem(Display d)
{
	m_context = nk_glfw3_init(d.getWindow(), NK_GLFW3_INSTALL_CALLBACKS);
	nk_glfw3_font_stash_begin(&m_atlas);
	// ...
	nk_glfw3_font_stash_end();
}
