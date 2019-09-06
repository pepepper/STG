#include "Graphic.h"


void Graphic::Render_StartMenu(int menuy) {
	Render_UTF8_Text(u8"Story Mode", SDL_TTF_CENTERING, 0, 640 - 160, 192, 128, 128, 0);
	Render_UTF8_Text(u8"Endless Mode", SDL_TTF_CENTERING, 0, 640 - 128, 255, 0, 0, 0);
	Render_UTF8_Text(u8"Option", SDL_TTF_CENTERING, 0, 640 - 96, 255, 0, 0, 0);
	Render_UTF8_Text(u8"Exit", SDL_TTF_CENTERING, 0, 640 - 64, 255, 0, 0, 0);
	RenderDrawRect(340, menuy * 32 + 475, 120, 24, 255, 0, 0, 0, SDL_BLENDMODE_NONE);
}

void Graphic::RenderBG(int num,SDL_Rect *dest) {
	SDL_RenderCopy(renderer, bg[num], NULL, dest);
}

void Graphic::RenderBullet(int bullettype, int x, int y){
	SDL_Rect rect = { x, y, 16, 16 };
	SDL_RenderCopy(renderer, bullet[bullettype], NULL, &rect);
}

void Graphic::RenderPlayer(int num,int x,int y) {
	SDL_Rect rect = { x, y, 64, 64 };
	SDL_RenderCopy(renderer, player[num], NULL, &rect);
}

void Graphic::RenderEnemy(int enemytype, int num, int x, int y) {
	SDL_Rect rect = { x, y, 64, 64 };
	SDL_RenderCopy(renderer, enemy[enemytype][num], NULL, &rect);
}

void Graphic::RenderEnemyBullet(int bullettype, int x, int y){
	SDL_Rect rect = { x, y, 16, 16 };
		SDL_RenderCopyEx(renderer, bullet[bullettype], NULL, &rect, 180, NULL, SDL_FLIP_NONE);
}

SDL_Texture *Graphic::IMG_Load_Texture( const char *filename) {
	SDL_RWops *file;
	SDL_Surface *temp;
	SDL_Texture *ret;
	file = SDL_RWFromFile(filename, "rb");
	temp = IMG_Load_RW(file, 0);
	ret = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_FreeSurface(temp);
	SDL_RWclose(file);
	return ret;
}

void Graphic::Render_UTF8_Text(std::string text, int position, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_Surface *textSurface;
	SDL_Texture *texture;
	SDL_Rect dst = { x, y, 0, 0 };
	SDL_Color color = { r, g, b, a };
	int textx;
	int texty;
	textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
	texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	TTF_SizeUTF8(font, text.c_str(), &textx, &texty);
	dst.w = textx;
	dst.h = texty;
	switch (position) {
		case SDL_TTF_LEFT:
			dst.x = 0;
			break;
		case SDL_TTF_CENTERING:
			dst.x = 400 - (textx / 2);
			break;
		case SDL_TTF_RIGHT:
			dst.x = 800 - textx;
			break;
	}
	SDL_RenderCopy(renderer, texture, NULL, &dst);
	SDL_DestroyTexture(texture);
}

void Graphic::Render_UTF8_Titletext(std::string text, int position, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_Surface *textSurface;
	SDL_Texture *texture;
	SDL_Rect dst = { x, y, 0, 0 };
	SDL_Color color = { r, g, b, a };
	int textx;
	int texty;
	textSurface = TTF_RenderUTF8_Blended(titlefont, text.c_str(), color);
	texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	TTF_SizeUTF8(titlefont, text.c_str(), &textx, &texty);
	dst.w = textx;
	dst.h = texty;
	switch (position) {
		case SDL_TTF_LEFT:
			dst.x = 0;
			break;
		case SDL_TTF_CENTERING:
			dst.x = 400 - (textx / 2);
			break;
		case SDL_TTF_RIGHT:
			dst.x = 800 - textx;
			break;
	}
	SDL_RenderCopy(renderer, texture, NULL, &dst);
	SDL_DestroyTexture(texture);
}

void Graphic::RenderFillRect(int x, int y, int w, int h, Uint8 R, Uint8 G, Uint8 B, Uint8 A, SDL_BlendMode blend) {
	SDL_Rect rect = { x, y, w, h };
	SDL_SetRenderDrawBlendMode(renderer, blend);
	SDL_SetRenderDrawColor(renderer, R, G, B, A);
	SDL_RenderFillRect(renderer, &rect);
}

void Graphic::RenderDrawRect(int x, int y, int w, int h, Uint8 R, Uint8 G, Uint8 B, Uint8 A, SDL_BlendMode blend) {
	SDL_Rect rect = { x, y, w, h };
	SDL_SetRenderDrawBlendMode(renderer, blend);
	SDL_SetRenderDrawColor(renderer, R, G, B, A);
	SDL_RenderDrawRect(renderer, &rect);
}

