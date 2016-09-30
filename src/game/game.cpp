#include "game.h"

using namespace lz;
using namespace maths;

Game::Game()
{
	GLfloat vertices[] = {
		0, 0, 0,
		1, 0, 0,
		1, 0, 1,
		0, 0, 1,

		0, 1, 0,
		1, 1, 0,
		1, 1, 1,
		0, 1, 1
	};

	GLuint indices[] = {
		0, 1, 2, 0, 2, 3,
		1, 5, 6, 1, 6, 2,
		5, 4, 7, 5, 7, 6,
		4, 0, 3, 4, 3, 7,
		1, 0, 4, 1, 4, 5,
		3, 2, 6, 3, 6, 7
	};

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
}

Game::~Game()
{

}

void Game::update()
{

}

void Game::render(shader *shader, camera *camera)
{
	shader->setUniform((char *)"modelMatrix", mat4::translate(0, -2, 0).mul(mat4::scale(10, 0.5, 10)));
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	shader->setUniform((char *)"modelMatrix", mat4::translate(10, -2, -0.5).mul(mat4::scale(0.5, 4, 4.5)));
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	shader->setUniform((char *)"modelMatrix", mat4::translate(10, -2, 6).mul(mat4::scale(0.5, 4, 4.5)));
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	shader->setUniform((char *)"modelMatrix", mat4::translate(-0.5, -2, -0.5).mul(mat4::scale(0.5, 4, 11)));
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	shader->setUniform((char *)"modelMatrix", mat4::translate(0, -2, 10).mul(mat4::scale(10, 4, 0.5)));
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	shader->setUniform((char *)"modelMatrix", mat4::translate(0, -2, -0.5).mul(mat4::scale(10, 4, 0.5)));
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	shader->setUniform((char *)"modelMatrix", mat4::translate(-1, 2, 10).mul(mat4::rotate(-45, 0, 0).mul(mat4::scale(12, 7.5, 0.5))));
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	shader->setUniform((char *)"modelMatrix", mat4::translate(-1, 2.4, -0.5).mul(mat4::rotate(45, 0, 0).mul(mat4::scale(12, 7.5, 0.5))));
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
