#include "Gameover.h"

Gameover::Gameover(std::shared_ptr<Graphic> g, std::shared_ptr<Music> m) :graphic(g), music(m) {
}

void Gameover::draw(int score) {
	std::string text;
	graphic->RenderFillRect(0, 0, 800, 640, 0, 255, 0, 128, SDL_BLENDMODE_BLEND);
	graphic->Render_UTF8_Text(u8"Game Over", SDL_TTF_CENTERING, 0, 64, 255, 255, 255, 0);
	text = u8"Score:" + std::to_string(score);
	graphic->Render_UTF8_Text(text, SDL_TTF_CENTERING, 0, 256, 255, 255, 255, 0);
	graphic->Render_UTF8_Text(u8"Press Z Key", SDL_TTF_CENTERING, 0, 320, 255, 255, 255, 0);
	graphic->update();
}

void Gameover::Start(int score) {
	SDL_Event e;
	draw(score);
	while (true) {
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_z:
					return;
				}
				break;
			}
		}
	}
}

Gameover::~Gameover() {
}
