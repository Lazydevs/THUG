#ifndef INPUT_H
# define INPUT_H

# include "LZ/display.h"
# include <GLFW/glfw3.h>

namespace lz
{
	class input
	{
	private:
		double m_x;
		double m_y;
		double m_dx;
		double m_dy;
		double m_focused;
		GLFWwindow *m_window;

	public:
		input();
		~input();

		void update(display *display);

		bool getKey(int key);
		bool getButton(int button);

		inline double getX() { return (m_x); }
		inline double getY() { return (m_y); }
		inline double getDX() { return (m_dx); }
		inline double getDY() { return (m_dy); }
		inline bool isFocused() { return (m_focused); }
	};
}

#endif
