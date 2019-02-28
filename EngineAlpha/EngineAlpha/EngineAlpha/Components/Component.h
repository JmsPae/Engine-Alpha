#pragma once

namespace alpha {
	class GameObject;
	class Shader;

	class Component {
	public:
		Component() : Parent(nullptr) {}

		void _SetParent(GameObject *parent) { Parent = parent; }

		virtual void Init() {}

		virtual void Update(float dt) {}

		virtual void Draw(Shader &shader) {}

		~Component() {}

		GameObject *Parent;
	};
}