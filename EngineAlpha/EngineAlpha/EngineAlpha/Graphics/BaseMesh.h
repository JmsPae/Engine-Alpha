#pragma once

#include "Mesh.h"
#include "../Core/ResourceManager.h"

/*
	The BaseMesh class takes the representation given to it via the Mesh Class
	and sends the representation to the GPU and then handles thew IDs provided 
	by the gpu
*/

namespace alpha {
	class BaseMesh {
	public:
		BaseMesh();

		void SetMesh(Mesh &mesh);
		
		void Draw();

		unsigned int Priority = 0;
		std::string TextureName = "_none";

		~BaseMesh();
	private:
		unsigned int m_VBO, m_VAO;
		unsigned int m_vertexCount;
	};
}