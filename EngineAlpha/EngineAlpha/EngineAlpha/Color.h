#pragma once

#include "Maths.h"

namespace alpha {

	class Color {
	public:
		Color();
		Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

		explicit Color(unsigned int color);

		static Color FromFloat(float r, float g, float b, float a);

		unsigned int ToInteger() const;
		glm::vec4 ToFloatColor() const;

		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;

		unsigned char operator[](const size_t index);
	};

	bool operator==(const Color& left, const Color& right);
	bool operator!=(const Color& left, const Color& right);
}