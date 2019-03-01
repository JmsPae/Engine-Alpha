#include "CircleColliderComponent.h"

namespace alpha {
	CircleColliderComponent::CircleColliderComponent(float radius, float mass) : Radius(radius), Mass(mass) {

	}

	void CircleColliderComponent::Init() {

		CreateBody(Parent->Position, Parent->Rotation,
			Mass > 0.f ? b2_dynamicBody : b2_staticBody);
		m_shape.m_p.Set(0, 0);
		m_shape.m_radius = Radius;

		Shape = &m_shape;

		CreateFixture(Mass / Radius, 1.0f);
	}

	CircleColliderComponent::~CircleColliderComponent(){
	}
}