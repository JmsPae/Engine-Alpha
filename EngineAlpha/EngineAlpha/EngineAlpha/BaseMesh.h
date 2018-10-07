#pragma once

#include <glad/glad.h>

#include "Maths.h"
#include "Mesh.h"

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