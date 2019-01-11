#pragma once

#include "../Graphics/Texture.h"

namespace alpha {
	class ResourceManager {
	public:
		static std::map<std::string, Shader> Shaders;
		static std::map<std::string, Image> Images;
		static std::map<std::string, Texture> Textures;
	};
}