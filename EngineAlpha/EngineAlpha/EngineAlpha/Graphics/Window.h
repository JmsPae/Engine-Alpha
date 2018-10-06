#pragma once

#include <GLFW/glfw3.h>

#include <iostream>

namespace alpha {
	class Window {
	public:
		Window(int windowWidth = 1280, int windowHeight = 720);
		~Window();

		void Clear();
		void SwapBuffers();
		void PollEvents();

		bool IsOpen();
	private:
		GLFWwindow *m_glfwWindow;
	};
}