#pragma once
class Bullet{
public:
	Bullet(int type,int origx,int origy);
	void go();
	~Bullet();
	int bullettype;
	int x;
	int y;
	int originy;
};