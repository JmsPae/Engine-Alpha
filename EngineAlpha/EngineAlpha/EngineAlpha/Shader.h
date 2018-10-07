#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include <glad/glad.h>

#include "glm/glm.hpp"

namespace alpha {
	enum ShaderType {
		VERTEX_SHADER = GL_VERTEX_SHADER,
		FRAGMENT_SHADER = GL_FRAGMENT_SHADER,
		GEOMETRY_SHADER = GL_GEOMETRY_SHADER
	};

	class Shader {
	public:
		Shader(std::string vsPath, std::string fsPath);

		void AddShader(std::string path, ShaderType type);
		void Compile();
		void Bind();

		void Delete();

		template<class T> void SendUniform(std::string name, T variable);
		void SendUniform(std::string name, float variable);
		void SendUniform(std::string name, int variable);
		void SendUniform(std::string name, glm::vec2 variable);
		void SendUniform(std::string name, glm::ivec2 variable);
		void SendUniform(std::string name, glm::vec3 variable);
		void SendUniform(std::string name, glm::ivec3 variable);
		void SendUniform(std::string name, glm::vec4 variable);
		void SendUniform(std::string name, glm::ivec4 variable);
		void SendUniform(std::string name, glm::mat2 variable);
		void SendUniform(std::string name, glm::mat3 variable);
		void SendUniform(std::string name, glm::mat4 variable);

		~Shader();

		unsigned int ProgramID;

	private:
		std::map<std::string, unsigned int> m_locations;
		std::vector<unsigned int> m_shaders;
	};
}