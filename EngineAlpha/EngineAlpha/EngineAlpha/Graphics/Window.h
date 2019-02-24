#pragma once

#include <iostream>

struct GLFWwindow;

namespace alpha {
	class Window {
	public:
		Window(int windowWidth = 1280, int windowHeight = 720, std::string windowName = "Engine Alpha");
		~Window();

		void Clear();
		void SwapBuffers();
		void PollEvents();

		GLFWwindow *GetGLFWWindow();

		bool IsOpen();
		int SizeX, SizeY;
	private:
		GLFWwindow *m_glfwWindow;
	};
}