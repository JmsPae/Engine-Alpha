#pragma once

#include <vector>
#include <chrono>

#include "GameObject.h"
#include "Game.h"

namespace alpha {
	class Game;
	class Scene {
	public:
		Scene();

		void AddGameObject(GameObject &object);

		virtual void Init() {}

		virtual void Update(float dt) {}
		void UpdateGameObjects(float dt);

		virtual void Draw() {}

		virtual void Finish() {}

		void _SetGame(Game *game);

		~Scene();
	protected:
		Game *MainGame;
	private:
		std::vector<GameObject*> m_gameObjects;
		std::vector<GameObject*> m_gameObjectRemovalQueue;
	};
}