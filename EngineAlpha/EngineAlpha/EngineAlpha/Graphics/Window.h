#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <iostream>

namespace alpha {
	class Window {
	public:
		Window(int windowWidth = 1280, int windowHeight = 720, std::string windowName = "Engine Alpha");
		~Window();

		void Clear();
		void SwapBuffers();
		void PollEvents();

		bool IsOpen();
		int SizeX, SizeY;
	private:
		GLFWwindow *m_glfwWindow;
	};
}