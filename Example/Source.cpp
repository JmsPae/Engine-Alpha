#include <EngineAlpha/Engine.h>

#include <EngineAlpha/Components/TestComponent.h>

class MainGame : public alpha::Game {
public:
	MainGame() {
		
	}

	void Init() override {
		m_scene = alpha::Scene();
		m_shader = new alpha::Shader("Resources/main.vs", "Resources/main.fs");

		auto mesh = alpha::Mesh();
		mesh.AddPosition({ 0, 1, 0 });
		mesh.AddPosition({ 0, 0, 0 });
		mesh.AddPosition({ 1, 0, 0 });

		mesh.AddColor({ 1, 0, 0, 1 });
		mesh.AddColor({ 0, 1, 0, 1 });
		mesh.AddColor({ 0, 0, 1, 1 });

		m_meshRenderer.SetMesh(mesh);

		m_testObject = alpha::GameObject();
		m_testObject.AddComponent(&m_testComponent);
		m_scene.AddGameObject(m_testObject);
	}

	void Update(float dt) override {
		m_testObject.Rotation += dt;
		m_scene.Update(dt);
	}

	void Draw() override {
		m_shader->Bind();

		m_shader->SendUniform("Timer", this->Time * 0.1f);
		m_shader->SendUniform("Transform", glm::translate(glm::vec3(0.5, 0, 0)));

		m_camera.Position.x = sinf(this->Time);
		m_camera.Draw(*m_shader, (float)GameWindow->SizeX / (float)GameWindow->SizeY);

		m_meshRenderer.Draw();

		m_scene.Draw(*m_shader);
	}

private:
	alpha::Camera m_camera;

	alpha::Scene m_scene;

	alpha::GameObject m_testObject;
	alpha::QuadComponent m_testComponent;

	alpha::Shader *m_shader;

	alpha::BaseMesh m_meshRenderer;
};

int main() {
	MainGame game;
	game.Start();

	return 0;
}