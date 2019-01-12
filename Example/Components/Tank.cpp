#include "Tank.h"

namespace game {
	Tank::Tank(float health) : Health(health), MoveVelocity(0.f), TankRotation(0.f), TurretRotation(0) {

	}

	void Tank::Init() {
		m_turretObject.AddComponent(new alpha::QuadComponent());
		m_turretObject._AddedToScene();

		TankInit();
	}

	void Tank::Update(float dt) {
		TankUpdate(dt);
		Parent->Position += glm::vec2(cos(Parent->Rotation + glm::radians(90.f)), sin(Parent->Rotation + glm::radians(90.f))) * MoveVelocity * dt;
		Parent->Rotation += TankRotation * dt;

		m_turretObject.Position = Parent->Position;
		m_turretObject.Rotation += TurretRotation * dt;
		m_turretObject.Update(dt);

		MoveVelocity -= MoveVelocity * dt * 2;
		TankRotation -= TankRotation * dt * 5.f;
		TurretRotation -= TurretRotation * dt * 5.f;
	}

	void Tank::Draw(alpha::Shader & shader) {
		alpha::ResourceManager::Textures["tank1_t"].Bind();
		m_turretObject.Draw(shader);
		alpha::ResourceManager::Textures["tank1"].Bind();
	}

	Tank::~Tank() {

	}
	
	void Tank::Move(float velocity) {
		MoveVelocity += velocity;
	}

	void Tank::Rotation(float rot) {
		TankRotation += rot;
	}
}