#include "AudioManager.h"

namespace alpha {
	float AudioManager::MasterVolume = 1.f;

	AudioManager::AudioManager() {
		m_device = alcOpenDevice(nullptr);
		if (!m_device) {
			printf("OpenAL device failed to initialize!\n");
		}

		ListAudioDevices(alcGetString(nullptr, ALC_DEVICE_SPECIFIER));

		m_context = alcCreateContext(m_device, nullptr);
		if (!alcMakeContextCurrent(m_context))
			CheckError();

		//TODO: Add proper listener class!
		ALfloat listenerOri[] = { 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f };
		alListener3f(AL_POSITION, 0, 0, 1.0f);
		CheckError();
		alListener3f(AL_VELOCITY, 0, 0, 0);
		CheckError();
		alListenerfv(AL_ORIENTATION, listenerOri);
		CheckError();
	}

	void AudioManager::ListAudioDevices(const ALCchar * devices) {
		const ALCchar *device = devices, *next = devices + 1;
		size_t len = 0;

		fprintf(stdout, "Devices list:\n");
		fprintf(stdout, "----------\n");
		while (device && *device != '\0' && next && *next != '\0') {
			fprintf(stdout, "%s\n", device);
			len = strlen(device);
			device += (len + 1);
			next += (len + 2);
		}
		fprintf(stdout, "----------\n");
	}

	void AudioManager::CheckError() {
		ALCenum error = alGetError();
		if (error != AL_NO_ERROR)
			printf("OpenAL error %i\n", error);
	}

	AudioManager::~AudioManager() {
		m_device = alcGetContextsDevice(m_context);
		alcMakeContextCurrent(NULL);
		alcDestroyContext(m_context);
		alcCloseDevice(m_device);
	}
}