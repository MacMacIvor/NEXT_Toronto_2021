#pragma once
#include "app\app.h"

class bullet {
public:
	bullet(float x = 100.0f, float y = 100.0f, float speedPas = -20.0f);
	void Update(float a_Deltatime);
	void Render();
	bool getActive() { return isActive; }
	void setPosition(float posX, float posY) { pos[0] = posX; pos[1] = posY; initPos[0] = posX; initPos[1] = posY; }
	void setSpeed(float speedP) { speed = speedP; }
	void setDir(float x, float y) { dir[0] = x; dir[1] = y; }
	void setActive(bool active) { isActive = active; }
	float* getPosition() {
		return pos;
	}
	bool isCollide(float x, float y);
private:
	float pos[2];
	float initPos[2];
	bool isActive;
	float dir[2];
	float speed;
	CSimpleSprite* sprite;

};