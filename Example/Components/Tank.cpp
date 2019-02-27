#include "Tank.h"

namespace game {
	Tank::Tank(float health) : Health(health), TurretDir(), m_tracerComponent(new alpha::QuadComponent()), m_colliderComponent(new alpha::QuadColliderComponent(glm::vec2(0.975f, 0.7f), 60000.f)), m_quadComponent(new alpha::QuadComponent()), m_turretQuadComponent(new alpha::QuadComponent()) {

		auto audioFile = new alpha::AudioFile();
		audioFile->LoadFile("test.wav");
		auto sound = new alpha::Sound();
		sound->SetAudioFile(*audioFile);
		m_audioPlayer = new alpha::AudioPlayerComponent(sound);
	}

	void Tank::Init() {
		m_colliderComponent->Friction = 3.f;
		Parent->AddComponent(m_colliderComponent);
		Parent->AddComponent(m_quadComponent);
		Parent->AddComponent(m_tracerComponent);
		Parent->AddComponent(m_audioPlayer);
		m_turretObject.AddComponent(m_turretQuadComponent);

		TankInit();
	}

	void Tank::Update(float dt) {
		TankUpdate(dt);
		
		m_turretObject.Position = Parent->Position;
		m_turretObject.Rotation = atan2f(TurretDir.y, TurretDir.x);
		m_turretObject.Update(dt);
	}

	void Tank::Draw(alpha::Shader & shader) {
		m_quadComponent->Draw(shader);
		alpha::ResourceManager::Textures["tank1_t"].Bind();
		m_turretObject.Draw(shader);
		alpha::ResourceManager::Textures["tank1"].Bind();
	}

	Tank::~Tank() {
	}
	
	void Tank::Fire(float damage) {

		m_audioPlayer->Play();

		alpha::RayCaster raycast;
		auto callback = raycast.CastRay(Parent->Position, Parent->Position + TurretDir * 100.f);
		if (callback.Hit) {
			printf("Hit! \n");
			callback.Collider->SetVelocity(callback.Collider->GetVelocity() + callback.RayDirection * 0.25f);

			auto tankComp = (Tank*)callback.Collider->Parent->GetComponent<Tank>();
			if (tankComp) {
				tankComp->Health -= damage;
				printf("%f \n", tankComp->Health);
			}
		}
	}

	void Tank::SetMove(float velocity) {
		m_colliderComponent->SetVelocity(m_colliderComponent->GetVelocity() + (glm::vec2(cos(m_colliderComponent->GetRotation()), sin(m_colliderComponent->GetRotation())) * velocity));
	}

	void Tank::SetRotation(float rot) {
		m_colliderComponent->SetAngularVelocity(m_colliderComponent->GetAngularVelocity() + rot);
	}

	void Tank::SetDirection(glm::vec2 dir) {
		m_colliderComponent->SetRotation(atan2f(dir.y - Parent->Position.y, dir.x - Parent->Position.x));
	}

	float Tank::GetRotation() {
		return m_colliderComponent->GetRotation();
	}

	void Tank::SetTurretDirection(glm::vec2 dir) {
		TurretDir = dir;
	}

	void Tank::SetColor(alpha::Color color) {
		m_quadComponent->Color = color;
		m_turretQuadComponent->Color = color;
	}
}