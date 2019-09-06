#pragma once
#include <SDL_mixer.h>
#include <vector>
class Music
{
public:
	void PlayBGM(int num);
	void PlaySE(int num);
	void StopBGM();
	void ChangeVolume(int BGM, int SE);
	Music();
	~Music();
private:
	std::vector<Mix_Music *> Musics;
	std::vector < Mix_Chunk *> SEs;
};

