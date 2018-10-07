#include "BaseMesh.h"

namespace alpha {
	BaseMesh::BaseMesh() {
		
	}

	void BaseMesh::SetMesh(Mesh & mesh) {
		if (!m_VAO) {
			glGenVertexArrays(1, &m_VAO);
			glGenBuffers(1, &m_VBO);
		}

		m_vertexCount = mesh.Positions.size();
		std::vector<float> data;
		for (size_t i = 0; i < mesh.Positions.size(); i++) {
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

		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);
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
		printf("Deleted mesh \n");
	}
}