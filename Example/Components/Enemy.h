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
			SetColor(alpha::Color::FromFloat(1.0f, 0.0f, 0.0f, 1.0f));
		}

		void TankUpdate(float dt) override {
			if (glm::distance(Parent->Position, m_player->Parent->Position) > 2.f) {
				SetMove(3.f * dt * glm::dot(glm::normalize(RotDirPos - Parent->Position), glm::normalize(m_player->Parent->Position - Parent->Position)));
			}

			RotDirPos += (m_player->Parent->Position - RotDirPos) * dt * 0.5f;
			TurretDirPos += (m_player->Parent->Position - TurretDirPos) * dt * 1.f;

			SetDirection(RotDirPos);
			SetTurretDirection(glm::normalize(TurretDirPos - Parent->Position));
		}

		~Enemy() {

		}

	private:
		Player *m_player;
		glm::vec2 RotDirPos, TurretDirPos;
	};
}