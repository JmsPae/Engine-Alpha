#include "AudioPlayerComponent.h"

namespace alpha {

	AudioPlayerComponent::AudioPlayerComponent() 
		: m_sound(nullptr) {
	}

	AudioPlayerComponent::AudioPlayerComponent(Sound *sound)
		: m_sound(sound) {
	}

	AudioPlayerComponent::~AudioPlayerComponent() {
	}

	void AudioPlayerComponent::Init() {
	}

	void AudioPlayerComponent::Update(float dt) {
	}

	void AudioPlayerComponent::Play() {
		if (m_sound != nullptr) {
			m_sound->Play();
		}
	}

	void AudioPlayerComponent::Stop() {
		static_assert(true, "not implemented.");
	}

	void AudioPlayerComponent::SetSound(Sound *sound) {
		m_sound = sound;
	}
}