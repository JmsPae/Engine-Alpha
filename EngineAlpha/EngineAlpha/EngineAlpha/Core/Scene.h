#pragma once

#include <vector>

#include "GameObject.h"

namespace alpha {
	class Scene {
	public:
		Scene();

		void AddGameObject(GameObject &object);

		void Update(float dt);

		void Draw(Shader &shader);

		~Scene();
	private:
		std::vector<GameObject*> m_gameObjects;
		std::vector<GameObject*> m_gameObjectRemovalQueue;
	};
}