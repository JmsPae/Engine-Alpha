#include <EngineAlpha/Window.h>
#include <EngineAlpha/BaseMesh.h>
#include <EngineAlpha/Shader.h>

#include <time.h>

int main() {
	auto window = alpha::Window();

	auto shader = alpha::Shader("Resources/main.vs", "Resources/main.fs");

	auto mesh = alpha::Mesh();
	mesh.AddPosition({ 0, 1, 0 });
	mesh.AddPosition({ 0, 0, 0 });
	mesh.AddPosition({ 1, 0, 0 });

	mesh.AddColor({ 1, 0, 0, 1 });
	mesh.AddColor({ 0, 1, 0, 1 });
	mesh.AddColor({ 0, 0, 1, 1 });

	auto meshRenderer = alpha::BaseMesh();
	meshRenderer.SetMesh(mesh);
	
	while (window.IsOpen()) {
		window.Clear();

		shader.Bind();

		shader.SendUniform("Timer", (float)((float)clock() / CLOCKS_PER_SEC) * 4);

		meshRenderer.Draw();

		window.SwapBuffers();
		window.PollEvents();
	}

	return 0;
}