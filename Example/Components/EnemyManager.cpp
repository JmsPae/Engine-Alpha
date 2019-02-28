#include "EnemyManager.h"

namespace game {
	EnemyManager::EnemyManager() {

	}

	void EnemyManager::AddEnemy(glm::vec2 position) {
		auto go = alpha::GameObject();
		go.AddComponent(new alpha::TransformComponent(position, glm::vec2(1), 0.0f));
		m_enemies.push_back(go);

	}

	void EnemyManager::Init() {

	}

	void EnemyManager::Update(float dt) {
		
	}

	EnemyManager::~EnemyManager() {

	}
}