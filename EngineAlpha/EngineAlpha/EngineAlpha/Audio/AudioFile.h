#pragma once

#include <string>

#include <iostream>
#include <fstream>
#include <vector>
#include <sndfile/sndfile.hh>

namespace alpha {
	class AudioFile {
	public:
		AudioFile();

		void LoadFile(std::string file);

		~AudioFile();

	private:
		unsigned int m_channels, m_samplerate;
	};
}