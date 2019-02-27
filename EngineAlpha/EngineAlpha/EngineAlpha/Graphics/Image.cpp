#include "Image.h"

#include "../Core/Log.h"

namespace alpha {
	Image::Image() : Width(0), Height(0), Components(0) {}

	Image::Image(int width, int height, Color fillColor) : Width(width), Height(height), Components(4) {
		m_data = std::vector<unsigned char>(width * height * Components);
		
		for (size_t y = 0; y < (size_t)width; y++) {
			for (size_t x = 0; x < (size_t)height; x++) {
				for (size_t c = 0; c < 4; c++) {
					m_data[4 * ((y * width) + x) + c] = (char)(fillColor[c] * 255);
				}
			}
		}
	}

	Image::Image(std::string path) : Width(0), Height(0), Components(0) {
		unsigned char *m_imageData = stbi_load(("Resources/Textures/" + path).c_str(), &Width, &Height, &Components, 4);

		if (!m_imageData) {
			Width = 0;
			Height = 0;
			Components = 0;

			LOG_ERROR("Image {} failed to load!", path);
		}
		else {
			m_data = std::vector<unsigned char>(m_imageData, m_imageData + Width * Height * Components);
			stbi_image_free(m_imageData);
		}
	}

	Color Image::GetPixel(int x, int y) {
		if (x < Width && y < Height) {
			float r = m_data[4 * ((y * Width) + x) + 0];
			float g = m_data[4 * ((y * Width) + x) + 1];
			float b = m_data[4 * ((y * Width) + x) + 2];
			float a = m_data[4 * ((y * Width) + x) + 3];

			return Color(r / 255, g / 255, b / 255, a / 255);
		}
		return Color(0.0f, 0.0f, 0.0f, 1.0f);
	}

	unsigned char *Image::GetPixelData() {
		return &m_data[0];
	}

	Image::~Image() {
    
	}
}