#pragma once
#include "Graphic.h"
#include "Music.h"
#include <memory>
class StartMenu {
public:
	StartMenu(std::shared_ptr<Graphic> g, std::shared_ptr<Music> m);
	void draw();
	int Start();
	~StartMenu();
private:
	std::shared_ptr<Graphic> graphic;
	std::shared_ptr<Music> music;
	int menuy;
};

