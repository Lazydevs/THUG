#ifndef SPHERE_H
# define SPHERE_H

# include <LZ/maths.h>
# include <LZ/transform.h>
# include <LZ/shader.h>
# include <LZ/physics.h>
# include <LZ/mesh.h>
# include <GL/glew.h>
# include <LZ/buffers.h>
# include <LZ/obj_loader.h>

class Sphere
{
private:
	lz::Transform m_transform;
	lz::maths::vec3 m_force;

	lz::Mesh 	*m_mesh;
	btRigidBody *m_rigidBody;

public:
	Sphere(lz::Transform transform, float mass);
	~Sphere();

	void update();
	void render(lz::Shader *shader);

	inline btRigidBody *getBody() { return (m_rigidBody); }
};

#endif
