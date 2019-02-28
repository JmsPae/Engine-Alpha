#pragma once

#include "Component.h"
#include "../Maths.h"

namespace alpha {

	class TransformComponent : public Component {
	public:
		TransformComponent();
		TransformComponent(glm::vec2 position, glm::vec2 scale, float rotation);

		~TransformComponent();

		glm::mat4 GetTransform() const;

		glm::vec2 Position;
		glm::vec2 Scale;
		float Rotation;
	};
}