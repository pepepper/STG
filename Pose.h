#pragma once
#include "Graphic.h"
#include "Music.h"
#include "Option.h"
#include <memory>
class Pose{
public:
	Pose(std::shared_ptr<Graphic> g, std::shared_ptr<Music> m);
	void draw();
	int Start();
	~Pose();
private:
	std::shared_ptr<Option > option;
	std::shared_ptr<Graphic> graphic;
	std::shared_ptr<Music> music;
	int posey;
	SDL_Texture *playtex;
};

