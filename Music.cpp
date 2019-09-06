#include "Music.h"
#include <SDL.h>
#include <SDL_mixer.h>

void Music::PlayBGM(int num) {
	Mix_PlayMusic(Musics[num], -1);
}

void Music::PlaySE(int num) {
	Mix_PlayChannel(-1, SEs[num], 0);
}

void Music::StopBGM() {
	Mix_HaltMusic();
}

void Music::ChangeVolume(int BGM, int SE) {
	Mix_VolumeMusic(BGM);
	Mix_Volume(-1, SE);
}

Music::Music(){
	SDL_version *mixer_version = (SDL_version *)Mix_Linked_Version();
	SDL_Log(u8"SDL_Mixer_%d.%d.%d Initialization Start!\n", mixer_version->major, mixer_version->minor, mixer_version->patch);
	int flag = MIX_INIT_MP3;
	int ret = Mix_Init(flag);
	if (ret & flag != flag) {
		SDL_Log(u8"SDL_Mixer Initialization failed...\n");
		SDL_Log(u8"error:%s", Mix_GetError());
	}
	SDL_Log(u8"SDL_Mixer API Initialization Start!\n");
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		SDL_Log(u8"SDL_Mixer API Initialization failed...\n");
		SDL_Log(u8"error:%s", Mix_GetError());
	}
	Mix_AllocateChannels(48);

	Musics.emplace_back(Mix_LoadMUS("01.wav"));
	Musics.emplace_back(Mix_LoadMUS("02.wav"));

	SEs.emplace_back(Mix_LoadWAV("ok.mp3"));
	SEs.emplace_back(Mix_LoadWAV("start.mp3"));
	SEs.emplace_back(Mix_LoadWAV("pose.mp3"));
	SEs.emplace_back(Mix_LoadWAV("change.mp3"));
	SEs.emplace_back(Mix_LoadWAV("nc94540.mp3"));
	SEs.emplace_back(Mix_LoadWAV("nc100040.mp3"));
	SEs.emplace_back(Mix_LoadWAV("nc104118.mp3"));
	SEs.emplace_back(Mix_LoadWAV("failed.mp3"));
	SEs.emplace_back(Mix_LoadWAV("top.mp3"));
	SEs.emplace_back(Mix_LoadWAV("car.mp3"));
}


Music::~Music(){
	SDL_Log(u8"Music file closing...\n");
	for(Mix_Music *mus:Musics)Mix_FreeMusic(mus);
	for (Mix_Chunk *se : SEs)Mix_FreeChunk(se);
	SDL_Log(u8"Mixer API Quitting...\n");
	Mix_CloseAudio();
	SDL_Log(u8"Mixer Quitting...\n");
	Mix_Quit();
}
