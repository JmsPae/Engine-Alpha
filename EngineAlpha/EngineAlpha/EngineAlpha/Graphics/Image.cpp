#include "Image.h"

namespace alpha {
	Image::Image() : Width(0), Height(0), Components(0), m_imageData(nullptr) {}

	Image::Image(int width, int height, glm::vec4 fillColor) : Width(width), Height(height), Components(4), m_imageData(nullptr) {
		m_imageData = new unsigned char[width * height * Components];
		
		for (size_t y = 0; y < width; y++) {
			for (size_t x = 0; x < height; x++) {
				for (size_t c = 0; c < 4; c++) {
					m_imageData[4 * ((y * width) + x) + c] = (char)(fillColor[c] * 255);
				}
			}
		}
	}

	Image::Image(std::string path) : Width(0), Height(0), Components(0), m_imageData(nullptr) {
		m_imageData = stbi_load(("Resources/Textures/" + path).c_str(), &Width, &Height, &Components, 4);

		if (!m_imageData) {
			Width = 0;
			Height = 0;
			Components = 0;

			printf("Image %s faled to load!\n", path.c_str());
		}
	}

	glm::vec4 Image::GetPixel(int x, int y) {
		if (m_imageData) {
			float r = m_imageData[4 * ((y * Width) + x) + 0];
			float g = m_imageData[4 * ((y * Width) + x) + 1];
			float b = m_imageData[4 * ((y * Width) + x) + 2];
			float a = m_imageData[4 * ((y * Width) + x) + 3];

			return glm::vec4(r / 255, g / 255, b / 255, a / 255);
		}
		return glm::vec4(0, 0, 0, 1);
	}

	unsigned char *Image::GetPixelData() {
		return m_imageData;
	}

	Image::~Image() {
		/*if (m_imageData) {
			stbi_image_free(m_imageData);
		}*/
	}
}