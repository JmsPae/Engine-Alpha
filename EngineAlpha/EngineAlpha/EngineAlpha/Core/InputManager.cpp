#include "InputManager.h"

namespace alpha {
	InputManager::InputManager(Window *window) : m_window(window) { }

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