#include "Tank.h"

namespace game {
	Tank::Tank(float health) : Health(health), TurretRotation(0), TurretAngularVelocity(0), m_colliderComponent(new alpha::QuadColliderComponent(glm::vec2(0.7f, 0.975f), 60000.f)){

	}

	void Tank::Init() {
		m_colliderComponent->Friction = 3.f; // Dampening is already applied manually
		Parent->AddComponent(m_colliderComponent);
		m_turretObject.AddComponent(new alpha::QuadComponent());

		TankInit();
	}

	void Tank::Update(float dt) {
		TankUpdate(dt);
		
		m_turretObject.Position = Parent->Position;
		TurretRotation += TurretAngularVelocity * dt;
		m_turretObject.Rotation = Parent->Rotation + TurretRotation;
		m_turretObject.Update(dt);

		
		//m_colliderComponent->SetVelocity(glm::vec2(cos(m_colliderComponent->GetRotation() + glm::radians(90.f)), sin(m_colliderComponent->GetRotation() + glm::radians(90.f))) * glm::distance(glm::vec2(0), m_colliderComponent->GetVelocity()));
		/*m_colliderComponent->SetVelocity(m_colliderComponent->GetVelocity() - (m_colliderComponent->GetVelocity() * dt * 2.f));
		
		m_colliderComponent->SetAngularVelocity(m_colliderComponent->GetAngularVelocity() - (m_colliderComponent->GetAngularVelocity() * dt * 3.f));*/
		TurretAngularVelocity -= TurretAngularVelocity * dt * 10.f;
	}

	void Tank::Draw(alpha::Shader & shader) {
		alpha::ResourceManager::Textures["tank1_t"].Bind();
		m_turretObject.Draw(shader);
		alpha::ResourceManager::Textures["tank1"].Bind();
	}

	Tank::~Tank() {

	}
	
	void Tank::SetMove(float velocity) {
		m_colliderComponent->SetVelocity(m_colliderComponent->GetVelocity() + (glm::vec2(cos(m_colliderComponent->GetRotation() + glm::radians(90.f)), sin(m_colliderComponent->GetRotation() + glm::radians(90.f))) * velocity));
	}

	void Tank::SetRotation(float rot) {
		m_colliderComponent->SetAngularVelocity(m_colliderComponent->GetAngularVelocity() + rot);
	}

	void Tank::SetTurretRotation(float rot) {
		TurretAngularVelocity += rot;
	}
}