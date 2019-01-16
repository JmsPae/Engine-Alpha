#include "QuadComponent.h"

namespace alpha {
	QuadComponent::QuadComponent(glm::vec2 size, glm::vec2 uvScale) : Size(size), UvScale(uvScale), Color(glm::vec4(1)) {

	}

	void QuadComponent::Init() {
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

	void QuadComponent::Draw(Shader & shader) {
		shader.SendUniform("ColorMult", Color);
		shader.SendUniform("Transform", Parent->Transform);
		m_meshRenderer.Draw();
	}
	
	QuadComponent::~QuadComponent() {

	}
}