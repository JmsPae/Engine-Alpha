#include "Color.h"

namespace alpha {

	Color::Color()
		: r(0), g(0), b(0), a(0)
	{
	}

	Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
		: r(r), g(g), b(b), a(a)
	{
	}

	Color Color::FromFloat(float r, float g, float b, float a) {
		return Color(((unsigned char)(r * 255)),
			((unsigned char)(g * 255)),
			((unsigned char)(b * 255)),
			((unsigned char)(a * 255)));
	}

	Color::Color(unsigned int color)
		: r((color & 0xff000000) >> 24),
		g((color & 0x00ff0000) >> 16),
		b((color & 0x0000ff00) >> 8),
		a((color & 0x000000ff) >> 0)
	{
	}

	unsigned int Color::ToInteger() const {
		return (r << 24) | (g << 16) | (b << 8) | a;
	}

	glm::vec4 Color::ToFloatColor() const {
		return glm::vec4(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
	}

	bool operator==(const Color& left, const Color& right) {
		return (left.r == right.r) && (left.g == right.g) && (left.b == right.b) && (left.a == right.a);
	}

	bool operator!=(const Color& left, const Color& right) {
		return !(left == right);
	}

	unsigned char Color::operator[](const size_t index)
	{
		switch (index)
		{
		case 0:
			return r;
		case 1:
			return g;
		case 2:
			return b;
		case 3:
			return a;
		default:
			return 0;
		}

		return 0;
	}
}