#pragma once

#include <time.h>

#include "../Graphics/Window.h"

namespace alpha {
	class Game {
	public:
		Game() : Time((double)clock() / CLOCKS_PER_SEC), GameWindow(new Window()){ }

		void Start() {
			Init();

			float LastTime = 0;
			while (GameWindow->IsOpen()) {
				Time = ((double)clock() / CLOCKS_PER_SEC);
				float dt = Time - LastTime;
				LastTime = Time;

				GameWindow->PollEvents();

				Update(dt);

				GameWindow->Clear();

				Draw();

				GameWindow->SwapBuffers();

			}
			Finish();
		}

		virtual void Init() {}
		virtual void Update(float dt) {}
		virtual void Draw() {}
		virtual void Finish() {}
	protected:
		Window *GameWindow;
		double Time;
	};

}