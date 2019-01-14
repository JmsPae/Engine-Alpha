#include "Player.h"

namespace game {
	Player::Player(alpha::InputManager &inputManager) : inputManager(&inputManager) {}

	void Player::TankInit() {}

	void Player::TankUpdate(float dt) {
		if (inputManager->GetInput("Shoot")) {
			alpha::RayCaster raycast;
			auto callback = raycast.CastRay(Parent->Position, Parent->Position + TurretDir * 100.f);
			if (callback.Hit) {
				printf("Hit! \n");
				callback.Collider->SetVelocity(callback.Collider->GetVelocity() + callback.RayDirection * 5.f * dt);
			}
		}

		auto windowSize = inputManager->GetWindowSize();
		auto mousePos = (inputManager->GetMousePosition() / windowSize) * glm::vec2(2.f) - glm::vec2(1.f);
		mousePos.y = mousePos.y * (windowSize.y / windowSize.x);
		mousePos = glm::normalize(mousePos) * glm::vec2(1, -1);

		//printf("%f %f \n", mousePos.x, mousePos.y);

		SetMove((float)inputManager->GetInput("Forward") * dt * 4.f);
		SetTurretDirection(TurretDir - (TurretDir - mousePos) * dt * 4.f);
		SetRotation((float)inputManager->GetInput("Right") * dt * 6.f);
		//SetTurretRotation((float)inputManager->GetInput("TurretRight") * dt * 10.f);
	}
}