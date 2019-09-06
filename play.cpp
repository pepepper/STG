#include "play.h"
#define enemy0 0
#define enemy1 1
#define enemy2 2
#define enemy3 3
#define enemy4 4
#define boss 5

play::play(std::shared_ptr<Graphic> g, std::shared_ptr<Music> m, int playernum) :graphic(g), music(m), playerleft(playernum), playerx(300), playery(640), score(0), globalperiod(0) {
	enemys.emplace_back(enemy0, 0, 320, 1, 0, MoveFromLeft1);
	enemys.emplace_back(enemy1, 0, 320, 1, 125, MoveFromLeft2);
	enemys.emplace_back(enemy2, 0, 320, 1, 250, MoveFromLeft3);
	enemys.emplace_back(enemy3, 600, 320, 1, 370, MoveFromRight1);
	enemys.emplace_back(enemy4, 600, 320, 1, 495, MoveFromRight2);
	enemys.emplace_back(enemy1, 600, 320, 1, 620, MoveFromRight3);
	enemys.emplace_back(boss, 300, 0, 200, 1500, MoveStraightVertical);
	enemys.emplace_back(enemy0, 120, 0, 1, 2300, MoveStraightVertical);
	enemys.emplace_back(enemy1, 240, 0, 1, 2300, MoveStraightVertical);
	enemys.emplace_back(enemy2, 360, 0, 1, 2300, MoveStraightVertical);
	enemys.emplace_back(enemy3, 480, 0, 1, 2300, MoveStraightVertical);
	enemys.emplace_back(enemy4, 0, 640, 1, 3000, MoveFromLeft2);
	enemys.emplace_back(enemy1, 600, 640, 1, 3000, MoveFromRight2);
	enemys.emplace_back(boss, 0, 160, 200, 3500, MoveStraightHorizontal);
	enemys.emplace_back(enemy0, 0, 384, 1, 4800, MoveStraightFromLeftUp);
	enemys.emplace_back(enemy1, 0, 320, 1, 4800, MoveStraightFromLeftUp);
	enemys.emplace_back(enemy2, 0, 254, 1, 4800, MoveStraightFromLeftUp);
	enemys.emplace_back(enemy3, 0, 190, 1, 4800, MoveStraightFromLeftUp);
	enemys.emplace_back(enemy4, 200, 0, 1, 5300, MoveStraightVertical);
	enemys.emplace_back(enemy1, 400, 0, 1, 5300, MoveStraightVertical);
	enemys.emplace_back(boss, 0, 320, 200, 6000, MoveFromLeft1);

	enemybullets.emplace_back(0, 100, BulletMoveStraight, 0,0);
	enemybullets.emplace_back(0, 105, BulletMoveStraight, 0,10);
	enemybullets.emplace_back(0, 110, BulletMoveStraight, 0,20);
	enemybullets.emplace_back(0, 115, BulletMoveStraight, 0,30);
	enemybullets.emplace_back(0, 120, BulletMoveStraight, 0,40);
	enemybullets.emplace_back(0, 125, BulletMoveStraight, 0,50);
	enemybullets.emplace_back(0, 130, BulletMoveStraight, 0,60);
	enemybullets.emplace_back(0, 135, BulletMoveStraight, 0,70);
	enemybullets.emplace_back(0, 140, BulletMoveStraight, 0,80);
	enemybullets.emplace_back(0, 145, BulletMoveStraight, 0,90);
	enemybullets.emplace_back(0, 150, BulletMoveStraight, 0,100);
	enemybullets.emplace_back(0, 155, BulletMoveStraight, 0,110);
	enemybullets.emplace_back(0, 160, BulletMoveStraight, 0, 120);
	enemybullets.emplace_back(0, 165, BulletMoveStraight, 0, 130);
	enemybullets.emplace_back(0, 170, BulletMoveStraight, 0, 140);
	enemybullets.emplace_back(0, 175, BulletMoveStraight, 0, 150);
	enemybullets.emplace_back(0, 180, BulletMoveStraight, 0, 160);
	enemybullets.emplace_back(0, 185, BulletMoveStraight, 0, 170);
	enemybullets.emplace_back(0, 190, BulletMoveStraight, 0, 180);
	enemybullets.emplace_back(0, 195, BulletMoveStraight, 0, 190);
	enemybullets.emplace_back(0, 200, BulletMoveStraight, 0, 200);
	enemybullets.emplace_back(0, 205, BulletMoveStraight, 0, 210);
	enemybullets.emplace_back(0, 210, BulletMoveStraight, 0, 220);
	enemybullets.emplace_back(0, 215, BulletMoveStraight, 0, 230);
	enemybullets.emplace_back(0, 220, BulletMoveStraight, 0, 240);
	enemybullets.emplace_back(0, 225, BulletMoveStraight, 0, 250);
	enemybullets.emplace_back(0, 230, BulletMoveStraight, 0, 260);
	enemybullets.emplace_back(0, 235, BulletMoveStraight, 0, 270);
	enemybullets.emplace_back(0, 240, BulletMoveStraight, 0, 280);
	enemybullets.emplace_back(0, 245, BulletMoveStraight, 0, 290);
	enemybullets.emplace_back(0, 250, BulletMoveStraight, 0, 300);
	enemybullets.emplace_back(0, 255, BulletMoveStraight, 0, 310);
	enemybullets.emplace_back(0, 260, BulletMoveStraight, 0, 320);
	enemybullets.emplace_back(0, 265, BulletMoveStraight, 0, 330);
	enemybullets.emplace_back(0, 270, BulletMoveStraight, 0, 340);
	enemybullets.emplace_back(0, 275, BulletMoveStraight, 0, 350);

	enemybullets.emplace_back(0, 100, BulletMoveStraight, 1, 0);
	enemybullets.emplace_back(0, 105, BulletMoveStraight, 1, 10);
	enemybullets.emplace_back(0, 110, BulletMoveStraight, 1, 20);
	enemybullets.emplace_back(0, 115, BulletMoveStraight, 1, 30);
	enemybullets.emplace_back(0, 120, BulletMoveStraight, 1, 40);
	enemybullets.emplace_back(0, 125, BulletMoveStraight, 1, 50);
	enemybullets.emplace_back(0, 130, BulletMoveStraight, 1, 60);
	enemybullets.emplace_back(0, 135, BulletMoveStraight, 1, 70);
	enemybullets.emplace_back(0, 140, BulletMoveStraight, 1, 80);
	enemybullets.emplace_back(0, 145, BulletMoveStraight, 1, 90);
	enemybullets.emplace_back(0, 150, BulletMoveStraight, 1, 100);
	enemybullets.emplace_back(0, 155, BulletMoveStraight, 1, 110);
	enemybullets.emplace_back(0, 160, BulletMoveStraight, 1, 120);
	enemybullets.emplace_back(0, 165, BulletMoveStraight, 1, 130);
	enemybullets.emplace_back(0, 170, BulletMoveStraight, 1, 140);
	enemybullets.emplace_back(0, 175, BulletMoveStraight, 1, 150);
	enemybullets.emplace_back(0, 180, BulletMoveStraight, 1, 160);
	enemybullets.emplace_back(0, 185, BulletMoveStraight, 1, 170);
	enemybullets.emplace_back(0, 190, BulletMoveStraight, 1, 180);
	enemybullets.emplace_back(0, 195, BulletMoveStraight, 1, 190);
	enemybullets.emplace_back(0, 200, BulletMoveStraight, 1, 200);
	enemybullets.emplace_back(0, 205, BulletMoveStraight, 1, 210);
	enemybullets.emplace_back(0, 210, BulletMoveStraight, 1, 220);
	enemybullets.emplace_back(0, 215, BulletMoveStraight, 1, 230);
	enemybullets.emplace_back(0, 220, BulletMoveStraight, 1, 240);
	enemybullets.emplace_back(0, 225, BulletMoveStraight, 1, 250);
	enemybullets.emplace_back(0, 230, BulletMoveStraight, 1, 260);
	enemybullets.emplace_back(0, 235, BulletMoveStraight, 1, 270);
	enemybullets.emplace_back(0, 240, BulletMoveStraight, 1, 280);
	enemybullets.emplace_back(0, 245, BulletMoveStraight, 1, 290);
	enemybullets.emplace_back(0, 250, BulletMoveStraight, 1, 300);
	enemybullets.emplace_back(0, 255, BulletMoveStraight, 1, 310);
	enemybullets.emplace_back(0, 260, BulletMoveStraight, 1, 320);
	enemybullets.emplace_back(0, 265, BulletMoveStraight, 1, 330);
	enemybullets.emplace_back(0, 270, BulletMoveStraight, 1, 340);
	enemybullets.emplace_back(0, 275, BulletMoveStraight, 1, 350);

	enemybullets.emplace_back(0, 500, BulletMoveSine, 2, 3);

	over.reset(new Gameover(graphic, music));
}

