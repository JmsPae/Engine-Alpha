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
		m_scene.Update(dt);
	}

	void Draw() override {
		m_shader->Bind();

		m_shader->SendUniform("Timer", this->Time);
		m_shader->SendUniform("Transform", glm::translate(glm::vec3(0.5, 0, 0)));
		
		m_scene.Draw(*m_shader);

		m_meshRenderer.Draw();
	}

private:
	alpha::Scene m_scene;

	alpha::GameObject m_testObject;
	TestComponent m_testComponent;

	alpha::Shader *m_shader;

	alpha::BaseMesh m_meshRenderer;
};

int main() {
	MainGame game;
	game.Start();

	return 0;
}