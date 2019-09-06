#pragma once
#include "Graphic.h"
#include "Music.h"
#include <memory>
class Option{
public:
	Option(std::shared_ptr<Graphic> g, std::shared_ptr<Music> m);
	void draw();
	int Start();
	~Option();
	int bgmvolume = 128, sevolume = 128,  playernumset = 3, scroll = 0;
private:
	std::shared_ptr<Graphic> graphic;
	std::shared_ptr<Music> music;
	int option;
};

