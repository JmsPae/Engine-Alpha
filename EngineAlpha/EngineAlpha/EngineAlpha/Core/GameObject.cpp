#include "GameObject.h"

#include "../Components/TransformComponent.h"

namespace alpha {
	GameObject::GameObject(glm::vec2 position, float rotation) {
		AddComponent(new TransformComponent(position, glm::vec2(1), rotation));
	}

	void GameObject::_SetScene(Scene *scene) {
		m_scene = scene;
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

	Scene *GameObject::GetScene() {
		return m_scene;
	}

	glm::mat4 GameObject::GetTransform() {
		return GetTransformComponent().GetTransform();
	}

	TransformComponent& GameObject::GetTransformComponent() {
		return *GetComponent<TransformComponent>();
	}

	GameObject::~GameObject() {
		for (size_t i = 0; i < m_components.size(); i++) {
			if (m_components[i]) {
				delete m_components[i];
			}
		}
	}
}