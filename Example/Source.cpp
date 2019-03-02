#define ALPHA_ENTRY_POINT
#include <EngineAlpha/Engine.h>

#include "Components/Player.h"
#include "Components/Enemy.h"

class MainScene : public alpha::Scene {
public:
	MainScene() {
		alpha::ResourceManager::Images.emplace(std::make_pair(std::string("tank1"), std::string("tank1.png")));
		alpha::ResourceManager::Images.emplace(std::make_pair(std::string("tank1_t"), std::string("tank1_t.png")));
		alpha::ResourceManager::Images.emplace(std::make_pair(std::string("wall"), std::string("wall.png")));
		alpha::ResourceManager::Images.emplace(std::make_pair(std::string("ground"), std::string("ground.png")));

		Time = 0.f;
	}

	void Init() override {
		alpha::ResourceManager::Textures["tank1"] = alpha::Texture();
		alpha::ResourceManager::Textures["tank1"].SetImage(alpha::ResourceManager::Images["tank1"]);
		alpha::ResourceManager::Textures["tank1_t"] = alpha::Texture();
		alpha::ResourceManager::Textures["tank1_t"].SetImage(alpha::ResourceManager::Images["tank1_t"]);
		alpha::ResourceManager::Textures["wall"] = alpha::Texture();
		alpha::ResourceManager::Textures["wall"].SetImage(alpha::ResourceManager::Images["wall"]);
		alpha::ResourceManager::Textures["ground"] = alpha::Texture();
		alpha::ResourceManager::Textures["ground"].SetImage(alpha::ResourceManager::Images["ground"]);

		alpha::AudioFile file, file2, file3;
		file.LoadFile("test.wav");
		file2.LoadFile("test2.wav");
		file3.LoadFile("test3.wav");

		m_sound.SetAudioFile(file);
		m_sound.SetAudioFile(file2);
		m_sound.SetAudioFile(file3);
		m_sound.Play(); //uncomment to play sound

		MainGame->GetInputManager().AddInput("Right", alpha::InputType::Keyboard, alpha::Keyboard::ALPHA_KEY_A, alpha::Keyboard::ALPHA_KEY_D);
		MainGame->GetInputManager().AddInput("Forward", alpha::InputType::Keyboard, alpha::Keyboard::ALPHA_KEY_W, alpha::Keyboard::ALPHA_KEY_S);
		MainGame->GetInputManager().AddInput("Shoot", alpha::InputType::Mouse, alpha::Mouse::ALPHA_MOUSE_BUTTON_LEFT);

		m_shader = std::shared_ptr<alpha::Shader>(new alpha::Shader("Resources/main.vs", "Resources/main.fs"));



		m_playerObject = alpha::GameObject();
		m_playerObject.AddComponent< alpha::TransformComponent>();
		m_playerObject.AddComponent<game::Player>((MainGame->GetInputManager()));
		AddGameObject(m_playerObject);

		m_testObject = alpha::GameObject();
		m_testObject.AddComponent< alpha::TransformComponent>(glm::vec2(0, 1.5f), glm::vec2(1), 0.0f);
		m_testObject.AddComponent<alpha::QuadComponent>();
		m_testObject.AddComponent< alpha::QuadColliderComponent>(glm::vec2(1), 0.f);
		AddGameObject(m_testObject);

		m_testCircle = alpha::GameObject(glm::vec2(4, 4));
		m_testCircle.AddComponent(new alpha::QuadComponent());
		m_testCircle.AddComponent(new alpha::CircleColliderComponent(0.5f, 0.f));
		AddGameObject(m_testCircle);

		m_testPolygon = alpha::GameObject(glm::vec2(-4, 4));
		m_testPolygon.AddComponent(new alpha::QuadComponent());
		auto vertices = std::vector<glm::vec2>{
			glm::vec2(-1, 2),
			glm::vec2(-1, 0),
			glm::vec2(0, -3),
			glm::vec2(1, 0),
			glm::vec2(1, 1)
		};
		m_testPolygon.AddComponent(new alpha::PolygonColliderComponent(vertices, 0.f));
		AddGameObject(m_testPolygon);

		m_groundObject = alpha::GameObject();
		m_groundObject.AddComponent<alpha::TransformComponent>();
		m_groundObject.AddComponent<alpha::QuadComponent>(0, glm::vec2(20.f), glm::vec2(20.f));
		AddGameObject(m_groundObject);

		m_enemyObject = alpha::GameObject();
		m_enemyObject.AddComponent<alpha::TransformComponent>(glm::vec2(0, 3.5f), glm::vec2(1), 0.0f);
		m_enemyObject.AddComponent<game::Enemy>(m_playerObject.GetComponent<game::Player>());
		AddGameObject(m_enemyObject);

		m_camera.Zoom = 1.f / 4;
	}

	void Update(float dt) override {
		Time += dt;
		UpdateGameObjects(dt);
		alpha::PhysicsWorld::MainWorld.Update(dt);
		m_camera.Position = m_playerObject.GetTransformComponent().Position;
	}

	void Draw() override {
		m_shader->Bind();

		m_shader->SendUniform("Timer", Time);
		m_shader->SendUniform("Transform", glm::translate(glm::vec3(0.5, 0, 0)));

		m_camera.Draw(*m_shader, (float)MainGame->GetWindow()->SizeX / (float)MainGame->GetWindow()->SizeY);
		
		alpha::ResourceManager::Textures["ground"].Bind();
		m_groundObject.Draw(*m_shader);

		alpha::ResourceManager::Textures["tank1"].Bind();
		m_playerObject.Draw(*m_shader);
		m_enemyObject.Draw(*m_shader);

		alpha::ResourceManager::Textures["wall"].Bind();
		m_testObject.Draw(*m_shader);
		m_testCircle.Draw(*m_shader);
		m_testPolygon.Draw(*m_shader);
	}

private:
	float Time;

	alpha::Camera m_camera;

	alpha::GameObject m_playerObject;
	alpha::GameObject m_enemyObject;

	alpha::GameObject m_testObject;
	alpha::GameObject m_groundObject;
	alpha::GameObject m_testCircle;
	alpha::GameObject m_testPolygon;

	std::shared_ptr<alpha::Shader> m_shader;
	alpha::Sound m_sound;
};

alpha::Scene* alpha::CreateMainScene() {
	return new MainScene();
}