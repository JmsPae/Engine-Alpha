#include "Window.h"

namespace alpha {
	Window::Window(int windowWidth, int windowHeight, std::string windowName) {
		if (!glfwInit()) {
			printf("ERROR: GLFW Failed to initialize!\n");
			std::cin.get();
			exit(EXIT_FAILURE);
		}

		m_glfwWindow = glfwCreateWindow(windowWidth, windowHeight, windowName.c_str(), NULL, NULL);

		if (!m_glfwWindow) {
			printf("ERROR: GLFW Window Failed to create!\n");
			std::cin.get();
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
		glfwMakeContextCurrent(m_glfwWindow);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD" << std::endl;
			std::cin.get();
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
	}

	Window::~Window() {
		glfwTerminate();
	}

	void Window::Clear() {
		int x, y;
		glfwGetWindowSize(m_glfwWindow, &x, &y);

		glViewport(0, 0, x, y);
		glClearColor(0.8f, 0.6f, 1.0f, 1.0f);
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