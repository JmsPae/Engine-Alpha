#pragma once

#include <EngineAlpha/Engine.h>

class Player : public alpha::Component {
public:
	Player(alpha::InputManager &inputManager) : inputManager(&inputManager) {

	}

	void Update(float dt) override {
		Parent->Rotation -= (float)inputManager->GetInput("Right") * dt;
		Parent->Position += glm::vec2(cos(Parent->Rotation + glm::radians(90.f)), sin(Parent->Rotation + glm::radians(90.f))) * dt * 0.5f * (float)inputManager->GetInput("Forward");
	}

	~Player() {

	}

private:
	alpha::InputManager *inputManager;
};