void play::draw() {
	std::string text;
	static int bgperiod = 0;
	SDL_Rect rect = {};
	graphic->RenderFillRect(0, 0, 600, 640, 0, 255, 0, 0, SDL_BLENDMODE_NONE);
	rect.x = 0;
	rect.y = bgperiod;
	rect.w = 600;
	rect.h = 800;
	graphic->RenderBG(1, &rect);
	rect.y = bgperiod - 800;
	graphic->RenderBG(1, &rect);
	if (bgperiod == 800)bgperiod = 0; else bgperiod++;
	for (Bullet bullet : bullets) {
		graphic->RenderBullet(bullet.bullettype, bullet.x - 8, bullet.y - 16);
	}
	for (Enemy enemy : enemys) {
		if (enemy.show)graphic->RenderEnemy(enemy.enemytype, globalperiod % 2, (int)enemy.x - 32, (int)enemy.y - 32);
	}
	for (EnemyBullet bullet : enemybullets) {
		if (bullet.show)graphic->RenderEnemyBullet(bullet.bullettype, bullet.x - 8, bullet.y - 16);
	}
	graphic->RenderPlayer(bgperiod % 3, playerx - 32, playery - 32);
	graphic->RenderFillRect(600, 0, 200, 640, 0, 0, 0, 0, SDL_BLENDMODE_NONE);
	text = u8"Score:" + std::to_string(score);
	graphic->Render_UTF8_Text(text, SDL_TTF_FREE, 620, 64, 255, 255, 255, 0);
	text = u8"High Score:" + std::to_string(score);
	graphic->Render_UTF8_Text(text, SDL_TTF_FREE, 620, 96, 255, 255, 255, 0);
	text = u8"Players left:" + std::to_string(playerleft);
	graphic->Render_UTF8_Text(text, SDL_TTF_FREE, 620, 128, 255, 255, 255, 0);
}

