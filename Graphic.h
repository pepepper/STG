#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>
#include <vector> 
#define SDL_TTF_LEFT 0
#define SDL_TTF_CENTERING 1
#define SDL_TTF_RIGHT 2
#define SDL_TTF_FREE 3
class Graphic
{
public:
	void Render_StartMenu(int menuy);
	void RenderBG(int num,SDL_Rect *dest);
	void RenderBullet(int bullettype, int x, int y);
	void RenderPlayer(int num,int x, int y);
	void RenderEnemy(int enemytype, int num, int x, int y);
	void RenderEnemyBullet(int bullettype, int x, int y);
	SDL_Texture * IMG_Load_Texture( const char * filename);
	void Render_UTF8_Text( std::string text, int position, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void Render_UTF8_Titletext(std::string text, int position, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void RenderFillRect(int x, int y, int w, int h, Uint8 R, Uint8 G, Uint8 B, Uint8 A, SDL_BlendMode blend);
	void RenderDrawRect( int x, int y, int w, int h, Uint8 R, Uint8 G, Uint8 B, Uint8 A, SDL_BlendMode blend);
	void GetSystemInfo();
	void update();
	Graphic();
	~Graphic();
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_RWops *fontfile = SDL_RWFromFile("font.ttf", "rb");
	TTF_Font *font, *titlefont;
	SDL_Texture *player[3], *bullet[3], *enemy[6][2] ;
	std::vector<SDL_Texture *> bg;
};

