#pragma once

#include <EngineAlpha/Engine.h>
#include "Tank.h"
#include "Player.h"

namespace game {
	class Enemy : public game::Tank {
	public:
		Enemy(Player *player) : m_player(player) {

		}

		void TankInit() override {
			SetColor(alpha::Color(1.0f, 0.0f, 0.0f, 1.0f));
		}

		void TankUpdate(float dt) override {
			auto transform = Parent->GetTransformComponent();
			auto playerTransform = m_player->Parent->GetTransformComponent();
			if (glm::distance(transform.Position, playerTransform.Position) > 2.f) {
				SetMove(3.f * dt * glm::dot(glm::normalize(RotDirPos - transform.Position), glm::normalize(playerTransform.Position - transform.Position)));
			}

			RotDirPos += (playerTransform.Position - RotDirPos) * dt * 0.5f;
			TurretDirPos += (playerTransform.Position - TurretDirPos) * dt * 1.f;

			SetDirection(RotDirPos);
			SetTurretDirection(glm::normalize(TurretDirPos - transform.Position));
		}

		~Enemy() {

		}

	private:
		Player *m_player;
		glm::vec2 RotDirPos, TurretDirPos;
	};
}