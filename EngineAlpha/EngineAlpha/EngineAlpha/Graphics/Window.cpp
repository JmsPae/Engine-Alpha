#include "Window.h"

namespace alpha {
	Window::Window(int windowWidth, int windowHeight, std::string windowName) : SizeX(windowWidth), SizeY(windowHeight) {
		if (!glfwInit()) {
			printf("ERROR: GLFW Failed to initialize!\n");
			std::cin.get();
			exit(EXIT_FAILURE);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
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

		glEnable(GL_TEXTURE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glfwSwapInterval(0);
	}

	Window::~Window() {
		glfwTerminate();
	}

	void Window::Clear() {
		glfwGetWindowSize(m_glfwWindow, &SizeX, &SizeY);

		glViewport(0, 0, SizeX, SizeY);
		glClearColor(.5f, .5f, .5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::SwapBuffers() {
		glfwSwapBuffers(m_glfwWindow);
	}

	void Window::PollEvents() {
		glfwPollEvents();
	}

	GLFWwindow *Window::GetGLFWWindow() {
		return m_glfwWindow;
	}

	bool Window::IsOpen() {
		return !glfwWindowShouldClose(m_glfwWindow);
	}
}