#include <LZ/maths.h>

using namespace lz;
using namespace maths;

quat::quat()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
	m_w = 1;
}

quat::quat(quat* q)
{
	m_x = q->m_x;
	m_y = q->m_y;
	m_z = q->m_z;
	m_w = q->m_w;
}

quat::quat(float x, float y, float z, float w)
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_w = w;
}

void quat::set(float x, float y, float z, float w)
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_w = w;
}

quat::quat(vec3 axis, float angle)
{
	float s = SIN(angle / 2.0f);
	float c = COS(angle / 2.0f);

	m_x = axis.m_x * s;
	m_y = axis.m_y * s;
	m_z = axis.m_z * s;
	m_w = c;
}

float quat::magnitude()
{
	return (SQRT(m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w));
}

quat quat::normalize()
{
	quat result;
	float mag = magnitude();
	result.set(m_x / mag, m_y / mag, m_z / mag, m_w / mag);

	return (result);
}

quat quat::conjugate()
{
	quat result;
	result.set(-m_x, -m_y, -m_z, m_w);

	return (result);
}

quat quat::mul(quat r)
{
	quat result;

	result.m_w = m_w * r.m_w - m_x * r.m_x - m_y * r.m_y - m_z * r.m_z;
	result.m_x = m_x * r.m_w + m_w * r.m_x + m_y * r.m_z - m_z * r.m_y;
	result.m_y = m_y * r.m_w + m_w * r.m_y + m_z * r.m_x - m_x * r.m_z;
	result.m_z = m_z * r.m_w + m_w * r.m_z + m_x * r.m_y - m_y * r.m_x;

	return (result);
}

quat quat::mul(vec3 r)
{
	quat result;

	result.m_w = -m_x * r.m_x - m_y * r.m_y - m_z * r.m_z;
	result.m_x = m_w * r.m_x + m_y * r.m_z - m_z * r.m_y;
	result.m_y = m_w * r.m_y + m_z * r.m_x - m_x * r.m_z;
	result.m_z = m_w * r.m_z + m_x * r.m_y - m_y * r.m_x;

	return (result);
}

float quat::dot(quat r)
{
	return (m_x * r.m_x + m_y * r.m_y + m_z * r.m_z + m_w * r.m_w);
}

mat4 quat::to_matrix()
{
	vec3 forward(2.0f * (m_x * m_z - m_w * m_y), 2.0f * (m_y * m_z + m_w * m_x), 1.0f - 2.0f * (m_x * m_x + m_y * m_y));
	vec3 up(2.0f * (m_x * m_y + m_w * m_z), 1.0f - 2.0f * (m_x * m_x + m_z * m_z), 2.0f * (m_y * m_z - m_w * m_x));
	vec3 right(1.0f - 2.0f * (m_y * m_y + m_z * m_z), 2.0f * (m_x * m_y - m_w * m_z), 2.0f * (m_x * m_z + m_w * m_y));

	return (mat4::rotate(forward, up, right));
}

vec3 quat::get_forward()
{
	vec3 result(0, 0, 1);
	result = result.rotate(this);

	return (result);
}

vec3 quat::get_back()
{
	vec3 result(0, 0, -1);
	result = result.rotate(this);

	return (result);
}

vec3 quat::get_right()
{
	vec3 result(1, 0, 0);
	result = result.rotate(this);

	return (result);
}

vec3 quat::get_left()
{
	vec3 result(-1, 0, 0);
	result = result.rotate(this);

	return (result);
}

vec3 quat::get_up()
{
	vec3 result(0, 1, 0);
	result = result.rotate(this);

	return (result);
}

vec3 quat::get_down()
{
	vec3 result(0, -1, 0);
	result = result.rotate(this);

	return (result);
}
