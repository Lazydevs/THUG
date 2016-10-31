#ifndef OBJ_LOADER_H
# define OBJ_LOADER_H

# include <iostream>
# include <vector>
# include <LZ/mesh.h>
# include <LZ/buffers.h>
# include <LZ/maths.h>

using namespace maths;

namespace lz
{
	typedef struct 	_VertexIndex
	{
		int position;
		int texcoord;
		int normal;
	}				VertexIndex;

	class ObjLoader
	{
	private:
		std::vector<vec3> 			m_loadedPositions;
		std::vector<vec2> 			m_loadedTexCoords;
		std::vector<vec3> 			m_loadedNormals;
		std::vector<VertexIndex> 	m_loadedIndices;
		
		int m_positionsSize; 
		int m_texCoordsSize; 
		int m_normalsSize; 
		int m_indicesSize;

		GLfloatBuffer m_positions;
		GLfloatBuffer m_texCoords;
		GLfloatBuffer m_normals;
		GLuintBuffer m_indices;

		Mesh *m_mesh;

	public:
		ObjLoader(char *path);
		~ObjLoader();

		inline Mesh *getMesh() { return (m_mesh); }
	};
}

#endif