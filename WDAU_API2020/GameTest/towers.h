#pragma once
#include "app\app.h"

class towers {
public:
	towers(float x = 100.0f, float y = 100.0f, int spriteID = 4, float shotCoolDownPass = 3);
	virtual void Update(float a_DeltaTime);
	virtual void Render();
	virtual bool getActive() { return isActive; }
	virtual void setPosition(float posX, float posY) { pos[0] = posX; pos[1] = posY; }
	virtual void setActive(bool active) { isActive = active; }
	virtual float* getPosition() {
		return pos;
	}
	virtual int getID() { return this->objectID; }
	virtual bool doesTowerExistAtPos(float &x, float &y);

	//virtual void move(float a_DeltaTime);
private:
	float pos[2];
	float speed;
	int dir;
	bool isActive;
	int objectID;
	float shotCoolDown;
	float shotCoolDownSaved;
	int damage;
	CSimpleSprite* sprite;
};

class fastTower: towers {
public:
	fastTower(float x = 100.0f, float y = 100.0f, int spriteID = 6, float shotCoolDownPass = 2.5);
	virtual void Update(float a_DeltaTime);
	virtual void Render();
	virtual bool getActive() { return isActive; }
	virtual void setPosition(float posX, float posY) { pos[0] = posX; pos[1] = posY; }
	virtual void setActive(bool active) { isActive = active; }
	virtual float* getPosition() {
		return pos;
	}
	virtual int getID() { return this->objectID; }
	virtual bool doesTowerExistAtPos(float& x, float& y);
private:
	float pos[2];
	float speed;
	int dir;
	bool isActive;
	int objectID;
	float shotCoolDown;
	float shotCoolDownSaved;
	int damage;
	CSimpleSprite* sprite;
};

class fasterTower : towers {
public:
	fasterTower(float x = 100.0f, float y = 100.0f, int spriteID = 8, float shotCoolDownPass = 1.5);
	virtual void Update(float a_DeltaTime);
	virtual void Render();
	virtual bool getActive() { return isActive; }
	virtual void setPosition(float posX, float posY) { pos[0] = posX; pos[1] = posY; }
	virtual void setActive(bool active) { isActive = active; }
	virtual float* getPosition() {
		return pos;
	}
	virtual int getID() { return this->objectID; }
	virtual bool doesTowerExistAtPos(float& x, float& y);
private:
	float pos[2];
	float speed;
	int dir;
	bool isActive;
	int objectID;
	float shotCoolDown;
	float shotCoolDownSaved;
	int damage;
	CSimpleSprite* sprite;
};

class fastestTower : towers {
public:
	fastestTower(float x = 100.0f, float y = 100.0f, int spriteID = 10, float shotCoolDownPass = 0.8);
	virtual void Update(float a_DeltaTime);
	virtual void Render();
	virtual bool getActive() { return isActive; }
	virtual void setPosition(float posX, float posY) { pos[0] = posX; pos[1] = posY; }
	virtual void setActive(bool active) { isActive = active; }
	virtual float* getPosition() {
		return pos;
	}
	virtual int getID() { return this->objectID; }
	virtual bool doesTowerExistAtPos(float& x, float& y);
private:
	float pos[2];
	float speed;
	int dir;
	bool isActive;
	int objectID;
	float shotCoolDown;
	float shotCoolDownSaved;
	int damage;
	CSimpleSprite* sprite;
};