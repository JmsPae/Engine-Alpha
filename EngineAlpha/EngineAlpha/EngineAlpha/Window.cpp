#include "Window.h"

namespace alpha {
	Window::Window(int windowWidth, int windowHeight, std::string windowName) {
		if (!glfwInit()) {
			printf("ERROR: GLFW Failed to initialize!\n");
			system("pause");
			exit(EXIT_FAILURE);
		}

		m_glfwWindow = glfwCreateWindow(windowWidth, windowHeight, windowName.c_str(), NULL, NULL);

		if (!m_glfwWindow) {
			printf("ERROR: GLFW Window Failed to create!\n");
			system("pause");
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
		glfwMakeContextCurrent(m_glfwWindow);
	}

	Window::~Window() {
		glfwTerminate();
	}

	void Window::Clear() {
		glClearColor(0.8, 0.6, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::SwapBuffers() {
		glfwSwapBuffers(m_glfwWindow);
	}

	void Window::PollEvents() {
		glfwPollEvents();
	}

	bool Window::IsOpen() {
		return !glfwWindowShouldClose(m_glfwWindow);
	}
}