#ifndef ENTITY_H
# define ENTITY_H

# include <LZ/maths.h>
# include <LZ/transform.h>
# include <LZ/shader.h>
# include <LZ/mesh.h>

using namespace lz;

class Entity
{
protected:
	long m_id;
	Transform m_transform;
	Mesh *m_mesh;

public:
	Entity(long id, Transform trs, Mesh *mesh);
	~Entity();

	virtual void update();
	virtual void render(Shader *shader);

	inline long getID() { return m_id; }
};

#endif