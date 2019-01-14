#include "QuadColliderComponent.h"

namespace alpha {
	QuadColliderComponent::QuadColliderComponent(glm::vec2 size, float mass) : Size(size), Mass(mass) {

	}

	void QuadColliderComponent::Init() {
		CreateBody(Parent->Position, Parent->Rotation, Mass > 0.f ? b2_dynamicBody : b2_staticBody);
		m_shape.SetAsBox(Size.x / 2, Size.y / 2, -b2Vec2(0, 0), 0);
		Shape = &m_shape;
		if (Mass > 0.f) //If mass is less than or equal to zero, then the shape will be defined as static.
			CreateFixture(Mass / (Size.x * Size.y), 1.f);
		else
			CreateFixtureStatic();
	}

	QuadColliderComponent::~QuadColliderComponent() {

	}
}