#pragma once

#include <string>

#include <sndfile/sndfile.hh>

#define BUFFER_LENGTH 1024

namespace alpha {
	class AudioFile {
	public:
		AudioFile();

		void LoadFile(std::string file);

		~AudioFile();
	};
}