#pragma once

#include "../Maths.h"
#include "../Core/Scene.h"
#include "../Components/Component.h"

namespace alpha {
	class Component;
	class Scene;

	class GameObject {
	public:
		GameObject(glm::vec2 position = glm::vec2(0), float rotation = 0.f);

		void _SetScene(Scene *scene);
		void AddComponent(Component *component);

		void Update(float dt);

		void Draw(Shader &shader);

		template<class T>
		bool HasComponent() {
			static_assert(std::is_base_of<Component, T>(), "T is not a component.");

			return GetComponent<T>() != nullptr;
		}

		template<class T>
		Component* GetComponent() {
			static_assert(std::is_base_of<Component, T>(), "T is not a component");

			for (size_t i = 0; i < m_components.size(); i++) {
				if (dynamic_cast<T*>(m_components[i])) {
					return m_components[i];
				}
			}
			return nullptr;
		}

		Scene *GetScene();

		~GameObject();

		float Rotation;
		glm::vec2 Position;
		glm::mat4 Transform;
	private:
		Scene *m_scene;
		std::vector<Component*> m_components;
		std::vector<Component*> m_componentRemovalQueue;
	};
}