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
			/*Parent->Rotation -= (float)inputManager->GetInput("Right") * dt;
			Parent->Position += glm::vec2(cos(Parent->Rotation + glm::radians(90.f)), sin(Parent->Rotation + glm::radians(90.f))) * dt * 0.5f * (float)inputManager->GetInput("Forward");*/
		
			SetMove((float)inputManager->GetInput("Forward") * dt * 2);
			SetRotation((float)inputManager->GetInput("Right") * dt * 5);
			SetTurretRotation((float)inputManager->GetInput("TurretRight") * dt * 10);
		}

		~Player() {

		}

	private:
		alpha::InputManager *inputManager;
	};
}