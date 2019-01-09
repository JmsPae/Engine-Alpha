#pragma once

#include "../Maths.h"

#include "Shader.h"

namespace alpha {
	class Camera {
	public:
		Camera();
		~Camera();

		void Draw(Shader &shader, float aspectRatio);

		glm::vec2 Position;
		float Zoom;
	};
}