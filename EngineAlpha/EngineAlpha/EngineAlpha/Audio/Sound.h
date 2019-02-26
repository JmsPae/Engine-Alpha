#pragma once

#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include "AudioFile.h"
#include "AudioManager.h"
#include "../Maths.h"

namespace alpha {
	class Sound {
	public:
		Sound();

		void SetAudioFile(AudioFile &file);

		void Play();

		~Sound();

		float Gain, Pitch;
		glm::vec3 Position, Velocity;
		bool Looping;
	private:
		unsigned int m_source, m_buffer;
		bool m_firstSet;

		static inline ALenum ToAlFormat(unsigned int channels, unsigned int format);
	};
}