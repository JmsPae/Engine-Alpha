#pragma once

#include <vector>

#include "../Maths.h"

/*
	The Mesh class is the representation of a (technically 3d) mesh. Its the 
	interface, so to speak, between the programmer and the BaseMesh class.
*/

namespace alpha {
	class Mesh {
	public:
		Mesh() {}
		~Mesh() {}

		void AddPosition(glm::vec3 position) { Positions.push_back(position); }
		void AddColor(glm::vec4 color) { Colors.push_back(color); }

		std::vector<glm::vec3> Positions;
		std::vector<glm::vec4> Colors;
	};
}