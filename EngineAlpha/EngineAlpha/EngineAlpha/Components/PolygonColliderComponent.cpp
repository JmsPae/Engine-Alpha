#include "PolygonColliderComponent.h"

namespace alpha {
	PolygonColliderComponent::PolygonColliderComponent(const std::vector<glm::vec2>& vertices, float mass)
		: Vertices(vertices), Mass(mass) {

	}

	void PolygonColliderComponent::Init() {

		CreateBody(Parent->Position, Parent->Rotation,
			Mass > 0.f ? b2_dynamicBody : b2_staticBody);

		std::vector<b2Vec2> b2Vertices;
		for (auto vert : Vertices) {
			b2Vertices.push_back(b2Vec2(vert.x, vert.y));
		}

		m_shape = b2PolygonShape();
		m_shape.Set(b2Vertices.data(), b2Vertices.size());

		Shape = &m_shape;

		CreateFixture(Mass, 1.0f);
	}

	PolygonColliderComponent::~PolygonColliderComponent() {
	}
}