#include "Pose.h"

Pose::Pose(std::shared_ptr<Graphic> g, std::shared_ptr<Music> m) :graphic(g), music(m), posey(0) {
	option.reset(new Option(graphic, music));
}

void Pose::draw() {
	graphic->RenderFillRect(0, 0, 800, 640, 0, 255, 0, 128, SDL_BLENDMODE_NONE);
	graphic->Render_UTF8_Titletext(u8"Pose Menu", SDL_TTF_CENTERING, 0, 64, 255, 255, 255, 0);
	graphic->Render_UTF8_Text(u8"Continue", SDL_TTF_CENTERING, 0, 640 - 160, 255, 255, 255, 0);
	graphic->Render_UTF8_Text(u8"Restart", SDL_TTF_CENTERING, 0, 640 - 128, 255, 255, 255, 0);
	graphic->Render_UTF8_Text(u8"Option", SDL_TTF_CENTERING, 0, 640 - 96, 255, 255, 255, 0);
	graphic->Render_UTF8_Text(u8"Return to Mainmenu", SDL_TTF_CENTERING, 0, 640 - 64, 255, 255, 255, 0);
	graphic->RenderDrawRect(314, posey * 32 + 475, 173, 24, 255, 255, 255, 0, SDL_BLENDMODE_NONE);
	graphic->update();
}

int Pose::Start() {
	SDL_Event e;
	draw();
	while (true) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
				case SDL_QUIT:
					return -2;
				case SDL_KEYDOWN:
					switch (e.key.keysym.sym) {
						case SDLK_ESCAPE:
							music->PlaySE(0);
							return 0;
						case SDLK_z:
							music->PlaySE(0);
							switch (posey) {
								case 0:
									music->PlaySE(9);
									return 0;
								case 1:
									music->PlaySE(9);
									return 1;
								case 2:
									option->Start();
									break;
								case 3:
									music->PlayBGM(0);
									return -1;
							}
						case SDLK_UP:
							if (posey > 0) {
								music->PlaySE(3);
								posey--;
								draw();
							} else if (posey == 0) {
								music->PlaySE(3);
								posey = 3;
								draw();
							}
							break;
						case SDLK_DOWN:
							if (posey < 3) {
								music->PlaySE(3);
								posey++;
								draw();
							} else if (posey == 3) {
								music->PlaySE(3);
								posey = 0;
								draw();
							}
							break;
					}
					break;
			}
		}
	}
}

Pose::~Pose() {
}
