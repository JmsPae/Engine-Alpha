#include <EngineAlpha/Window.h>

int main() {
	auto window = alpha::Window();

	while (window.IsOpen()) {
		window.Clear();

		window.SwapBuffers();
		window.PollEvents();
	}

	return 0;
}