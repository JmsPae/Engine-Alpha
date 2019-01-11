#include "ResourceManager.h"

namespace alpha {
	std::map<std::string, Shader> ResourceManager::Shaders = std::map<std::string, Shader>();
	std::map<std::string, Image> ResourceManager::Images = std::map<std::string, Image>();
	std::map<std::string, Texture> ResourceManager::Textures = std::map<std::string, Texture>();
}