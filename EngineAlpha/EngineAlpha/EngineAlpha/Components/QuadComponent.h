#pragma once

#include "Component.h"
#include "../Graphics/BaseMesh.h"
#include "../Graphics/Color.h"

namespace alpha {
	class QuadComponent : public Component {
	public:
		QuadComponent(unsigned int priority = 0, glm::vec2 size = glm::vec2(1), glm::vec2 uvScale = glm::vec2(1));

		void Init() override;

		void Draw(Shader &shader) override;

		~QuadComponent();

		glm::vec2 Size, UvScale;
		Color Color;
	private:
		BaseMesh m_meshRenderer;
	};
}