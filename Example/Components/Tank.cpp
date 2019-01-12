#include "Tank.h"

namespace game {
	Tank::Tank(float health) : Health(health), Velocity(0), TurretRotation(0), m_colliderComponent(new alpha::QuadColliderComponent(glm::vec2(0.75f, 1.f), 60000.f)){

	}

	void Tank::Init() {
		m_colliderComponent->Friction = 0.f; // Dampening is already applied manually
		Parent->AddComponent(m_colliderComponent);
		m_turretObject.AddComponent(new alpha::QuadComponent());

		TankInit();
	}

	void Tank::Update(float dt) {
		TankUpdate(dt);
		
		m_turretObject.Position = Parent->Position;
		m_turretObject.Rotation += TurretRotation * dt;
		m_turretObject.Update(dt);

		m_colliderComponent->SetVelocity(glm::vec2(cos(m_colliderComponent->GetRotation() + glm::radians(90.f)), sin(m_colliderComponent->GetRotation() + glm::radians(90.f))) * Velocity);
		Velocity -= Velocity * dt * 2.f;
		m_colliderComponent->SetAngularVelocity(m_colliderComponent->GetAngularVelocity() - (m_colliderComponent->GetAngularVelocity() * dt * 5.f));
		TurretRotation -= TurretRotation * dt * 10.f;
	}

	void Tank::Draw(alpha::Shader & shader) {
		alpha::ResourceManager::Textures["tank1_t"].Bind();
		m_turretObject.Draw(shader);
		alpha::ResourceManager::Textures["tank1"].Bind();
	}

	Tank::~Tank() {

	}
	
	void Tank::SetMove(float velocity) {
		Velocity += velocity;
	}

	void Tank::SetRotation(float rot) {
		m_colliderComponent->SetAngularVelocity(m_colliderComponent->GetAngularVelocity() + rot);
	}

	void Tank::SetTurretRotation(float rot) {
		TurretRotation += rot;
	}
}