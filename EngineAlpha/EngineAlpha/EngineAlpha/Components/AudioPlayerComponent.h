#pragma once

#include "Component.h"
#include "../Audio/Sound.h"

namespace alpha {

	class AudioPlayerComponent : public Component {
	public:

		AudioPlayerComponent();
		AudioPlayerComponent(Sound *sound);
		~AudioPlayerComponent();

		void Init() override;

		void Update(float delta) override;

		void Play();
		void Stop();

		void SetSound(Sound *sound);

	private:
		Sound *m_sound;
	};
}