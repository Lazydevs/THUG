#include "game.h"
#include <LZ/physics.h>
#include <LZ/obj_loader.h>

using namespace lz;
using namespace maths;
using namespace physics;

Game::Game()
{
	m_physicsWorld = new PhysicsWorld(vec3(0, -9.81, 0));
	m_groundBox = new Box(Transform(vec3(0, 0, 0), quat(0, 0, 0, 1), vec3(15, 0.5, 15)), 0.0);
	m_physicsWorld->addBody(m_groundBox->getBody());
	m_mousePressed = false;
}

Game::~Game()
{
	delete m_groundBox;
	m_boxes.clear();
}

void Game::update(Input *input, Camera *camera)
{
	m_groundBox->update();
	for (Box *box : m_boxes)
		box->update();

	if (input->getButton(0) && !m_mousePressed)
	{
		Transform boxTransform = Transform(camera->getTransform());
		boxTransform.setScale(vec3(0.5, 0.5, 0.5));
		Box *box = new Box(boxTransform, 1.0);
		m_physicsWorld->addBody(box->getBody());
		m_boxes.push_back(box);
		m_mousePressed = true;
	}
	if (!input->getButton(0) && m_mousePressed)
		m_mousePressed = false;

	m_physicsWorld->update(1.0 / 60.0);
}

void Game::render(Shader *shader)
{
	m_groundBox->render(shader);
	for (Box *box : m_boxes)
		box->render(shader);
}
