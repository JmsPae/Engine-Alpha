#pragma once

namespace game {
	class Tank {
	public:
		Tank();
		~Tank();

		float Health;
	protected:
		void Move(float Velocity);
	};
}