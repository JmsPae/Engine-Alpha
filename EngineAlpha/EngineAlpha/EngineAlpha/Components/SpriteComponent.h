#pragma once

#include "Component.h"
#include "../Graphics/BaseMesh.h"

namespace alpha {
	class SpriteComponent : public Component {
	public:
		SpriteComponent(glm::vec2 size);
		~SpriteComponent();

		glm::vec2 Size;
	private:
		alpha::BaseMesh m_meshRenderer;
	};
}