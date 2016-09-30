#include "LZ/camera.h"

using namespace lz;

camera::camera(maths::vec3 pos)
{
	m_transform = transform(pos);
}

camera::camera(maths::vec3 pos, maths::quat rot)
{
	m_transform = transform(pos, rot);
}

camera::camera(transform trs)
{
	m_transform = trs;
}

camera::~camera()
{

}

void camera::mouseLook(input *input, float speed)
{
	m_transform.rotate(maths::vec3(0, 1, 0), input->getDX() * speed);
	m_transform.rotate(m_transform.getRight(), input->getDY() * speed);
}

void camera::control(input *input, float speed)
{
	if (input->getKey(GLFW_KEY_W))
		m_transform.translate(m_transform.getForward(), speed);
	if (input->getKey(GLFW_KEY_S))
		m_transform.translate(m_transform.getForward(), -speed);
	if (input->getKey(GLFW_KEY_A))
		m_transform.translate(m_transform.getRight(), -speed);
	if (input->getKey(GLFW_KEY_D))
		m_transform.translate(m_transform.getRight(), speed);
}

void camera::update()
{
	maths::mat4 translation_matrix = maths::mat4::translate(m_transform.getPosition().mul(-1));
	maths::mat4 rotation_matrix = maths::mat4::cameraView(m_transform.getForward(), m_transform.getUp());
	m_view_matrix = rotation_matrix.mul(translation_matrix);
}

void camera::perspective(float fov, float w, float h, float near, float far)
{
	m_projection_matrix = maths::mat4::perspective(fov, w / h, near, far);
}
