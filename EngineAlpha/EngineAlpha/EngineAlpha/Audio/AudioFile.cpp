#include "AudioFile.h"

namespace alpha {
	AudioFile::AudioFile() {

	}

	void AudioFile::LoadFile(std::string filename) {
		std::string path = "Resources/Audio/" + filename;
		if (std::ifstream(path)) {
			SndfileHandle myf = SndfileHandle(&(path).c_str()[0]);
			std::vector<float> array(unsigned int(myf.frames()));
			myf.read(&array[0], int(myf.frames()));

			printf("%i channels \n", myf.channels());
			printf("%i samplerate \n", myf.samplerate());

		}
	}

	AudioFile::~AudioFile() {

	}
}