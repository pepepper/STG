#pragma once
#include"movefunc.h"
typedef void(*movefunc)(double*, double*, int);
class Enemy {
public:
	Enemy(int type, int origx, int origy, int orighp, int origperiod, movefunc origfunc);
	void Reset();
	void Go();
	~Enemy();
	int enemytype;
	double x;
	double y;
	int defaulthp;
	int hp;
	int period;
	int startperiod;
	movefunc func;
	double defaultx;
	double defaulty;
	int show;
};

