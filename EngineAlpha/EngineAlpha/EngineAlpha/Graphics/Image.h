#pragma once

#include <string>

#include "../Maths.h"
#include "stb_img.h"

namespace alpha {
	class Image {
	public:
		Image();
		Image(int width, int height, glm::vec4 fillColor = glm::vec4(1));
		Image(std::string path);
		
		glm::vec4 GetPixel(int x, int y);
		unsigned char *GetPixelData();

		~Image();

		int Width, Height;
		int Components;
	private:
		unsigned char *m_imageData;
	};
}