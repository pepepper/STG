#pragma once
#include "Music.h"
#include "Graphic.h"
#include "StartMenu.h"
#include "Option.h"
#include "play.h"
class STG{
public:
	STG();
	void Run();
	~STG();
private:
	std::shared_ptr<Graphic> graphic;
	std::shared_ptr<Music> music;
	std::shared_ptr<StartMenu >start;
	std::shared_ptr<Option >option;
	std::shared_ptr<play > shoot;
};
