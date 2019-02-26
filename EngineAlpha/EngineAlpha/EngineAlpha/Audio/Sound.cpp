#include "Sound.h"

namespace alpha {
	Sound::Sound() {
		m_source = 0;
		m_buffer = 0;
		Position = glm::vec3(0);
		Velocity = glm::vec3(0);
		Pitch = 1.f;
		Gain = 1.f;
		Looping = false;
	}

	void Sound::SetAudioFile(AudioFile & file) {
		if (!m_source)
			alGenSources((ALuint)1, &m_source);
		if (!m_buffer)
			alGenBuffers((ALuint)1, &m_buffer);

		alSourcei(m_source, AL_BUFFER, 0);
		alBufferData(m_buffer, ToAlFormat(file.GetChannels(), file.GetFormat()), &file.GetData()[0], file.GetData().size() * sizeof(short), file.GetSampleRate());
		AudioManager::CheckError();
		alSourcei(m_source, AL_BUFFER, m_buffer);
	}

	void Sound::Play() {
		alSourcef(m_source, AL_PITCH, Pitch);
		alSourcef(m_source, AL_GAIN, Gain * AudioManager::MasterVolume);
		alSource3f(m_source, AL_POSITION, Position.x, Position.y, Position.z);
		alSource3f(m_source, AL_VELOCITY, Velocity.x, Velocity.y, Velocity.z);
		alSourcei(m_source, AL_LOOPING, AL_TRUE ? Looping : AL_FALSE);

		alSourcePlay(m_source);
	}

	Sound::~Sound() {
		alDeleteSources(1, &m_source);
		alDeleteBuffers(1, &m_buffer);
	}

	inline ALenum Sound::ToAlFormat(unsigned int channels, unsigned int format) {
		bool stereo = (channels > 1);
		if (stereo)
			return AL_FORMAT_STEREO16;
		return AL_FORMAT_MONO16;
		

		/*switch (format) {
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
		}*/
	}
}