#include <EngineAlpha/Engine.h>

#include <EngineAlpha/Components/TestComponent.h>

class MainGame : public alpha::Game {
public:
	MainGame() {
		m_image = alpha::Image("robo1.png");

		
	}

	void Init() override {
		InputManager = alpha::InputManager(GameWindow);
		InputManager.AddInput("Right", ALPHA_KEY_D, ALPHA_KEY_A);

		m_scene = alpha::Scene();
		m_shader = new alpha::Shader("Resources/main.vs", "Resources/main.fs");

		m_texture.SetImage(m_image);

		m_testObject = alpha::GameObject();
		m_testObject.AddComponent(&m_testComponent);
		m_scene.AddGameObject(m_testObject);
	}

	void Update(float dt) override {
		printf("%i\n", InputManager.GetInput("Right"));

		m_testObject.Rotation = sin(this->Time * 2) * 0.5;
		m_testObject.Position.y = 0.5f;
		m_scene.Update(dt);
	}

	void Draw() override {
		m_shader->Bind();

		m_shader->SendUniform("Timer", this->Time);
		m_shader->SendUniform("Transform", glm::translate(glm::vec3(0.5, 0, 0)));

		m_camera.Draw(*m_shader, (float)GameWindow->SizeX / (float)GameWindow->SizeY);
		m_texture.Bind();
		m_testObject.Draw(*m_shader);
	}

private:
	alpha::Image m_image;
	alpha::Texture m_texture;

	alpha::Camera m_camera;

	alpha::Scene m_scene;

	alpha::GameObject m_testObject;
	alpha::QuadComponent m_testComponent;

	alpha::Shader *m_shader;
};

int main() {
	MainGame game;
	game.Start();

	return 0;
}