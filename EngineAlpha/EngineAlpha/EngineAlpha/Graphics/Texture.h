#pragma once

#include <glad/glad.h>

#include "Image.h"
#include "Shader.h"

namespace alpha {
	class Texture {
	public:
		Texture();

		void SetImage(Image &image);

		void Bind();

		~Texture();
	private:
		GLuint m_textureId;
	};
}