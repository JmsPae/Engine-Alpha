#pragma once

#include <EngineAlpha/Engine.h>
#include "Enemy.h"

namespace game {
	class EnemyManager : public alpha::Component {
	public:
		EnemyManager();

		void AddEnemy(glm::vec2 position);

		void Init() override;
		void Update(float dt) override;

		~EnemyManager();
	private:
		std::vector<alpha::GameObject> m_enemies;
	};
}