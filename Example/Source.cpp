#include <EngineAlpha/Engine.h>
#include <EngineAlpha/Components/TestComponent.h>

#include "Components/Player.h"

class MainGame : public alpha::Game {
public:
	MainGame() {
		alpha::ResourceManager::Images["tank1"] = alpha::Image("tank1.png");
		alpha::ResourceManager::Images["tank1_t"] = alpha::Image("tank1_t.png");
		alpha::ResourceManager::Images["test"] = alpha::Image("test.png");
	}

	void Init() override {
		alpha::ResourceManager::Textures["tank1"] = alpha::Texture();
		alpha::ResourceManager::Textures["tank1"].SetImage(alpha::ResourceManager::Images["tank1"]);
		alpha::ResourceManager::Textures["tank1_t"] = alpha::Texture();
		alpha::ResourceManager::Textures["tank1_t"].SetImage(alpha::ResourceManager::Images["tank1_t"]);
		alpha::ResourceManager::Textures["test"] = alpha::Texture();
		alpha::ResourceManager::Textures["test"].SetImage(alpha::ResourceManager::Images["test"]);

		InputManager = alpha::InputManager(GameWindow);
		InputManager.AddInput("Right", ALPHA_KEY_A, ALPHA_KEY_D);
		InputManager.AddInput("TurretRight", ALPHA_KEY_LEFT, ALPHA_KEY_RIGHT);
		InputManager.AddInput("Forward", ALPHA_KEY_W, ALPHA_KEY_S);

		m_scene = alpha::Scene();
		m_shader = new alpha::Shader("Resources/main.vs", "Resources/main.fs");



		m_playerObject = alpha::GameObject();
		m_playerObject.AddComponent(new alpha::QuadComponent());
		m_playerObject.AddComponent(new game::Player(InputManager));
		m_scene.AddGameObject(m_playerObject);

		m_testObject = alpha::GameObject(glm::vec2(0, 1.5f));
		m_testObject.AddComponent(new alpha::QuadComponent());
		m_testObject.AddComponent(new alpha::QuadColliderComponent(glm::vec2(1), 10.f));
		m_scene.AddGameObject(m_testObject);

		m_camera.Zoom = 1.f / 3;
	}

	void Update(float dt) override {
		m_scene.Update(dt);
		alpha::PhysicsWorld::MainWorld.Update(dt);
		//m_camera.Position = m_playerObject.Position;
	}

	void Draw() override {
		m_shader->Bind();

		m_shader->SendUniform("Timer", this->Time);
		m_shader->SendUniform("Transform", glm::translate(glm::vec3(0.5, 0, 0)));

		m_camera.Draw(*m_shader, (float)GameWindow->SizeX / (float)GameWindow->SizeY);
		alpha::ResourceManager::Textures["tank1"].Bind();
		m_playerObject.Draw(*m_shader);

		alpha::ResourceManager::Textures["test"].Bind();
		m_testObject.Draw(*m_shader);
	}

private:
	alpha::Camera m_camera;

	alpha::Scene m_scene;

	alpha::GameObject m_playerObject;
	alpha::GameObject m_testObject;

	alpha::Shader *m_shader;
};

int main() {
	MainGame game;
	game.Start();

	return 0;
}