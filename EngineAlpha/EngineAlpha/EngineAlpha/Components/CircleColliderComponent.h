#pragma once

#include "BaseColliderComponent.h"

namespace alpha {
	class CircleColliderComponent : public BaseColliderComponent {
	public:
		CircleColliderComponent(float radius = 1.f, float mass = 1.f);

		void Init() override;

		~CircleColliderComponent();

		float Mass;
		float Radius;
	private:
		b2CircleShape m_shape;
	};
}