#include "TransformComponent.h"

#include "../Maths.h"

namespace alpha {
	TransformComponent::TransformComponent() 
		: Position(glm::vec2()), Scale(glm::vec2(1, 1)), Rotation(0.0f) {
	}

	TransformComponent::TransformComponent(glm::vec2 position, glm::vec2 scale, float rotation)
		: Position(position), Scale(scale), Rotation(rotation) {
	}

	TransformComponent::~TransformComponent() {
	}

	glm::mat4 TransformComponent::GetTransform() const {
		return glm::translate(glm::vec3(Position, 0))
			* glm::rotate(Rotation, glm::vec3(0, 0, 1));
	}
}