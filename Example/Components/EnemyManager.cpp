#include "EnemyManager.h"

namespace game {
	EnemyManager::EnemyManager() {

	}

	void EnemyManager::AddEnemy(glm::vec2 position) {
		m_enemies.push_back(alpha::GameObject(position));

	}

	void EnemyManager::Init() {

	}

	void EnemyManager::Update(float dt) {
		
	}

	EnemyManager::~EnemyManager() {

	}
}