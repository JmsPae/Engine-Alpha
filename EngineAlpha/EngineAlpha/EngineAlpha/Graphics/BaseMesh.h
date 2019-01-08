#pragma once

#include <glad/glad.h>

#include "Mesh.h"

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

		~BaseMesh();
	private:
		unsigned int m_VBO, m_VAO;
		unsigned int m_vertexCount;
	};
}