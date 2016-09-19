#ifndef DISPLAY_H
# define DISPLAY_H

# include <iostream>
# include <GL/glew.h>
# include <GLFW/glfw3.h>

namespace lz
{
	class display
	{
	private:
	    GLFWwindow *m_window;

	    std::string m_title;

	    int m_width;
	    int m_height;

	    int m_last_width;
	    int m_last_height;

	    bool m_resized;
	    bool m_closed;

	    void create(const char *title, int width, int height);

	public:
	    display(const char *title, int width, int height);
	    ~display();

	    void update();

	    void set_title(const char* title);
	    const char *get_title();

	    inline GLFWwindow *get_window() { return m_window; };

	    inline int get_width() { return m_width; };
	    inline int get_height() { return m_height; };

	    inline bool was_resized() { return m_resized; };
	    inline bool is_closed() { return m_closed; };
	};
}
#endif
