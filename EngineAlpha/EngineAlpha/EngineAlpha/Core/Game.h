#pragma once

#include <time.h>

#include "../Graphics/Window.h"
#include "InputManager.h"

namespace alpha {
	class Game {
	public:
		Game() : Time((double)clock() / CLOCKS_PER_SEC), GameWindow(new Window()){ }

		void Start() {
			Init();

			int TotalFrames = 0;
			float LastTime = 0, FrameTimer = 0;
			while (GameWindow->IsOpen()) {
				Time = glfwGetTime();
				float dt = Time - LastTime;
				LastTime = Time;

				FrameTimer += dt;
				TotalFrames++;
				if (FrameTimer >= 1) {
					printf("%f FPS | %f MS \n", (float)TotalFrames / FrameTimer, (FrameTimer / (float)TotalFrames) * 1000.f);
					TotalFrames = 0;
					FrameTimer = 0;
				}

				GameWindow->PollEvents();

				Update(dt);

				GameWindow->Clear();

				Draw();

				GameWindow->SwapBuffers();

			}
		}

		~Game() { Finish(); }

		virtual void Init() {}
		virtual void Update(float dt) {}
		virtual void Draw() {}
		virtual void Finish() {}
	protected:
		Window *GameWindow;
		InputManager InputManager;
		double Time;
	};

}