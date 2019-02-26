#pragma once

#include <iostream>

#include <OpenAL/al.h>
#include <OpenAL/alc.h>

namespace alpha {
	class AudioManager {
	public:
		AudioManager();

		static void ListAudioDevices(const ALCchar *devices);

		static void CheckError();

		static float MasterVolume;

		~AudioManager();
	private:
		ALCdevice *m_device;
		ALCcontext *m_context;
	};
}