#include "Sound.h"

namespace alpha {
	Sound::Sound(AudioFile &file) {
		alGenSources((ALuint)1, &m_source);

		//TODO add proper variables and whatnot
		alSourcef(m_source, AL_PITCH, 1);
		AudioManager::CheckError();
		alSourcef(m_source, AL_GAIN, 1);
		AudioManager::CheckError();
		alSource3f(m_source, AL_POSITION, 0, 0, 0);
		AudioManager::CheckError();
		alSource3f(m_source, AL_VELOCITY, 0, 0, 0);
		AudioManager::CheckError();
		alSourcei(m_source, AL_LOOPING, AL_FALSE);
		AudioManager::CheckError();

		alGenBuffers((ALuint)1, &m_buffer);
		alBufferData(m_buffer, ToAlFormat(file.GetChannels(), file.GetFormat()), file.GetData().data(), file.GetData().size() * sizeof(short), file.GetSampleRate());
		AudioManager::CheckError();
		alSourcei(m_source, AL_BUFFER, m_buffer);
	}

	void Sound::Play() {
		alSourcePlay(m_source);
	}

	Sound::~Sound() {
		alDeleteSources(1, &m_source);
		alDeleteBuffers(1, &m_buffer);
	}

	inline ALenum Sound::ToAlFormat(unsigned int channels, unsigned int format) {
		bool stereo = (channels > 1);

		switch (format) {
		case SF_FORMAT_WAV | SF_FORMAT_PCM_16:
			if (stereo)
				return AL_FORMAT_STEREO16;
			else
				return AL_FORMAT_MONO16;
		case SF_FORMAT_WAV | SF_FORMAT_PCM_U8:
			if (stereo)
				return AL_FORMAT_STEREO8;
			else
				return AL_FORMAT_MONO8;
		default:
			return -1;
		}
	}
}