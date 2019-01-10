#include "Texture.h"

namespace alpha {
	Texture::Texture() : m_textureId(0) {

	}

	void Texture::SetImage(Image &image) {
		if (image.GetPixelData()) {
			if (m_textureId == 0) {
				glGenTextures(1, &m_textureId);
			}
			glBindTexture(GL_TEXTURE_2D, m_textureId);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.Width, image.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.GetPixelData());
		}
		else {
			printf("Failed to create texture! \n");
		}
	}

	void Texture::Bind() {
		glBindTexture(GL_TEXTURE_2D, m_textureId);
	}

	Texture::~Texture() {
		glDeleteTextures(1, &m_textureId);
	}
}