#include "Player.h"

namespace game {
	Player::Player(alpha::InputManager &inputManager) : inputManager(&inputManager), m_shootTimer(0.f) {}

	void Player::TankInit() {
		SetColor(alpha::Color::FromFloat(0.3f, 0.3f, 1.f, 1.f));
	}

	void Player::TankUpdate(float dt) {
		m_shootTimer += dt;

		if (inputManager->GetInput("Shoot") && m_shootTimer >= 0.25f) {
			Fire(10.f);
			m_shootTimer = 0.f;
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