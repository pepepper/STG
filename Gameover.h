#pragma once
#include "Graphic.h"
#include "Music.h"
#include "Option.h"
#include <memory>

class Gameover
{
public:
	Gameover(std::shared_ptr<Graphic> g, std::shared_ptr<Music> m);
	void draw(int score);
	void Start(int score);
	~Gameover();
private:
	std::shared_ptr<Graphic> graphic;
	std::shared_ptr<Music> music;
};

