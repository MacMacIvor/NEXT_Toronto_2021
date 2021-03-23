#include "stdafx.h"
#include "bullet.h"

bullet::bullet(float x, float y, float speedPas)
{
	pos[0] = x;
	pos[1] = y;
	speed = speedPas;
	isActive = false;
	dir[0] = 0;
	dir[1] = 0;
	sprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 13);
	sprite->SetPosition(900.0f, 600.0f);
	sprite->SetFrame(3);
	sprite->SetScale(1.0f);
}

void bullet::Update(float a_DeltaTime)
{
	if (this->getActive()) {
		
		pos[0] += speed * dir[0];
		pos[1] += speed * dir[1];
		sprite->SetPosition(pos[0], pos[1]);
		sprite->Update(a_DeltaTime);
		float distFromX = initPos[0] - pos[0];
		distFromX < 0 ? distFromX *= -1 : distFromX;
		float distFromY = initPos[1] - pos[1];
		distFromY < 0 ? distFromY *= -1 : distFromY;
		float totDist = distFromX + distFromY;
		if (totDist > 1000) {
			enemyManager::Get().resetBullets(this);
		}
	}
}

void bullet::Render()
{
	if (this->getActive()) {
		sprite->Draw();
	}
}

bool bullet::isCollide(float x, float y)
{
	if (this->getActive()) {
		float distFromX = x - pos[0];
		distFromX < 0 ? distFromX *= -1 : distFromX;
		float distFromY = y - pos[1];
		distFromY < 0 ? distFromY *= -1 : distFromY;

		float totDist = distFromX + distFromY;

		return totDist < 64;
	}
	return false;
}
