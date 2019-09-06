#include "StartMenu.h"


StartMenu::StartMenu(std::shared_ptr<Graphic> g, std::shared_ptr<Music> m) :graphic(g), music(m),menuy(0) {
}

void StartMenu::draw() {
	graphic->RenderBG(0,NULL);
	graphic->Render_UTF8_Text(u8"Story Mode", SDL_TTF_CENTERING, 0, 640 - 160, 192, 128, 128, 0);
	graphic->Render_UTF8_Text(u8"Endless Mode", SDL_TTF_CENTERING, 0, 640 - 128, 255, 0, 0, 0);
	graphic->Render_UTF8_Text(u8"Option", SDL_TTF_CENTERING, 0, 640 - 96, 255, 0, 0, 0);
	graphic->Render_UTF8_Text(u8"Exit", SDL_TTF_CENTERING, 0, 640 - 64, 255, 0, 0, 0);
	graphic->RenderDrawRect(340, menuy * 32 + 475, 120, 24, 255, 0, 0, 0, SDL_BLENDMODE_NONE);
	graphic->update();
}

int StartMenu::Start() {
	SDL_Event e;
	if(!Mix_PlayingMusic())music->PlayBGM(0);
	draw();
	while (true) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
				case SDL_KEYDOWN:
					switch (e.key.keysym.sym) {
						case SDLK_z:
							music->PlaySE(0);
							return menuy;
						case SDLK_UP:
							if (menuy > 0)menuy--;
							else if (menuy == 0) menuy = 3;
							music->PlaySE(3);
							draw();
							break;
						case SDLK_DOWN:
							if (menuy < 3)menuy++;
							else if (menuy == 3) menuy = 0;
							music->PlaySE(3);
							draw();
							break;
					}
			}
		}
	}
}

StartMenu::~StartMenu() {
}
