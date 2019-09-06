#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(int type,int origperiod,bulletfunc origfunc,int origenemy, double origdata):bullettype(type),func(origfunc),originenemy(origenemy),startperiod(origperiod),show(0), data(origdata) {
}

void EnemyBullet::reset(int origx,int origy){
	show = 1;
	x = origx;
	y = origy;
}


void EnemyBullet::go(){
	func(&x, &y, period, bullettype, data);
	period++;
}


EnemyBullet::~EnemyBullet(){
}
