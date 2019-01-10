#pragma once

#include <glad/glad.h>

namespace alpha {
	class Texture {
	public:
		Texture();
		~Texture();
	private:
		GLuint m_textureId;
	};
}