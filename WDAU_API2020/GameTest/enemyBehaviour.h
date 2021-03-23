#pragma once
#include "app\app.h"

const int AMOUNT_OF_ENEMY_CLASSES = 2;

class baseEnemy {
public:
	baseEnemy(float x = 100.0f, float y = 100.0f, float speedPas = -30, int hp = 1);
	virtual void Update(float a_DeltaTime);
	virtual void Render();
	virtual bool getActive() { return isActive; }
	virtual void setPosition(float posX, float posY) { pos[0] = posX; pos[1] = posY; }
	virtual void setActive(bool active) { isActive = active; }
	virtual float* getPosition() {
		return pos;
	}
	virtual float getDistanceTravelled() { return distTrav; }
	virtual int getID() { return this->objectID; }
	//virtual void move(float a_DeltaTime);
private:
	int health;
	float pos[2];
	float speed;
	int dir;
	bool isActive;
	int objectID;
	float distTrav = 0;
	CSimpleSprite* sprite;
};

class tankEnemy : public baseEnemy {
public:
	tankEnemy(float x = 100.0f, float y = 100.0f, float speedPas = -30.0f, int hp = 3);
	//tankEnemy() {}
	virtual void setPosition(float posX, float posY) { pos[0] = posX; pos[1] = posY; }
	virtual void setActive(bool active) { isActive = active; }
	virtual bool getActive() { return isActive; }
	virtual float getDistanceTravelled() { return distTrav; }
	virtual void Update(float a_DeltaTime);
	virtual void Render();
	virtual float* getPosition() {
		return pos;
	}
	
private:
	bool isActive;
	float pos[2];
	int dir;
	float distTrav = 0;
	float speed;
	int health;
	CSimpleSprite* sprite;
};

class speedEnemy : public baseEnemy {
public:
	speedEnemy(float x = 100.0f, float y = 100.0f, float speedPas = -60.0f, int hp = 2);
	//tankEnemy() {}
	virtual void setPosition(float posX, float posY) { pos[0] = posX; pos[1] = posY; }
	virtual void setActive(bool active) { isActive = active; }
	virtual bool getActive() { return isActive; }
	virtual float getDistanceTravelled() { return distTrav; }
	virtual void Update(float a_DeltaTime);
	virtual void Render();
	virtual float* getPosition() {
		return pos;
	}

private:
	bool isActive;
	float pos[2];
	int dir;
	float distTrav = 0;
	float speed;
	int health;
	CSimpleSprite* sprite;
};

class beastEnemy : public baseEnemy {
public:
	beastEnemy(float x = 100.0f, float y = 100.0f, float speedPas = -40.0f, int hp = 10);
	//tankEnemy() {}
	virtual void setPosition(float posX, float posY) { pos[0] = posX; pos[1] = posY; }
	virtual void setActive(bool active) { isActive = active; }
	virtual bool getActive() { return isActive; }
	virtual float getDistanceTravelled() { return distTrav; }
	virtual void Update(float a_DeltaTime);
	virtual void Render();
	virtual float* getPosition() {
		return pos;
	}

private:
	bool isActive;
	float pos[2];
	int dir;
	float distTrav = 0;
	float speed;
	int health;
	CSimpleSprite* sprite;
};


//HitBoxes
class HitBoxes {
public:
	HitBoxes() {};
	void setHitBoxes(int mapToLoad, int index);
	void Update(float a_DeltaTime);
	void Render();
	static bool isColliding(float x, float y);
private:
	float positionOfHitBoxes[2];
	CSimpleSprite* sprite;
};