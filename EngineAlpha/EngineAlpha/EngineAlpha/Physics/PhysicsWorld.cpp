#include "PhysicsWorld.h"

namespace alpha {
	PhysicsWorld::PhysicsWorld() : m_world(b2Vec2(0, 0)) {

	}

	void PhysicsWorld::Update(float dt) {
		m_world.Step(dt, m_VELOCITYITERATIONS, m_POSITIONITERATIONS);
	}

	PhysicsWorld::~PhysicsWorld() {

	}

	b2World *PhysicsWorld::GetB2World() {
		return &m_world;
	}

	PhysicsWorld PhysicsWorld::MainWorld = PhysicsWorld();
}