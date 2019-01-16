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
		glm::vec2 TurretDir;

		void SetMove(float velocity);
		void SetRotation(float rot);
		void SetTurretDirection(glm::vec2 dir);
		void SetColor(glm::vec4 color);
	private:
		alpha::GameObject m_turretObject;
		alpha::QuadColliderComponent *m_colliderComponent;
		alpha::QuadComponent *m_quadComponent, *m_turretQuadComponent;
	};
}