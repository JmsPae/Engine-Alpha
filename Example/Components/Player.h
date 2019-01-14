#pragma once

#include <EngineAlpha/Engine.h>
#include "Tank.h"

namespace game {
	class Player : public game::Tank {
	public:
		Player(alpha::InputManager &inputManager);

		void TankInit() override;

		void TankUpdate(float dt) override;
	private:
		alpha::InputManager *inputManager;
	};
}