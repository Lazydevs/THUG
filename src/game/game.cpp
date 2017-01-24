#include "game.h"
#include <LZ/physics.h>
#include <LZ/obj_loader.h>

using namespace lz;
using namespace maths;
using namespace physics;

Game::Game(Input *input, Camera *camera)
{
	m_input = input;
	m_camera = camera;
	
	m_entityManager = new EntityManager();

	m_physicsWorld = new PhysicsWorld(vec3(0, -9.81, 0));
	m_groundBox = new Box(Transform(vec3(0, 0, 0), quat(0, 0, 0, 1), vec3(15, 0.5, 15)), 0.0);
	m_physicsWorld->addBody(m_groundBox->getBody());
	m_mousePressed = false;
}

Game::~Game()
{
	delete m_groundBox;
	delete m_entityManager;
}

int i = 0;
void Game::update()
{
	m_entityManager->update();
	if (m_input->getButton(0) && !m_mousePressed)
	{
	 	Transform trs = Transform(m_camera->getTransform());
		m_entityManager->add(new Spaceship(i++, trs));
		m_mousePressed = true;
	}
	if (!m_input->getButton(0) && m_mousePressed)
		m_mousePressed = false;

	m_physicsWorld->update(1.0 / 60.0);
}

void Game::render(Shader *shader)
{
	m_groundBox->render(shader);
	for (std::pair<long, Entity *> data : m_entityManager->getEntities())
	{
		Entity *e = (Entity *)data.second;
		e->render(shader);
	}
}
