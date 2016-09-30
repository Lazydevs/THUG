#include "LZ/input.h"

using namespace lz;

input::input()
{
}

input::~input()
{
}

void input::updateMouseMovement(display *display)
{
	m_window = display->getWindow();
	if (glfwGetMouseButton(m_window, 0) && !m_focused)
	{
		m_focused = true;
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
	else if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) && m_focused)
	{
		m_focused = false;
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		glfwSetCursorPos(m_window, (double) (display->getWidth() / 2), (double) (display->getHeight() / 2));
	}
	if (m_focused)
	{
		glfwGetCursorPos(display->getWindow(), &m_x, &m_y);
		m_dx = m_x - display->getWidth() / 2;
		m_dy = m_y - display->getHeight() / 2;
		glfwSetCursorPos(display->getWindow(), (double) (display->getWidth() / 2), (double) (display->getHeight() / 2));
	}
}

bool input::getKey(int key)
{
	return (glfwGetKey(m_window, key));
}

bool input::getButton(int button)
{
	return (glfwGetMouseButton(m_window, button));
}
