#include "spaceship.h"

Spaceship::Spaceship(long id, Transform trs)
:	Entity(id, trs, Resources::loadObj((char *)"data/models/space_ship_1.obj")->getMesh())
{
	
}

Spaceship::~Spaceship()
{

}

void Spaceship::update()
{

}

void Spaceship::render(Shader *shader)
{
	shader->setUniform((char *)"modelMatrix", m_transform.toMatrix());
	m_mesh->draw();
}