int play::Start() {
	SDL_Event e;
	keys = (Uint8 *)SDL_GetKeyboardState(NULL);
	music->PlayBGM(1);
	while (true) {
		SDL_PollEvent(&e);
		if (keys[SDL_SCANCODE_UP] && playery > 0) {
			if (keys[SDL_SCANCODE_LSHIFT])playery -= 1;
			else playery -= 2;
		}
		if (keys[SDL_SCANCODE_DOWN] && playery < 640) {
			if (keys[SDL_SCANCODE_LSHIFT])playery += 1;
			else playery += 2;
		}
		if (keys[SDL_SCANCODE_LEFT] && playerx > 0) {
			if (keys[SDL_SCANCODE_LSHIFT])playerx -= 1;
			else playerx -= 2;
		}
		if (keys[SDL_SCANCODE_RIGHT] && playerx < 600) {
			if (keys[SDL_SCANCODE_LSHIFT])playerx += 1;
			else playerx += 2;
		}
		if (keys[SDL_SCANCODE_ESCAPE]) {
			music->StopBGM();
			music->PlaySE(2);
			pose.reset(new Pose(graphic, music));
			int ret = pose->Start();
			if (ret)return ret;
			music->PlayBGM(1);
		}
		if (bullets.size() == 0 || (bullets.back().originy - bullets.back().y > 24)) {
			if (keys[SDL_SCANCODE_Z]) {
				music->PlaySE(4);
				bullets.emplace_back(0, playerx, playery);
			} else if (keys[SDL_SCANCODE_X]) {
				music->PlaySE(5);
				bullets.emplace_back(1, playerx, playery);
			} else if (keys[SDL_SCANCODE_C]) {
				music->PlaySE(6);
				bullets.emplace_back(2, playerx, playery);
			}
		}

		starttime = SDL_GetTicks();
		for (Enemy &enemy : enemys) {
			if (enemy.y < 0)enemy.show = 0;
			if (enemy.show)enemy.Go();
			if (
				((playerx + 32) >= (enemy.x - 32)) &&
				((playerx - 32) <= (enemy.x + 32)) &&
				((playery + 32) >= (enemy.y - 16)) &&
				((playery - 16) <= (enemy.y + 32)) &&
				enemy.show
				) {
				music->PlaySE(8);
				if ((playerleft > 0)) {
					playerleft--;
					playerx = 300;
					playery = 640;
				} else if (playerleft == 0) {
					music->StopBGM();
					music->PlaySE(7);
					over->Start(score);
					return -1;
				}
			}
			if (enemy.startperiod == globalperiod)enemy.Reset();
		}
		for (EnemyBullet &bullet : enemybullets) {
			if (bullet.startperiod == globalperiod && enemys[bullet.originenemy].show)bullet.reset(enemys[bullet.originenemy].x, enemys[bullet.originenemy].y);
			if (bullet.x < 0 || bullet.y < 0 || bullet.x>600 || bullet.y>640)bullet.show = 0;
			if (bullet.show)bullet.go();
			if (
				((playerx + 32) >= (bullet.x - 4)) &&
				((playerx - 32) <= (bullet.x + 4)) &&
				((playery + 32) >= (bullet.y - 8)) &&
				((playery - 16) <= (bullet.y + 8)) &&
				bullet.show
				) {
				bullet.show = 0;
				music->PlaySE(8);
				if ((playerleft > 0)) {
					playerleft--;
					playerx = 300;
					playery = 640;
				} else {
					music->StopBGM();
					music->PlaySE(7);
					over->Start(score);
					return -1;
				}
			}
		}
		for (Bullet &bullet : bullets) {
			bullet.go();
			for (Enemy &enemy : enemys) {
				if (
					((bullet.x + 4) >= (enemy.x - 16)) &&
					((bullet.x - 4) <= (enemy.x + 16)) &&
					((bullet.y + 8) >= (enemy.y - 16)) &&
					((bullet.y - 8) <= (enemy.y + 16)) &&
					(enemy.show == 1)
					) {
					enemy.hp -= bullet.bullettype + 1;
					if (enemy.hp <= 0) {
						enemy.show = 0;
						score += 100;
					}
					bullet.y = -1;
					score += 10;
				}
			}
		}
		bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Bullet bullet) {return bullet.y < 0; }), bullets.end());
		draw();
		graphic->update();
		while (!SDL_TICKS_PASSED(SDL_GetTicks(), starttime + 8)) {
			SDL_Delay(1);
		}
		globalperiod++;
		if (globalperiod > 7000)globalperiod = 0;
		continue;
	}
}

play::~play() {
}
