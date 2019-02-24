#pragma once

#include "../Maths.h"
#include "../Components/Component.h"
#include "../Core/Scene.h"

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
		Component* GetComponent();

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