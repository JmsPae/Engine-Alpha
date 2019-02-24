#pragma once

#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include "AudioFile.h"
#include "AudioManager.h"

namespace alpha {
	class Sound {
	public:
		Sound(AudioFile &file);

		void Play();

		~Sound();
	private:
		unsigned int m_source, m_buffer;

		static inline ALenum ToAlFormat(unsigned int channels, unsigned int format);
	};
}