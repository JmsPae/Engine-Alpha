#include "InputManager.h"

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

	void InputManager::AddInput(std::string name, int inputPositive, int inputNegative) {
		m_inputs[name] = { inputPositive, inputNegative };
	}

	int InputManager::GetInput(std::string name) {
		int ret = 0;
		int state = glfwGetKey(m_window->GetGLFWWindow(), m_inputs[name].PositiveKey);
		if (state == GLFW_PRESS)
			ret += 1;
		if (m_inputs[name].NegativeKey != -2) {
			state = glfwGetKey(m_window->GetGLFWWindow(), m_inputs[name].NegativeKey);
			if (state == GLFW_PRESS)
				ret -= 1;
		}
		return ret;
	}

	InputManager::~InputManager() {

	}
}