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
		template<> void SendUniform(std::string name, float variable);

		~Shader();

		unsigned int ProgramID;

	private:
		std::map<std::string, unsigned int> m_locations;
		std::vector<unsigned int> m_shaders;
	};
}