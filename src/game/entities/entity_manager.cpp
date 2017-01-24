#include "entity_manager.h"

EntityManager::EntityManager()
{
}

EntityManager::~EntityManager()
{
	m_entities.clear();
}

void EntityManager::update()
{
	for (std::pair<long, Entity *> data : m_entities)
	{
		Entity *e = (Entity *)data.second;
		e->update();
	}
}

void EntityManager::add(Entity *e)
{
	m_entities[e->getID()] = e;
	// if (e->getRigidBody())
	// 	m_game->getPhysicsWorld()->addBody(e->getRigidBody());
}

void EntityManager::remove(Entity *e)
{
	// if (e->getRigidBody())
	// 	m_game->getPhysicsWorld()->removeBody(e->getRigidBody());
	m_entities.erase(e->getID());
}

void EntityManager::remove(int id)
{
	m_entities.erase(id);
}

Entity *EntityManager::get(int id)
{
	return m_entities[id];
}