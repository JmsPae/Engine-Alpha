#include <EngineAlpha/Engine.h>
#include <EngineAlpha/Components/TestComponent.h>

#include "Components/Player.h"
#include "Components/Enemy.h"

class MainGame : public alpha::Game {
public:
	MainGame() {
		alpha::ResourceManager::Images["tank1"] = alpha::Image("tank1.png");
		alpha::ResourceManager::Images["tank1_t"] = alpha::Image("tank1_t.png");
		alpha::ResourceManager::Images["test"] = alpha::Image("test.png");
		alpha::ResourceManager::Images["dirt1"] = alpha::Image("dirt1.png");
	}

	void Init() override {
		alpha::ResourceManager::Textures["tank1"] = alpha::Texture();
		alpha::ResourceManager::Textures["tank1"].SetImage(alpha::ResourceManager::Images["tank1"]);
		alpha::ResourceManager::Textures["tank1_t"] = alpha::Texture();
		alpha::ResourceManager::Textures["tank1_t"].SetImage(alpha::ResourceManager::Images["tank1_t"]);
		alpha::ResourceManager::Textures["test"] = alpha::Texture();
		alpha::ResourceManager::Textures["test"].SetImage(alpha::ResourceManager::Images["test"]);
		alpha::ResourceManager::Textures["dirt1"] = alpha::Texture();
		alpha::ResourceManager::Textures["dirt1"].SetImage(alpha::ResourceManager::Images["dirt1"]);

		InputManager = alpha::InputManager(GameWindow);
		InputManager.AddInput("Right", ALPHA_KEY_A, ALPHA_KEY_D);
		InputManager.AddInput("TurretRight", ALPHA_KEY_LEFT, ALPHA_KEY_RIGHT);
		InputManager.AddInput("Forward", ALPHA_KEY_W, ALPHA_KEY_S);
		InputManager.AddInput("Shoot", ALPHA_KEY_SPACE);

		m_scene = alpha::Scene();
		m_shader = new alpha::Shader("Resources/main.vs", "Resources/main.fs");



		m_playerObject = alpha::GameObject();
		m_playerObject.AddComponent(new alpha::QuadComponent());
		m_playerObject.AddComponent(new game::Player(InputManager));
		m_scene.AddGameObject(m_playerObject);

		m_testObject = alpha::GameObject(glm::vec2(0, 1.5f));
		m_testObject.AddComponent(new alpha::QuadComponent());
		m_testObject.AddComponent(new alpha::QuadColliderComponent(glm::vec2(1), 0.f));
		m_scene.AddGameObject(m_testObject);

		m_groundObject = alpha::GameObject();
		m_groundObject.AddComponent(new alpha::QuadComponent(glm::vec2(20.f), glm::vec2(5.f)));
		m_scene.AddGameObject(m_groundObject);

		m_enemyObject = alpha::GameObject(glm::vec2(0, 3.5f));
		m_enemyObject.AddComponent(new alpha::QuadComponent());
		m_enemyObject.AddComponent(new game::Enemy());
		m_scene.AddGameObject(m_enemyObject);

		m_camera.Zoom = 1.f / 4;
	}

	void Update(float dt) override {
		m_scene.Update(dt);
		alpha::PhysicsWorld::MainWorld.Update(dt);
		m_camera.Position = m_playerObject.Position;
	}

	void Draw() override {
		m_shader->Bind();

		m_shader->SendUniform("Timer", this->Time);
		m_shader->SendUniform("Transform", glm::translate(glm::vec3(0.5, 0, 0)));

		m_camera.Draw(*m_shader, (float)GameWindow->SizeX / (float)GameWindow->SizeY);
		
		alpha::ResourceManager::Textures["dirt1"].Bind();
		m_groundObject.Draw(*m_shader);

		alpha::ResourceManager::Textures["tank1"].Bind();
		m_playerObject.Draw(*m_shader);
		m_enemyObject.Draw(*m_shader);

		alpha::ResourceManager::Textures["test"].Bind();
		m_testObject.Draw(*m_shader);
	}

private:
	alpha::Camera m_camera;

	alpha::Scene m_scene;

	alpha::GameObject m_playerObject;
	alpha::GameObject m_enemyObject;

	alpha::GameObject m_testObject;
	alpha::GameObject m_groundObject;

	alpha::Shader *m_shader;
};

int main() {
	MainGame game;
	game.Start();

	return 0;
}