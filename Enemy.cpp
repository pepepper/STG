#include "Enemy.h"



Enemy::Enemy(int type, int origx, int origy, int orighp, int origperiod, movefunc origfunc) 
	:enemytype(type), startperiod(origperiod), defaulthp(orighp), defaultx(origx), defaulty(origy), func(origfunc),show(0) {
}

void Enemy::Reset() {
	show = 1;
	period = 0;
	hp = defaulthp;
	x = defaultx;
	y = defaulty;
}

void Enemy::Go() {
	func(&x, &y, period);
	period++;
}

Enemy::~Enemy() {
}
