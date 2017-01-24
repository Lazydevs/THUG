#ifndef ENTITY_MANAGER_H
# define ENTITY_MANAGER_H

#include "entity.h"
#include <map>
#include <iostream>

class EntityManager
{
private:
	std::map<long, Entity*>	m_entities;

public:
	EntityManager();
	~EntityManager();

	void update();

	void add(Entity *e);
	void remove(Entity *e); 
	void remove(int id);
	Entity *get(int id);

	inline std::map<long, Entity *> getEntities() { return m_entities; }
};

#endif