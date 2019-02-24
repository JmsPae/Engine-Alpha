#include "Shader.h"

#include <glad/glad.h>

namespace alpha {
	GLenum ShaderTypeToGL(ShaderType type) {
		switch (type)
		{
		case ShaderType::FRAGMENT_SHADER:
			return GL_FRAGMENT_SHADER;
		case ShaderType::VERTEX_SHADER:
			return GL_VERTEX_SHADER;
		case ShaderType::GEOMETRY_SHADER:
			return GL_GEOMETRY_SHADER;
		default:
			throw std::exception("Unknown shader type");
		}

		// Something went really wrong when we reach this
		throw std::exception("Unknown shader type");
	}

	Shader::Shader(std::string vsPath, std::string fsPath) {
		AddShader(vsPath, VERTEX_SHADER);
		AddShader(fsPath, FRAGMENT_SHADER);
		Compile();
	}

	void Shader::AddShader(std::string path, ShaderType type) {
		std::string line;
		std::string pth;
		std::ifstream myfile(path);

		while (std::getline(myfile, line)) { pth.append(line + "\n"); }
		myfile.close();

		m_shaders.push_back(glCreateShader(ShaderTypeToGL(type)));
		const char *chars = pth.c_str();
		glShaderSource(m_shaders[m_shaders.size() - 1], 1, &chars, NULL);
		glCompileShader(m_shaders[m_shaders.size() - 1]);

		GLint success;
		GLchar infoLog[1024];
		glGetShaderiv(m_shaders[m_shaders.size() - 1], GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(m_shaders[m_shaders.size() - 1], 1024, NULL, infoLog);
			std::cout << "Error at " << path << ", \n" << infoLog << std::endl;
		}
	}

	void Shader::Compile() {
		ProgramID = glCreateProgram();
		for (size_t i = 0; i < m_shaders.size(); i++) {
			glAttachShader(ProgramID, m_shaders[i]);
		}
		glLinkProgram(ProgramID);
		for (size_t i = 0; i < m_shaders.size(); i++) {
			glDeleteShader(m_shaders[i]);
		}
		m_shaders.clear();
	}

	void Shader::Bind() {
		glUseProgram(ProgramID);
	}

	template<class T> void Shader::SendUniform(std::string name, T variable) {
		printf("Unsupported type!\n");
	}

	void Shader::SendUniform(std::string name, float variable) {
		if (m_locations.find(name) == m_locations.end())
			m_locations[name] = glGetUniformLocation(ProgramID, name.c_str());
		glUniform1f(m_locations[name], variable);
	}

	void Shader::SendUniform(std::string name, double variable) {
		if (m_locations.find(name) == m_locations.end())
			m_locations[name] = glGetUniformLocation(ProgramID, name.c_str());
		glUniform1f(m_locations[name], variable);
	}

	void Shader::SendUniform(std::string name, int variable) {
		if (m_locations.find(name) == m_locations.end())
			m_locations[name] = glGetUniformLocation(ProgramID, name.c_str());
		glUniform1i(m_locations[name], variable);
	}

	void Shader::SendUniform(std::string name, glm::vec2 variable) {
		if (m_locations.find(name) == m_locations.end())
			m_locations[name] = glGetUniformLocation(ProgramID, name.c_str());
		glUniform2f(m_locations[name], variable.x, variable.y);
	}

	void Shader::SendUniform(std::string name, glm::ivec2 variable) {
		if (m_locations.find(name) == m_locations.end())
			m_locations[name] = glGetUniformLocation(ProgramID, name.c_str());
		glUniform2i(m_locations[name], variable.x, variable.y);
	}

	void Shader::SendUniform(std::string name, glm::vec3 variable) {
		if (m_locations.find(name) == m_locations.end())
			m_locations[name] = glGetUniformLocation(ProgramID, name.c_str());
		glUniform3f(m_locations[name], variable.x, variable.y, variable.z);
	}

	void Shader::SendUniform(std::string name, glm::ivec3 variable) {
		if (m_locations.find(name) == m_locations.end())
			m_locations[name] = glGetUniformLocation(ProgramID, name.c_str());
		glUniform3i(m_locations[name], variable.x, variable.y, variable.z);
	}

	void Shader::SendUniform(std::string name, glm::vec4 variable) {
		if (m_locations.find(name) == m_locations.end())
			m_locations[name] = glGetUniformLocation(ProgramID, name.c_str());
		glUniform4f(m_locations[name], variable.x, variable.y, variable.z, variable.w);
	}

	void Shader::SendUniform(std::string name, glm::ivec4 variable) {
		if (m_locations.find(name) == m_locations.end())
			m_locations[name] = glGetUniformLocation(ProgramID, name.c_str());
		glUniform4i(m_locations[name], variable.x, variable.y, variable.z, variable.w);
	}

	void Shader::SendUniform(std::string name, glm::mat2 variable) {
		if (m_locations.find(name) == m_locations.end())
			m_locations[name] = glGetUniformLocation(ProgramID, name.c_str());
		glUniformMatrix2fv(m_locations[name], 1, GL_FALSE, &variable[0][0]);
	}

	void Shader::SendUniform(std::string name, glm::mat3 variable) {
		if (m_locations.find(name) == m_locations.end())
			m_locations[name] = glGetUniformLocation(ProgramID, name.c_str());
		glUniformMatrix3fv(m_locations[name], 1, GL_FALSE, &variable[0][0]);
	}

	void Shader::SendUniform(std::string name, glm::mat4 variable) {
		if (m_locations.find(name) == m_locations.end())
			m_locations[name] = glGetUniformLocation(ProgramID, name.c_str());
		glUniformMatrix4fv(m_locations[name], 1, GL_FALSE, &variable[0][0]);
	}

	Shader::~Shader() {
		glDeleteProgram(ProgramID);
	}
}