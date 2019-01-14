#pragma once

#include <EngineAlpha/Engine.h>
#include "Tank.h"

namespace game {
	class Player : public game::Tank {
	public:
		Player(alpha::InputManager &inputManager) : inputManager(&inputManager) {

		}

		void TankInit() override {

		}

		void TankUpdate(float dt) override {
			if (inputManager->GetInput("Shoot")) {
				alpha::RayCaster raycast;
				auto callback = raycast.CastRay(Parent->Position, Parent->Position + glm::vec2(cosf(Parent->Rotation + TurretRotation + glm::radians(90.f)), sinf(Parent->Rotation + TurretRotation + glm::radians(90.f))) * 100.f);
				if (callback.Hit) {
					printf("Hit! \n");
					callback.Collider->SetVelocity(callback.Collider->GetVelocity() + callback.RayDirection * 5.f * dt);
				}
			}
			
			SetMove((float)inputManager->GetInput("Forward") * dt * 4);
			SetRotation((float)inputManager->GetInput("Right") * dt * 6);
			SetTurretRotation((float)inputManager->GetInput("TurretRight") * dt * 10);
		}

		~Player() {

		}

	private:
		alpha::InputManager *inputManager;
	};
}