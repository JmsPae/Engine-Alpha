#pragma once

#include <EngineAlpha/Engine.h>

namespace game {
	class Tank : public alpha::Component {
	public:
		Tank(float health = 20.f);

		virtual void TankInit() {}
		void Init() override;
		virtual void TankUpdate(float dt) {}
		void Update(float dt) override;
		void Draw(alpha::Shader &shader) override;

		~Tank();

		float Health;
	protected:
		float Velocity, TurretRotation;

		void SetMove(float velocity);
		void SetRotation(float rot);
		void SetTurretRotation(float rot);
	private:
		alpha::GameObject m_turretObject;
		alpha::QuadColliderComponent *m_colliderComponent;
	};
}