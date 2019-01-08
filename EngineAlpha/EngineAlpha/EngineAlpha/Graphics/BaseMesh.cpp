#include "BaseMesh.h"

namespace alpha {
	BaseMesh::BaseMesh() { // Nothing is needed to be done here 
		
	}

	void BaseMesh::SetMesh(Mesh & mesh) {
		//If the VAO and VBO have not been created/been deleted (i.e. m_VAO == 0), generate VAO and VBO
		if (!m_VAO) {
			glGenVertexArrays(1, &m_VAO);
			glGenBuffers(1, &m_VBO);
		}

	/*
		Since the engine is only intended to handle displaying sprites/simple shapes,
		and index buffer object would have little effect on performance.
	*/

		m_vertexCount = mesh.Positions.size();
		std::vector<float> data;
		for (size_t i = 0; i < mesh.Positions.size(); i++) { // Adds all the mesh information from the Mesh class into a single vector
			data.push_back(mesh.Positions[i].x);
			data.push_back(mesh.Positions[i].y);
			data.push_back(mesh.Positions[i].z);

			data.push_back(mesh.Colors[i].r);
			data.push_back(mesh.Colors[i].g);
			data.push_back(mesh.Colors[i].b);
			data.push_back(mesh.Colors[i].a);
		}

		glBindVertexArray(m_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

		auto stride = sizeof(float) * (3 + 4);

		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW); //Static draw since i dont intend to constantly change the mesh
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)*3));
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void BaseMesh::Draw() {
		glBindVertexArray(m_VAO);
		glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
	}

	BaseMesh::~BaseMesh() {
		glDeleteVertexArrays(1, &m_VAO);
		glDeleteBuffers(1, &m_VBO);
	}
}