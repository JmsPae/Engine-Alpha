#pragma once

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
		unsigned int m_textureId;
	};
}