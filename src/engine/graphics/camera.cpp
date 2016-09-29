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

void camera::update()
{
	maths::mat4 translation_matrix = maths::mat4::translate(m_transform.getPosition());
	maths::mat4 rotation_matrix = maths::mat4::cameraView(m_transform.getForward(), m_transform.getUp());
	m_view_matrix = translation_matrix.mul(rotation_matrix);
}

void camera::perspective(float fov, float w, float h, float near, float far)
{
	m_projection_matrix = maths::mat4::perspective(fov, w / h, near, far);
}
