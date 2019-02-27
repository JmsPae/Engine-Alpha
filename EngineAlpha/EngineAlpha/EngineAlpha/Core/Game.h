#pragma once

#include <time.h>

#include "../Audio/AudioManager.h"
#include "../Graphics/Window.h"
#include "InputManager.h"
#include "Scene.h"
#include "Log.h"

namespace alpha {
	class Timer {
	public:
		Timer() {
			m_lastTime = std::chrono::steady_clock::now();
		}

		template<class T>
		T Restart() {
			auto current = std::chrono::steady_clock::now();
			T restartTime = std::chrono::duration<T>(current - m_lastTime).count();
			m_lastTime = current;
			return restartTime;
		}

		void Restart() {
			m_lastTime = std::chrono::steady_clock::now();
		}

	private:
		std::chrono::time_point<std::chrono::steady_clock> m_lastTime;
	};

	class Scene;
	class Game {
	public:
		Game();

		void SetScene(Scene *newScene);
		void Start(Scene *startScene);

		InputManager &GetInputManager();
		Window *GetWindow();
		AudioManager &GetAudioManager();

		~Game();
	private:
		Scene *m_currentScene;
		Window *m_gameWindow;
		InputManager m_inputManager;
		AudioManager m_audioManager;
		Timer m_deltaTimer;
	};
}