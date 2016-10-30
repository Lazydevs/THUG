#include <LZ/obj_loader.h>
#include <LZ/error.h>
#include <LZ/string_utils.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace lz;

ObjLoader::ObjLoader(char *path)
{
	char line[256];
	FILE *fp;
	
	printf("loading:%s\n", path);
	if ((fp = fopen(path, "r")) == NULL)
		sever("Unable to load file !"); 
	while (fgets(line, 256, fp) != NULL)
	{
		char **tokens = str_split(line, ' ');
		if (strcmp(tokens[0], "v") == 0)
		{
			m_loadedPositions.push_back(atof(tokens[1]));
			m_loadedPositions.push_back(atof(tokens[2]));
			m_loadedPositions.push_back(atof(tokens[3]));

			m_positionsSize += 3;
		}
		else if (strcmp(tokens[0], "vn") == 0)
		{
			m_loadedNormals.push_back(atof(tokens[1]));
			m_loadedNormals.push_back(atof(tokens[2]));
			m_loadedNormals.push_back(atof(tokens[3]));

			m_normalsSize += 3;
		}
		else if (strcmp(tokens[0], "f") == 0)
		{
			char **indides_a = str_split(tokens[1], '/');
			char **indides_b = str_split(tokens[2], '/');
			char **indides_c = str_split(tokens[3], '/');
			
			m_loadedIndices.push_back(atoi(indides_a[0]));
			m_loadedIndices.push_back(atoi(indides_a[1]));
			m_loadedIndices.push_back(atoi(indides_a[2]));
			
			m_loadedIndices.push_back(atoi(indides_b[0]));
			m_loadedIndices.push_back(atoi(indides_b[1]));
			m_loadedIndices.push_back(atoi(indides_b[2]));

			m_loadedIndices.push_back(atoi(indides_c[0]));
			m_loadedIndices.push_back(atoi(indides_c[1]));
			m_loadedIndices.push_back(atoi(indides_c[2]));

			m_indicesSize += 9;
		}
	}
	m_positions.size = sizeof(GLfloat) * m_positionsSize;
	m_positions.buffer = (GLfloat *)malloc(m_positions.size);
	if (m_positions.buffer == NULL)
		sever("OBJ POSITION MALLOC PROBLEM !");

	m_normals.size = sizeof(GLfloat) * m_normalsSize;
	m_normals.buffer = (GLfloat *)malloc(m_normals.size);
	if (m_normals.buffer == NULL)
		sever("OBJ NORMALS MALLOC PROBLEM !");

	m_indices.size = sizeof(GLuint) * m_indicesSize;
	m_indices.buffer = (GLuint *)malloc(m_indices.size);
	if (m_indices.buffer == NULL)
		sever("OBJ INDICES MALLOC PROBLEM !");

	int i = 0;
	for (float data : m_loadedPositions)
	{
		m_positions.buffer[i] = (GLfloat)data;
		i++;
	}
	i = 0;
	for (float data : m_loadedNormals)
	{
		m_normals.buffer[i] = (GLfloat)data;
		i++;
	}
	i = 0;
	for (int data : m_loadedIndices)
	{
		m_indices.buffer[i] = (GLuint)data;
		printf("%i\n", m_indices.buffer[i]);
		i++;
	}
	m_mesh = new Mesh(m_positions, m_normals, m_indices, m_indicesSize);
	m_mesh->create();
}

ObjLoader::~ObjLoader()
{
	free(m_positions.buffer);
	free(m_normals.buffer);
	free(m_indices.buffer);
	delete m_mesh;
}