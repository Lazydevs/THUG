#ifndef MATH_H
# define MATH_H

# include <math.h>

# define PI 3.14159265358979323846264338327950288419716939937510582f

# define TO_RADIANS(x) (float) (x * PI / 180.0f)
# define TO_DEGREES(x) (float) (x * 180.0f / PI)

# define SQRT(x) (float) (sqrt(x))
# define POW(x) (float) (pow(x))

# define COS(x) (float) (cos(x))
# define SIN(x) (float) (sin(x))
# define TAN(x) (float) (tan(x))

# define ACOS(x) (float) (acos(x))
# define ASIN(x) (float) (asin(x))
# define ATAN(x) (float) (atan(x))
# define ATAN2(x) (float) (atan2(x))

# define LERP(a, b, t) (float) (a + (b - a) * t)

# define MAX(a, b) (float) (a > b ? a : b)
# define MIN(a, b) (float) (a < b ? a : b)

namespace lz
{
	namespace maths
	{
		class vec3;
		class mat4;
		class quat;

	    class vec3
	    {
	    public:
	        float m_x;
	        float m_y;
	        float m_z;

			vec3();
			vec3(float x, float y, float z);
			vec3(vec3 *v);
			void set(float x, float y, float z);

			float magnitude();
			vec3 normalize();
			vec3 cross(vec3 r);

			vec3 rotate(quat rot);
			float dot(vec3 r);
			vec3 reflect(vec3 normal);

			static float distance(vec3 a, vec3 b);

			//ADD
			inline vec3 add(float x, float y, float z)
			{
				m_x += x;
				m_y += y;
				m_z += z;

				return (this);
			}
			inline vec3 add(float v) { return add(v, v, v); };
			inline vec3 add(vec3 v) { return add(v.m_x, v.m_y, v.m_z); };

			//SUB
			inline vec3 sub(float x, float y, float z)
			{
				m_x -= x;
				m_y -= y;
				m_z -= z;

				return (this);
			}
			inline vec3 sub(float v) { return sub(v, v, v); };
			inline vec3 sub(vec3 v) { return sub(v.m_x, v.m_y, v.m_z); };

			//MUL
			inline vec3 mul(float x, float y, float z)
			{
				m_x *= x;
				m_y *= y;
				m_z *= z;

				return (this);
			}
			inline vec3 mul(float v) { return mul(v, v, v); };
			inline vec3 mul(vec3 v) { return mul(v.m_x, v.m_y, v.m_z); };

			//DIV
			inline vec3 div(float x, float y, float z)
			{
				m_x /= x;
				m_y /= y;
				m_z /= z;

				return (this);
			}
			inline vec3 div(float v) { return div(v, v, v); };
			inline vec3 div(vec3 v) { return div(v.m_x, v.m_y, v.m_z); };

			inline vec3 copy() { return vec3(m_x, m_y, m_z); };
	    };

	    class mat4
	    {
	    public:
	        float m_matrix[4 * 4];

			mat4 mul(mat4 m);

			static mat4 identity();

			static mat4 translate(float x, float y, float z);
			static mat4 translate(vec3 pos);
			static mat4 rotate(float x, float y, float z);
			static mat4 rotate(vec3 forward, vec3 up, vec3 right);
			static mat4 scale(float x, float y, float z);

			static mat4 cameraView(vec3 forward, vec3 up);
			static mat4 perspective(float fov, float aspect, float near, float far);
			static mat4 orthographic(float right, float left, float top, float bottom, float near, float far);

			static vec3 transform(mat4 m, vec3 v);
	    };

	    class quat
	    {
	    public:
	        float m_x;
	        float m_y;
	        float m_z;
	        float m_w;

			quat();
			quat(quat* q);
			quat(float x, float y, float z, float w);
			quat(vec3 axis, float angle);
			void set(float x, float y, float z, float w);

			float magnitude();
			quat normalize();
			quat conjugate();
			quat mul(quat r);
			quat mul(vec3 r);
			float dot(quat r);

			mat4 to_matrix();

			vec3 get_forward();
			vec3 get_back();
			vec3 get_right();
			vec3 get_left();
			vec3 get_up();
			vec3 get_down();
	    };
	}
}

#endif
