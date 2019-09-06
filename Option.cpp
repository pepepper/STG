#include "Option.h"



Option::Option(std::shared_ptr<Graphic> g, std::shared_ptr<Music> m) :graphic(g), music(m), option(0) {
}

void Option::draw() {
	std::string text;
	graphic->RenderFillRect(0, 0, 800, 640, 0, 255, 0, 0, SDL_BLENDMODE_NONE);

	graphic->Render_UTF8_Titletext(u8"Option", SDL_TTF_CENTERING, 0, 96, 255, 255, 255, 0);
	text = u8"BGM            " + std::to_string(bgmvolume);
	if (option == 0)graphic->Render_UTF8_Text(text, SDL_TTF_CENTERING, 96, 194, 128, 128, 128, 0);
	else graphic->Render_UTF8_Text(text, SDL_TTF_CENTERING, 96, 194, 255, 255, 255, 0);

	text = u8"SE            " + std::to_string(sevolume);
	if (option == 1)graphic->Render_UTF8_Text(text, SDL_TTF_CENTERING, 96, 258, 128, 128, 128, 0);
	else graphic->Render_UTF8_Text(text, SDL_TTF_CENTERING, 96, 258, 255, 255, 255, 0);

	text = u8"Player            " + std::to_string(playernumset);
	if (option == 2)graphic->Render_UTF8_Text(text, SDL_TTF_CENTERING, 96, 322, 128, 128, 128, 0);
	else graphic->Render_UTF8_Text(text, SDL_TTF_CENTERING, 96, 322, 255, 255, 255, 0);

	if (!scroll)text = u8"Scroll            Verical";
	else text = u8"Scroll            Horizontal";
	if (option == 3)graphic->Render_UTF8_Text(text, SDL_TTF_CENTERING, 96, 388, 128, 128, 128, 0);
	else graphic->Render_UTF8_Text(text, SDL_TTF_CENTERING, 96, 388, 255, 255, 255, 0);

	if (option == 4)graphic->Render_UTF8_Text(u8"Exit", SDL_TTF_CENTERING, 96, 452, 128, 128, 128, 0);
	else graphic->Render_UTF8_Text(u8"Exit", SDL_TTF_CENTERING, 96, 452, 255, 255, 255, 0);
	graphic->update();
}

int Option::Start() {
	SDL_Event e;
	draw();
	while (true) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				return -1;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_z:
					if (option == 4) {
						music->PlaySE(0);
						music->ChangeVolume(bgmvolume, sevolume);
						return 0;
					}
				case SDLK_UP:
					if (option > 0)option--;
					else if (option == 0) option = 4;
					music->PlaySE(3);
					draw();
					break;
				case SDLK_DOWN:
					if (option < 4)option++;
					else if (option == 4)	option = 0;
					music->PlaySE(3);
					draw();
					break;
				case SDLK_LEFT:
					music->PlaySE(3);
					switch (option) {
					case 0:
						if (bgmvolume > 0)bgmvolume--;
						break;
					case 1:
						if (sevolume > 0) sevolume--;
						break;
					case 2:
						if (playernumset > 1) playernumset--;
						break;
					case 3:
						if (scroll > 0) scroll--;
						break;
					}
					draw();
					break;
				case SDLK_RIGHT:
					music->PlaySE(3);
					switch (option) {
					case 0:
						if (bgmvolume < 128) bgmvolume++;
						break;
					case 1:
						if (sevolume < 128) sevolume++;
						break;
					case 2:
						if (playernumset < 5) playernumset++;
						break;
					case 3:
						if (scroll < 1) scroll++;
						break;
					}
					draw();
					break;
				}
			}
		}
	}
}

Option::~Option() {
}
