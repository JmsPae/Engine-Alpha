#include "Tank.h"

namespace game {
	Tank::Tank(float health) : Health(health), TurretDir(glm::vec2(0)), m_colliderComponent(new alpha::QuadColliderComponent(glm::vec2(0.975f, 0.7f), 60000.f)), m_quadComponent(new alpha::QuadComponent()), m_turretQuadComponent(new alpha::QuadComponent()) {

	}

	void Tank::Init() {
		m_colliderComponent->Friction = 3.f; // Dampening is already applied manually
		Parent->AddComponent(m_colliderComponent);
		Parent->AddComponent(m_quadComponent);
		m_turretObject.AddComponent(m_turretQuadComponent);

		TankInit();
	}

	void Tank::Update(float dt) {
		TankUpdate(dt);
		
		m_turretObject.Position = Parent->Position;
		m_turretObject.Rotation = atan2f(TurretDir.y, TurretDir.x);
		m_turretObject.Update(dt);

		
		//m_colliderComponent->SetVelocity(glm::vec2(cos(m_colliderComponent->GetRotation() + glm::radians(90.f)), sin(m_colliderComponent->GetRotation() + glm::radians(90.f))) * glm::distance(glm::vec2(0), m_colliderComponent->GetVelocity()));
		/*m_colliderComponent->SetVelocity(m_colliderComponent->GetVelocity() - (m_colliderComponent->GetVelocity() * dt * 2.f));
		
		m_colliderComponent->SetAngularVelocity(m_colliderComponent->GetAngularVelocity() - (m_colliderComponent->GetAngularVelocity() * dt * 3.f));*/
	}

	void Tank::Draw(alpha::Shader & shader) {
		m_quadComponent->Draw(shader);
		alpha::ResourceManager::Textures["tank1_t"].Bind();
		m_turretObject.Draw(shader);
		alpha::ResourceManager::Textures["tank1"].Bind();
		
	}

	Tank::~Tank() {

	}
	
	void Tank::SetMove(float velocity) {
		m_colliderComponent->SetVelocity(m_colliderComponent->GetVelocity() + (glm::vec2(cos(m_colliderComponent->GetRotation()), sin(m_colliderComponent->GetRotation())) * velocity));
	}

	void Tank::SetRotation(float rot) {
		m_colliderComponent->SetAngularVelocity(m_colliderComponent->GetAngularVelocity() + rot);
	}

	void Tank::SetTurretDirection(glm::vec2 dir) {
		TurretDir = dir;
	}

	void Tank::SetColor(glm::vec4 color) {
		m_quadComponent->Color = color;
		m_turretQuadComponent->Color = color;
	}
}