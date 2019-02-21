#include "BaseColliderComponent.h"

namespace alpha {
	BaseColliderComponent::BaseColliderComponent() {

	}

	glm::vec2 BaseColliderComponent::GetPosition() { return glm::vec2(Body->GetPosition().x, Body->GetPosition().y); }
	float BaseColliderComponent::GetRotation() { return Body->GetAngle(); }

	glm::vec2 BaseColliderComponent::GetVelocity() { return glm::vec2(Body->GetLinearVelocity().x, Body->GetLinearVelocity().y); }
	float BaseColliderComponent::GetAngularVelocity() { return Body->GetAngularVelocity(); }

	void BaseColliderComponent::SetPosition(glm::vec2 pos) { Body->SetTransform(b2Vec2(pos.x, pos.y), Body->GetAngle()); }
	void BaseColliderComponent::SetRotation(float rotation) { Body->SetTransform(Body->GetPosition(), rotation); }

	void BaseColliderComponent::SetVelocity(glm::vec2 vel) { Body->SetLinearVelocity(b2Vec2(vel.x, vel.y)); }
	void BaseColliderComponent::SetAngularVelocity(float angVel) { Body->SetAngularVelocity(angVel); }


	void BaseColliderComponent::Update(float dt) {
		if (Body) {
			Body->SetLinearDamping(Friction); //Awful, awful, awful!!
			Body->SetAngularDamping(Friction);
			Parent->Position = GetPosition();
			Parent->Rotation = GetRotation();
		}
	}
	
	BaseColliderComponent::~BaseColliderComponent() {
		PhysicsWorld::MainWorld.GetB2World()->DestroyBody(Body);
		Body = nullptr;
	}

	void BaseColliderComponent::CreateBody(glm::vec2 Position, float rotation, b2BodyType type) {
		BodyDef.type = type;
		BodyDef.position.Set(Position.x, Position.y);
		BodyDef.angle = rotation;
		Body = PhysicsWorld::MainWorld.GetB2World()->CreateBody(&BodyDef);
		Body->SetUserData(this);
	}

	void BaseColliderComponent::CreateFixture(float density, float friction) {
		FixtureDef.shape = Shape;
		FixtureDef.density = density;
		FixtureDef.friction = friction;
		Body->CreateFixture(&FixtureDef);
	}
}