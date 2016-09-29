#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <LZ/shader.h>
#include <LZ/error.h>
#include <LZ/file_utils.h>

using namespace lz;

shader::shader(const char *vertex_path, const char *fragment_path)
{
	const char *vertex_source = load_file(vertex_path);
	const char *fragment_source = load_file(fragment_path);
	m_program = shader::createProgram(vertex_source, fragment_source);
}

shader::~shader()
{
	glDeleteProgram(m_program);
}

GLuint shader::createProgram(const char *vertex_source, const char *fragment_source)
{
	GLuint program = glCreateProgram();

	if (program == GL_FALSE)
		sever("Unable to create shader program !");

	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

	GLuint vertex_shader = shader::createShader(vertex_source, GL_VERTEX_SHADER);
	GLuint fragment_shader = shader::createShader(fragment_source, GL_FRAGMENT_SHADER);

	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return (program);
}

GLuint shader::getUniformLocation(char *name)
{
	return glGetUniformLocation(m_program, (GLchar*)name);
}

void shader::setUniform(char* name, GLint v)
{
	glUniform1i(getUniformLocation(name), v);
}

void shader::setUniform(char *name, GLfloat v)
{
	glUniform1f(getUniformLocation(name), v);
}

void shader::setUniform(char* name, vec3 v)
{
	glUniform3f(getUniformLocation(name), v.m_x, v.m_y, v.m_z);
}

void shader::setUniform(char* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	glUniform4f(getUniformLocation(name), x, y, z, w);
}

void shader::setUniform(char* name, mat4 m)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, false, m.m_matrix);
}

GLuint shader::createShader(const char *source, int type)
{
	GLuint shader;
	GLint result;

	shader = glCreateShader(type);
	if (shader == GL_FALSE)
		sever("Unable to create shader !");
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> error(length);
		glGetShaderInfoLog(shader, length, &length, &error[0]);
		std::cout << &error[0] << std::endl;
		glDeleteShader(shader);
		return (0);
	}
	return (shader);
}
