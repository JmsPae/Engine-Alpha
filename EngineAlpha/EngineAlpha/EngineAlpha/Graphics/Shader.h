#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include <glad/glad.h>

#include "../glm/glm.hpp"

/*
	The Shader class handles everything to do with the shader on the hardware aswell as the software side.
*/

namespace alpha {
	//The shader types supported by Opengl 3.3
	enum ShaderType {
		VERTEX_SHADER = GL_VERTEX_SHADER,
		FRAGMENT_SHADER = GL_FRAGMENT_SHADER,
		GEOMETRY_SHADER = GL_GEOMETRY_SHADER
	};

	class Shader {
	public:
		Shader(std::string vsPath, std::string fsPath);

		//AddShader() and Compile() are intended for if you intend to add each shader individually aswell as add a geometry shader
		void AddShader(std::string path, ShaderType type);
		void Compile();
		void Bind();

		//Sending uniform variables to the shader 
		template<class T> void SendUniform(std::string name, T variable);
		void SendUniform(std::string name, float variable);
		void SendUniform(std::string name, double variable);
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
		//m_locations is a map of all the uniform locations retrieved from the shader. It is stored instead of just retrieving them again for performance sakes
		std::map<std::string, unsigned int> m_locations;
		std::vector<unsigned int> m_shaders;
	};
}