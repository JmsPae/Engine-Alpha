#pragma once

#include "Component.h"
#include "../Physics/PhysicsWorld.h"

namespace alpha {
	enum ColliderBodyType {
		Static = b2_staticBody,
		Kinematic = b2_kinematicBody,
		Dynamic = b2_dynamicBody
	};

	class BaseColliderComponent : public Component {
	public:
		BaseColliderComponent();

		glm::vec2 GetPosition();
		float GetRotation();
		
		glm::vec2 GetVelocity();
		float GetAngularVelocity();

		void SetPosition(glm::vec2 pos);
		void SetRotation(float rotation);

		void SetVelocity(glm::vec2 vel);
		void SetAngularVelocity(float angVel);

		void Update(float dt) override;

		float Friction = 5.f; // Is actually Linear Dampining, but this is required because of box 2d not simulating friction unless there is contact with another surface (which isnt always the case for top-down games)

		~BaseColliderComponent();
	protected:
		void CreateBody(glm::vec2 Position, float rotation);
		//Create polygon shape before calling...
		void DefineFixture(float density, float friction);

		ColliderBodyType BodyType;

		b2BodyDef BodyDef;
		b2Body *Body; //Deleted automatically by B2World
		b2Shape *Shape;
		b2FixtureDef FixtureDef;
	};
}