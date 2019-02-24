#pragma once

#include <string>
#include <vector>

#include "stb_img.h"

#include "../Maths.h"
#include "../Color.h"

namespace alpha {
	class Image {
	public:
		Image();
		Image(int width, int height, Color fillColor = Color(1.0f, 1.0f, 1.0f, 1.0f));
		Image(std::string path);
		
		Color GetPixel(int x, int y);
		unsigned char *GetPixelData();

		~Image();

		int Width, Height;
		int Components;
	private:
		std::vector<unsigned char> m_data;
	};
}