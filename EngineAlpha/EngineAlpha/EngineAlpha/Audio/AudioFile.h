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

		unsigned int GetChannels();
		unsigned int GetSampleRate();
		unsigned int GetFrames();
		unsigned int GetFormat();

		std::vector<short> &GetData();

		~AudioFile();

	private:
		unsigned int m_channels, m_samplerate, m_frames, m_format;
		std::vector<short> m_data;
	};
}