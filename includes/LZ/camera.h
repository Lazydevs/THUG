#ifndef CAMERA_H
# define CAMERA_H

# include "transform.h"
# include "maths.h"
# include "input.h"

namespace lz
{
	class Camera
	{
	private:
		transform	 	m_transform;
		maths::mat4		m_view_matrix;
		maths::mat4		m_projection_matrix;

	public:
		Camera(maths::vec3 pos);
		Camera(maths::vec3 pos, maths::quat rot);
		Camera(transform trs);
		~Camera();

		void update();
		void perspective(float fov, float w, float h, float near, float far);
		void mouseLook(Input *input, float speed);
		void control(Input *input, float speed);

		inline maths::mat4 getViewMatrix() { return (m_view_matrix); };
		inline maths::mat4 getProjectionMatrix() { return (m_projection_matrix); };
		inline transform getTransform() { return (m_transform); }
		inline void setTransform(transform trs) { m_transform = trs; }
	};
}

#endif
