#include "RayCaster.h"

namespace alpha {
	RayCastCallback::RayCastCallback() : Collider(nullptr), Hit(false) { }

	float32 RayCastCallback::ReportFixture(b2Fixture * rFixture, const b2Vec2 & rPoint, const b2Vec2 & rNormal, float32 rFraction) {
		Collider = (BaseColliderComponent*)rFixture->GetBody()->GetUserData();
		Point = glm::vec2(rPoint.x, rPoint.y);
		Normal = glm::vec2(rNormal.x, rNormal.y);
		Fraction = rFraction;
		Hit = true;
		return rFraction;
	}

	// --- RayCaster Class Starts Here

	RayCaster::RayCaster() {}

	RayCastCallback RayCaster::CastRay(glm::vec2 Start, glm::vec2 End) {
		RayCastCallback callback;
		callback.RayDirection = glm::normalize(End - Start);
		PhysicsWorld::MainWorld.GetB2World()->RayCast(&callback, b2Vec2(Start.x, Start.y), b2Vec2(End.x, End.y));
		return callback;
	}
}