#include "STG.h"

STG::STG() {
	graphic.reset(new Graphic());
	music.reset(new Music());
	start.reset(new StartMenu(graphic,music));
	option.reset(new Option(graphic, music));
}

void STG::Run() {
	SDL_Event e;
	music->PlayBGM(0);
	while (true) {
		SDL_WaitEvent(&e);
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_z)break;
		if (e.type == SDL_QUIT)return;
	}
	music->PlaySE(0);
	while (true) {
		int ret = start->Start();
		if (ret == 0)continue;//not implemented yet
		else if (ret == 1)
			while (true) {//endless start
				shoot.reset(new play(graphic, music, option->playernumset));
				music->StopBGM();
				ret = shoot->Start();
				if(ret == -2)return;
				if(ret == -1)break;
				if(ret == 1)continue;
			}
		else if (ret == 2) {//option
			if (option->Start() == -1)return;
			else continue;
		}
		else if (ret == 3)return;
	}
}

STG::~STG() {
}
