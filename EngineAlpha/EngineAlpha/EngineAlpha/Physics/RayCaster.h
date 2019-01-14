#pragma once

#include "../Maths.h"
#include "PhysicsWorld.h"
#include "../Components/BaseColliderComponent.h"

namespace alpha {
	class RayCastCallback : public b2RayCastCallback{
	public:
		RayCastCallback();

		float32 ReportFixture(b2Fixture *rFixture, const b2Vec2 &rPoint, const b2Vec2 &rNormal, float32 rFraction) override;

		BaseColliderComponent *Collider;
		glm::vec2 Point;
		glm::vec2 Normal;
		glm::vec2 RayDirection;
		float Fraction;
		bool Hit;
	};

	class RayCaster {
	public:
		RayCaster();
		RayCastCallback CastRay(glm::vec2 Start, glm::vec2 End);
	};
}