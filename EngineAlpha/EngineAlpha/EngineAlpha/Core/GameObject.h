#pragma once

#include "../Maths.h"

#include "../Components/Component.h"

namespace alpha {
	class Component;

	class GameObject {
	public:
		GameObject(glm::vec2 position = glm::vec2(0), float rotation = 0.f);

		void _AddedToScene();

		void AddComponent(Component *component);

		void Update(float dt);

		void Draw(Shader &shader);

		~GameObject();

		float Rotation;
		glm::vec2 Position;
		glm::mat4 Transform;
	private:
		

		std::vector<Component*> m_components;
		std::vector<Component*> m_componentRemovalQueue;
	};
}