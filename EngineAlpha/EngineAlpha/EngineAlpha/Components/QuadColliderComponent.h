#pragma once

#include "BaseColliderComponent.h"

namespace alpha {
	class QuadColliderComponent : public BaseColliderComponent {
	public:
		QuadColliderComponent(glm::vec2 size = glm::vec2(1), float mass = 1.f);

		void Init() override;

		~QuadColliderComponent();

		float Mass;
		glm::vec2 Size;
	private:
		b2PolygonShape m_shape;
	};
}