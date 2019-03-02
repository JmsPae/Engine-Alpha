#pragma once

#include <vector>

#include "BaseColliderComponent.h"

namespace alpha {
	class PolygonColliderComponent : public BaseColliderComponent {
	public:
		PolygonColliderComponent(const std::vector<glm::vec2>& vertices, float mass = 1.f);

		void Init() override;

		~PolygonColliderComponent();

		float Mass;
		std::vector<glm::vec2> Vertices;
	private:
		b2PolygonShape m_shape;
	};
}