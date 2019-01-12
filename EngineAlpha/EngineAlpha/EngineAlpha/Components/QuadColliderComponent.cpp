#include "QuadColliderComponent.h"

namespace alpha {
	QuadColliderComponent::QuadColliderComponent(glm::vec2 size, float mass) : Size(size), Mass(mass) {

	}

	void QuadColliderComponent::Init() {
		CreateBody(Parent->Position, Parent->Rotation);
		m_shape.SetAsBox(Size.x / 2, Size.y / 2, -b2Vec2(0, 0), 0);
		Shape = &m_shape;
		DefineFixture(Mass / (Size.x * Size.y), 1.f);
	}

	QuadColliderComponent::~QuadColliderComponent() {

	}
}