#include "AudioFile.h"

namespace alpha {
	AudioFile::AudioFile() {

	}

	void AudioFile::LoadFile(std::string filename) {
		short buffer[BUFFER_LENGTH];

		SndfileHandle file;

		file = SndfileHandle(filename);

		printf("Opened file '%s'\n", filename.c_str());
		printf("    Sample rate : %d\n", file.samplerate());
		printf("    Channels    : %d\n", file.channels());

		file.read(buffer, BUFFER_LENGTH);
		
	}

	AudioFile::~AudioFile() {

	}
}