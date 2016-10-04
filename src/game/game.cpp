#include "game.h"

using namespace lz;
using namespace maths;

Game::Game()
{
	m_groundBox = new Box(transform(vec3(0, 0, 0), quat(0, 0, 0, 1), vec3(30, 1, 30)));
	m_mousePressed = false;
}

Game::~Game()
{
	delete m_groundBox;
	m_boxes.clear();
}

void Game::update(input *input, camera *camera)
{
	m_groundBox->update();

	if (input->getButton(0) && !m_mousePressed)
	{
		transform boxTransform = transform(camera->getTransform());
		boxTransform.setScale(vec3(1, 1, 1));
		m_boxes.push_back(new Box(boxTransform, vec3(camera->getTransform().getForward().x * 500, camera->getTransform().getForward().y * 500, camera->getTransform().getForward().z * 500)));
		m_mousePressed = true;
	}
	if (!input->getButton(0) && m_mousePressed)
		m_mousePressed = false;

	for (Box *box : m_boxes)
		box->update();
}

void Game::render(shader *shader)
{
	m_groundBox->render(shader);
	for (Box *box : m_boxes)
		box->render(shader);
}
