#pragma once

#include "Maths.h"

namespace alpha {

	class Color {
	public:
		Color();
		Color(float r, float g, float b, float a);

		float r;
		float g;
		float b;
		float a;

		float operator[](const size_t index);
	};

	bool operator==(const Color& left, const Color& right);
	bool operator!=(const Color& left, const Color& right);
}