#pragma once
#include "Graphic.h"
#include "Music.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Pose.h"
#include "Gameover.h"
#include <memory>
#include <list>
#include <algorithm>
class play{
public:
	play(std::shared_ptr<Graphic> g, std::shared_ptr<Music> m,int playernum);
	void draw();
	int Start();
	~play();
	std::shared_ptr<Graphic> graphic;
	std::shared_ptr<Music> music;
private:
	std::shared_ptr<Pose> pose;
	std::shared_ptr<Gameover> over;
	std::vector<Bullet> bullets;
	std::vector<Enemy> enemys;
	std::list<EnemyBullet> enemybullets;
	int playerx, playery, score,playerleft,globalperiod;
	Uint8 *keys;
	Uint32 starttime;
};

