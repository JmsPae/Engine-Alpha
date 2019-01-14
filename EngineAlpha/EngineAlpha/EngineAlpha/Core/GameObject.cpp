#include "GameObject.h"

namespace alpha {
	GameObject::GameObject(glm::vec2 position, float rotation) : Position(position), Rotation(rotation), Transform(glm::rotate(rotation, glm::vec3(0, 0, 1)) * glm::translate(glm::vec3(position, 0))) {
		
	}

	void GameObject::AddComponent(Component *component) {
		component->_SetParent(this);
		component->Init();
		m_components.push_back(component);
	}

	void GameObject::Update(float dt) {
		for (size_t i = 0; i < m_components.size(); i++) {
			if (m_components[i])
				m_components[i]->Update(dt);
		}

		//Rotation -= (float)((int)(Rotation / (glm::pi<float>() * 2))) * (glm::pi<float>() * 2);
		Transform = glm::translate(glm::vec3(Position, 0)) * glm::rotate(Rotation, glm::vec3(0, 0, 1));
	}

	void GameObject::Draw(Shader &shader) {
		for (size_t i = 0; i < m_components.size(); i++) {
			if (m_components[i])
				m_components[i]->Draw(shader);
			else
				m_componentRemovalQueue.push_back(m_components[i]);
		}

		while (m_componentRemovalQueue.size() > 0) {
			m_components.erase(std::find(m_components.begin(), m_components.end(), m_componentRemovalQueue[0]));
			m_componentRemovalQueue.erase(m_componentRemovalQueue.begin());
		}
	}

	GameObject::~GameObject() {
		for (size_t i = 0; i < m_components.size(); i++) {
			if (m_components[i]) {
				delete m_components[i];
			}
		}
	}
}