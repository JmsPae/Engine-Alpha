#include "Camera.h"

namespace alpha {
	Camera::Camera() : Zoom(1), Position(glm::vec2(0)) {

	}
	
	void Camera::Draw(Shader &shader, float aspectRatio) {
		shader.SendUniform("Projection", glm::ortho(-aspectRatio / Zoom, aspectRatio / Zoom, -1.f / Zoom, 1.f / Zoom, -10.f, 10.f));
		shader.SendUniform("View", glm::lookAt(glm::vec3(Position, 0), glm::vec3(Position, -1), glm::vec3(0, 1, 0)));
	}

	Camera::~Camera() {

	}	
}