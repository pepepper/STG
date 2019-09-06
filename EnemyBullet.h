#pragma once
typedef void(*bulletfunc)(double*, double*, int, int, double);
class EnemyBullet {
public:
	EnemyBullet(int type, int origperiod, bulletfunc origfunc, int origenemy, double origdata);
	void reset(int origx, int origy);
	void go();
	~EnemyBullet();
	int bullettype;
	double x;
	double y;
	int period;
	int startperiod;
	int show;
	bulletfunc func;
	int originenemy;
	double data;
};
