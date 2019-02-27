#include "AudioFile.h"

#include "../Core/Log.h"

namespace alpha {
	AudioFile::AudioFile() {

	}

	void AudioFile::LoadFile(std::string filename) {
		std::string path = "Resources/Audio/" + filename;
		if (std::ifstream(path)) {
			SndfileHandle myf = SndfileHandle(&(path).c_str()[0]);
			m_data = std::vector<short>(unsigned int(myf.frames()));
			myf.read(&m_data[0], int(myf.frames()));

			m_channels = myf.channels();
			m_samplerate = myf.samplerate();
			m_frames = (unsigned int)myf.frames();
			m_format = myf.format();

			DEBUG("{} channels", myf.channels());
			DEBUG("{} samplerate", myf.samplerate());
			DEBUG("{} format", myf.format());
			DEBUG("{} frames", (int)myf.frames());
			DEBUG("{0} wav16 {1} wavu8", SF_FORMAT_WAV | SF_FORMAT_PCM_16, SF_FORMAT_WAV | SF_FORMAT_PCM_U8);
			DEBUG("{} bytes", m_data.size() * sizeof(short));
		}
	}

	unsigned int AudioFile::GetChannels() {
		return m_channels;
	}

	unsigned int AudioFile::GetSampleRate() {
		return m_samplerate;
	}

	unsigned int AudioFile::GetFrames() {
		return m_frames;
	}

	unsigned int AudioFile::GetFormat() {
		return m_format;
	}

	std::vector<short> &AudioFile::GetData() {
		return m_data;
	}

	AudioFile::~AudioFile() {

	}
}