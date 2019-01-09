#pragma once

#include "../Graphics/Shader.h"
#include "../Core/GameObject.h"

namespace alpha {
	class GameObject;

	class Component {
	public:
		Component() {}

		void _SetParent(GameObject *parent) { Parent = parent; }

		virtual void Init() {}

		virtual void Update(float dt) {}

		virtual void Draw(Shader &shader) {}

		~Component() {}
	protected:
		GameObject *Parent;
	};
}