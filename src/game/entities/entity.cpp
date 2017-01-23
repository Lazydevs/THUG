#include "entity.h"

using namespace lz;

Entity::Entity(long id, Transform trs, Mesh *mesh)
{
	m_id = id;
	m_transform = trs;
	m_mesh = mesh;
}

Entity::~Entity()
{

}

void Entity::update()
{
	
}

void Entity::render(Shader *shader)
{
	m_mesh->draw();
}