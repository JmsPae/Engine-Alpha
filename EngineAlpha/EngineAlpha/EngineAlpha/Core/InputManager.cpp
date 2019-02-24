#include "InputManager.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace alpha {
	InputManager::InputManager() : m_window(nullptr) {}
	InputManager::InputManager(Window *window) : m_window(window) { }

	glm::vec2 InputManager::GetMousePosition() {
		double mposx, mposy;
		glfwGetCursorPos(m_window->GetGLFWWindow(), &mposx, &mposy);
		return glm::vec2(mposx, mposy);
	}

	glm::vec2 InputManager::GetWindowPosition() {
		int posx, posy;
		glfwGetWindowPos(m_window->GetGLFWWindow(), &posx, &posy);
		return glm::vec2(posx, posy);
	}

	glm::vec2 InputManager::GetWindowSize() {
		int sizex, sizey;
		glfwGetWindowSize(m_window->GetGLFWWindow(), &sizex, &sizey);
		return glm::vec2(sizex, sizey);
	}

	void InputManager::AddInput(std::string name, InputType type, int inputPositive, int inputNegative) {
		m_inputs[name] = { inputPositive, inputNegative, type };
	}

	int InputManager::GetInput(std::string name) {
		int ret = 0;
		switch (m_inputs[name].Type) {
			case InputType::Keyboard: {
				int state = glfwGetKey(m_window->GetGLFWWindow(), m_inputs[name].PositiveKey);
				if (state == GLFW_PRESS)
					ret += 1;
				if (m_inputs[name].NegativeKey != -2) {
					state = glfwGetKey(m_window->GetGLFWWindow(), m_inputs[name].NegativeKey);
					if (state == GLFW_PRESS)
						ret -= 1;
				}
			}
			case InputType::Mouse: {
				int state = glfwGetMouseButton(m_window->GetGLFWWindow(), m_inputs[name].PositiveKey);
				if (state == GLFW_PRESS)
					ret += 1;
				if (m_inputs[name].NegativeKey != -2) {
					state = glfwGetMouseButton(m_window->GetGLFWWindow(), m_inputs[name].NegativeKey);
					if (state == GLFW_PRESS)
						ret -= 1;
				}
			}
		}

		return ret;
	}
}