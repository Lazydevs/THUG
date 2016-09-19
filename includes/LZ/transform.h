#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "maths.h"

namespace lz
{
	class transform
	{
	private:
		maths::vec3 m_pos;
		maths::quat m_rot;
		maths::vec3 m_scale;

	public:
		transform()
		{
			m_pos = maths::vec3();
			m_rot = maths::quat();
			m_scale = maths::vec3();
		}

		transform(maths::vec3 pos, maths::quat rot, maths::vec3 scale)
		{
			m_pos = pos;
			m_rot = rot;
			m_scale = scale;
		}

		transform(maths::vec3 pos, maths::quat rot)
		{
			m_pos = pos;
			m_rot = rot;
			m_scale = maths::vec3();
		}

		transform(maths::vec3 pos)
		{
			m_pos = pos;
			m_rot = maths::quat();
			m_scale = maths::vec3();
		}

		transform(transform* t)
		{
			m_pos = t->m_pos;
			m_rot = t->m_rot;
			m_scale = t->m_scale;
		}

		maths::mat4 to_matrix();

		void rotate(maths::vec3 axis, float angle);
		void translate(maths::vec3 axis, float speed);

		inline maths::vec3 get_position() { return (m_pos); };
		inline maths::quat get_rotation() { return (m_rot); };
		inline maths::vec3 get_scale() { return (m_scale); };

		inline void set_position(maths::vec3 pos) { m_pos = pos; };
		inline void set_rotation(maths::quat rot) { m_rot = rot; };
		inline void set_scale(maths::vec3 scale) { m_scale = scale; };
	};
}

#endif
