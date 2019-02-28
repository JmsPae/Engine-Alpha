#pragma once

#include "Core/Game.h"
#include "Core/Log.h"

extern alpha::Scene* alpha::CreateMainScene();

int main(int argc, char** argv) {
	alpha::Log::Init();
	LOG("Initialized Logging.");

	auto game = new alpha::Game();
	alpha::AudioManager::MasterVolume = 0.5f;
	game->Start(alpha::CreateMainScene());

	delete game;

	return 0;
}
