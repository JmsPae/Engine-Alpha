#pragma once

#include <vector>

#include "../Maths.h"
#include "../Color.h"

/*
	The Mesh class is the representation of a (technically 3d) mesh. Its the 
	interface, so to speak, between the programmer and the BaseMesh class.
*/

namespace alpha {
	class Mesh {
	public:
		Mesh() {}
		~Mesh() {}

		void AddUv(glm::vec2 uv) { Uvs.push_back(uv); }
		void AddPosition(glm::vec3 position) { Positions.push_back(position); }
		void AddColor(Color color) { Colors.push_back(color); }

		std::vector<glm::vec2> Uvs;
		std::vector<glm::vec3> Positions;
		std::vector<Color> Colors;
	};
}