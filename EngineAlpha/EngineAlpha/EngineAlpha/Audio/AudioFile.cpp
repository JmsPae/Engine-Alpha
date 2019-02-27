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

			/*printf("%i channels \n", myf.channels());
			printf("%i samplerate \n", myf.samplerate());
			printf("%i format \n", myf.format());
			printf("%i frames \n", (int)myf.frames());
			printf("%i wav16 %i wavu8 \n", SF_FORMAT_WAV|SF_FORMAT_PCM_16, SF_FORMAT_WAV|SF_FORMAT_PCM_U8);
			printf("%i bytes \n", m_data.size() * sizeof(short));*/

			DEBUG("%i channels", myf.channels());
			DEBUG("%i samplerate", myf.samplerate());
			DEBUG("%i format", myf.format());
			DEBUG("%i frames", (int)myf.frames());
			DEBUG("%i wav16 %d wavu8", SF_FORMAT_WAV | SF_FORMAT_PCM_16, SF_FORMAT_WAV | SF_FORMAT_PCM_U8);
			DEBUG("%i bytes", m_data.size() * sizeof(short));
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