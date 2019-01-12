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
		float MoveVelocity, TankRotation, TurretRotation;

		void Move(float velocity);
		void Rotation(float rot);
	private:
		alpha::GameObject m_turretObject;
	};
}