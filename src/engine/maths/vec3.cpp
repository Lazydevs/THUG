#include <LZ/maths.h>

using namespace lz;
using namespace maths;

vec3::vec3()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

vec3::vec3(vec3* vec)
{
	m_x = vec->m_x;
	m_y = vec->m_y;
	m_z = vec->m_z;
}

vec3::vec3(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

void vec3::set(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

float vec3::magnitude()
{
	return (SQRT(m_x * m_x + m_y * m_y + m_z * m_z));
}

vec3 vec3::normalize()
{
	vec3 result;
	float m = magnitude();
	result.set(m_x / m, m_y / m, m_z / m);

	return (result);
}

vec3 vec3::cross(vec3 r)
{
	vec3 result;

	result.m_x = m_y * r.m_z - m_z * r.m_y;
	result.m_y = m_z * r.m_x - m_x * r.m_z;
	result.m_z = m_x * r.m_y - m_y * r.m_x;

	return (result);
}

vec3 vec3::rotate(quat rot)
{
	quat w = rot.mul(this);
	w = w.mul(rot.conjugate());

	return (vec3(w.m_x, w.m_y, w.m_z));
}

float vec3::distance(vec3 a, vec3 b)
{
	return (vec3(a).sub(b).magnitude());
}

float vec3::dot(vec3 r)
{
	return (m_x * r.m_x + m_y * r.m_y + m_z * r.m_z);
}

vec3 vec3::reflect(vec3 normal)
{
	return (sub(normal.copy().mul(dot(normal) * 2.0f)));
}
