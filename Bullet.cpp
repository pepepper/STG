#include "Bullet.h"

Bullet::Bullet(int type, int origx, int origy):bullettype(type),x(origx),y(origy),originy(origy){
}

void Bullet::go(){
	y -= 5 - bullettype;
}


Bullet::~Bullet(){
}
