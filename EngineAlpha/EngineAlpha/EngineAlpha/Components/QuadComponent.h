#pragma once

#include "Component.h"
#include "../Graphics/BaseMesh.h"

namespace alpha {
	class QuadComponent : public Component {
	public:
		QuadComponent(glm::vec2 size = glm::vec2(1), glm::vec2 uvScale = glm::vec2(1));

		void Init() override {
			auto mesh = alpha::Mesh();

			mesh.AddPosition({ -Size.x / 2, -Size.y / 2, 0 });
			mesh.AddPosition({ -Size.x / 2, Size.y / 2, 0 });
			mesh.AddPosition({ Size.x / 2, Size.y / 2, 0 });
			mesh.AddPosition({ Size.x / 2, Size.y / 2, 0 });
			mesh.AddPosition({ Size.x / 2, -Size.y / 2, 0 });
			mesh.AddPosition({ -Size.x / 2, -Size.y / 2, 0 });

			mesh.AddUv(glm::vec2(0, 0));
			mesh.AddUv(glm::vec2(0, 1) * UvScale);
			mesh.AddUv(glm::vec2(1, 1) * UvScale);
			mesh.AddUv(glm::vec2(1, 1) * UvScale);
			mesh.AddUv(glm::vec2(1, 0) * UvScale);
			mesh.AddUv(glm::vec2(0, 0));

			for (size_t i = 0; i < 6; i++)
				mesh.AddColor(glm::vec4(1));

			m_meshRenderer.SetMesh(mesh);
		}
		void Draw(Shader &shader) override {
			shader.SendUniform("Transform", Parent->Transform);
			m_meshRenderer.Draw();
		}

		~QuadComponent();

		glm::vec2 Size, UvScale;
	private:
		BaseMesh m_meshRenderer;
	};
}