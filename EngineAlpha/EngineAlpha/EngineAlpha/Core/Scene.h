#pragma once

#include <vector>

#include "GameObject.h"

namespace alpha {
	class Scene {
	public:
		Scene();
		~Scene();
	private:
		std::vector<GameObject*> m_gameObjects;
	};
}