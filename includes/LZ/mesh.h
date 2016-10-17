#ifndef MESH_H
# define MESH_H

# include <stdlib.h>
# include <GL/glew.h>
# include <iostream>
# include <vector>
# include <LZ/maths.h>

using namespace lz::maths;

namespace lz
{
	class Mesh
	{
	private:
		GLuint  m_vao, m_vbo, m_cbo, m_nbo, m_tbo, m_ibo;

		GLfloat 	*m_positions;
		GLfloat 	*m_texCoords;
		GLfloat 	*m_normals;
		GLfloat 	*m_tangents;
		GLuint	 	*m_indices;

		int 		m_size;

	public:
		Mesh(GLfloat *positions, GLfloat *normals, GLuint *indices, int size);
		~Mesh();
		
		void create();
		void draw();

		inline void setPositions(GLfloat *positions) { m_positions = positions; }
		inline void setTexCoords(GLfloat *texCoords) { m_texCoords = texCoords; }
		inline void setNormals(GLfloat *normals) { m_normals = normals; }
		inline void setTangents(GLfloat *tangents) { m_tangents = tangents; }
		inline void setIndices(GLuint *indices) { m_indices = indices; }

		inline GLfloat *getPositions() { return (m_positions); }
		inline GLfloat *getTexCoords() { return (m_texCoords); }
		inline GLfloat *getNormals() { return (m_normals); }
		inline GLfloat *getTangents() { return (m_tangents); }
		inline GLuint  *getIndices() { return (m_indices); }
	};
}

#endif