#ifndef OBJ_LOADER_H
# define OBJ_LOADER_H

# include <LZ/mesh.h>

namespace lz
{
	class ObjLoader
	{
	private:
		std::vector<vec3> m_loadedPositions;
		std::vector<vec2> m_loadedTexCoords;
		std::vector<vec3> m_loadedNormals;
		std::vector<int> m_loadedIndices;
	public:
		ObjLoader(char *path);
		~ObjLoader();
	};
}

#endif