void Graphic::GetSystemInfo() {
	SDL_Log(u8"Platform %s\n", SDL_GetPlatform());
	SDL_Log(u8"Number of Logical CPU Unit %d\n", SDL_GetCPUCount());
	SDL_Log(u8"Size of CPU L1 Cache Line Size %dByte\n", SDL_GetCPUCacheLineSize());
	SDL_Log(u8"Usable CPU Features:");
	if (SDL_Has3DNow() == SDL_TRUE)SDL_Log(u8" 3DNow");
	if (SDL_HasAltiVec() == SDL_TRUE)SDL_Log(u8" AltiVec");
	if (SDL_HasAVX() == SDL_TRUE)SDL_Log(u8" AVX");
	if (SDL_HasAVX2() == SDL_TRUE)SDL_Log(u8" AVX2");
	if (SDL_HasMMX() == SDL_TRUE)SDL_Log(u8" MMX");
	if (SDL_HasRDTSC() == SDL_TRUE)SDL_Log(u8" RDTSC");
	if (SDL_HasSSE() == SDL_TRUE)SDL_Log(u8" SSE");
	if (SDL_HasSSE2() == SDL_TRUE)SDL_Log(u8" SSE2");
	if (SDL_HasSSE3() == SDL_TRUE)SDL_Log(u8" SSE3");
	if (SDL_HasSSE41() == SDL_TRUE)SDL_Log(u8" SSE41");
	if (SDL_HasSSE42() == SDL_TRUE)SDL_Log(u8" SSE42");
	SDL_Log(u8"\nSystem Memory %dMB Installed\n", SDL_GetSystemRAM());
}

void Graphic::update() {
	SDL_RenderPresent(renderer);
}

Graphic::Graphic(){
	SDL_version version, *ttf_version = (SDL_version *)TTF_Linked_Version(), *image_version = (SDL_version *)IMG_Linked_Version();
	SDL_Log(u8"起動中・・・ この画面には触らないでね");
	SDL_GetVersion(&version);
	SDL_Log(u8"SDL_%d.%d.%d Initialization Start!\n", version.major, version.minor, version.patch);
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		SDL_Log(u8"SDL Initialization failed...\n");
		SDL_Log(u8"error:%s", SDL_GetError());
	}
	GetSystemInfo();
	SDL_Log(u8"SDL_TTF_%d.%d.%d Initialization Start!\n", ttf_version->major, ttf_version->minor, ttf_version->patch);
	if (TTF_Init() == -1) {
		SDL_Log(u8"SDL_TTF Initialization failed...\n");
		SDL_Log(u8"error:%s", TTF_GetError());
	}
	SDL_Log(u8"SDL_Image_%d.%d.%d Initialization Start!\n", image_version->major, image_version->minor, image_version->patch);
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		SDL_Log(u8"SDL_Image Initialization failed...\n");
		SDL_Log(u8"error:%s", IMG_GetError());
	}

	SDL_Log(u8"Creating Window and Renderer\n");
	if (SDL_CreateWindowAndRenderer(800, 640, NULL, &window, &renderer)) {
		SDL_Log(u8"Create Window and Renderer failed...\n");
		SDL_Log(u8"error:%s\n", SDL_GetError());
	}
	SDL_SetWindowTitle(window, u8"Shooting Game");
	RenderFillRect( 0, 0, 800, 640, 0, 255, 0, 0, SDL_BLENDMODE_NONE);
	SDL_Log(u8"Font file Loading...\n");
	font = TTF_OpenFontRW(fontfile, 0, 16);
	TTF_SetFontStyle(font, TTF_STYLE_BOLD);
	SDL_RWseek(fontfile, 0, RW_SEEK_SET);
	titlefont = TTF_OpenFontRW(fontfile, 0, 48);
	if (!font || !titlefont) {
		SDL_Log(u8"Font file Load failed...\n");
		SDL_Log(u8"error:%s", TTF_GetError());
	}

	bg.emplace_back(IMG_Load_Texture( "opening.png"));
	bg.emplace_back(IMG_Load_Texture("bg.png"));

	player[0] = IMG_Load_Texture("player.png");
	player[1] = IMG_Load_Texture( "player_1.png");
	player[2] = IMG_Load_Texture("player_2.png");

	bullet[0] = IMG_Load_Texture( "bullet1.png");
	bullet[1] = IMG_Load_Texture("bullet2.png");
	bullet[2] = IMG_Load_Texture( "bullet3.png");

	enemy[0][0] = IMG_Load_Texture("siru1.png");
	enemy[0][1] = IMG_Load_Texture( "siru2.png");
	enemy[1][0] = IMG_Load_Texture("crx1.png");
	enemy[1][1] = IMG_Load_Texture("crx2.png");
	enemy[2][0] = IMG_Load_Texture( "boss1.png");
	enemy[2][1] = IMG_Load_Texture( "boss2.png");
	enemy[3][0] = IMG_Load_Texture("evo1.png");
	enemy[3][1] = IMG_Load_Texture( "evo2.png");
	enemy[4][0] = IMG_Load_Texture("imp1.png");
	enemy[4][1] = IMG_Load_Texture("imp2.png");
	enemy[5][0] = IMG_Load_Texture( "teki1_1.png");
	enemy[5][1] = IMG_Load_Texture( "teki1_2.png");

	SDL_RenderCopy(renderer, bg[0], NULL, NULL);
	Render_UTF8_Text(u8"Press Z key...", SDL_TTF_CENTERING, 0, 640 - 128, 255, 0, 0, 0);
	update();
}


Graphic::~Graphic(){
	SDL_Log(u8"Font file closing...\n");
	TTF_CloseFont(font);
	TTF_CloseFont(titlefont);
	SDL_RWclose(fontfile);
	SDL_Log(u8"Destroying Window and Renderer\n");
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Log(u8"Image Quitting...\n");
	IMG_Quit();
	SDL_Log(u8"TTF Quitting...\n");
	TTF_Quit();
	SDL_Log(u8"SDL Quitting...\n");
	SDL_Quit();
}
