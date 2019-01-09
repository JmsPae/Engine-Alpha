#include "Scene.h"

namespace alpha {
	Scene::Scene() {

	}

	void Scene::AddGameObject(GameObject &object) {
		m_gameObjects.push_back(&object);
		object._AddedToScene();
	}

	void Scene::Update(float dt) {
		for (size_t i = 0; i < m_gameObjects.size(); i++) {
			if (m_gameObjects[i])
				m_gameObjects[i]->Update(dt);
			else
				m_gameObjectRemovalQueue.push_back(m_gameObjects[i]);
		}

		while (m_gameObjectRemovalQueue.size() > 0) { //TODO
			m_gameObjects.erase(std::find(m_gameObjects.begin(), m_gameObjects.end(), m_gameObjectRemovalQueue[0]));
			m_gameObjectRemovalQueue.erase(m_gameObjectRemovalQueue.begin());
		}
	}

	void Scene::Draw(Shader &shader) {
		for (size_t i = 0; i < m_gameObjects.size(); i++) {
			if (m_gameObjects[i])
				m_gameObjects[i]->Draw(shader);
		}
	}

	Scene::~Scene() {
		for (size_t i = 0; i < m_gameObjects.size(); i++) {
			if (m_gameObjects[i])
				delete m_gameObjects[i];
		}
		m_gameObjects.clear();
	}
}