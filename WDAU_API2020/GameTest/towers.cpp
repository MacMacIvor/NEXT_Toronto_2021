#include "stdafx.h"
#include "towers.h"
#include "objectPooling.h"
#include "maps.h"
towers::towers(float x, float y, int spriteID, float shotCoolDownPass)
{
	pos[0] = x;
	pos[1] = y;
	isActive = false;
	dir = -1; //up = 1, left = 0, down = -1, right = -2
	static int ID = -1;
	ID++;
	objectID = ID;
	sprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 13);
	sprite->SetPosition(-1000.0f, -1000.0f);
	sprite->SetFrame(spriteID);
	sprite->SetScale(1.0f);
	shotCoolDown = shotCoolDownPass;
	shotCoolDownSaved = shotCoolDownPass;
}

void towers::Update(float a_DeltaTime)
{
	if (this->getActive()) {
		
		sprite->SetPosition(pos[0], pos[1]);
		sprite->Update(a_DeltaTime);
		static float unitVector[2];
		static float denominator;

		//Take aim
		float* posToAimAt = enemyManager::Get().getFurthestEnemy();

		unitVector[0] = posToAimAt[0] - pos[0];
		unitVector[1] = posToAimAt[1] - pos[1];
		denominator = (unitVector[0] > unitVector[1] ? unitVector[0] : unitVector[1]);
		denominator < 0 ? denominator *= -1 : denominator;
		unitVector[0] /= denominator;
		unitVector[1] /= denominator;

		//Fire bullet starting at this position with certain speed
		if (shotCoolDown <= 0) {
			enemyManager::Get().getBulletToSpawn(pos[0], pos[1], 5, unitVector[0], unitVector[1]);
			shotCoolDown = shotCoolDownSaved;
		}
		shotCoolDown -= a_DeltaTime / 1000;
	}
}

void towers::Render()
{
	if (this->getActive() == true) {
		sprite->Draw();
	}
}

bool towers::doesTowerExistAtPos(float &x, float &y)
{
	int yArray = ((y) / 64.0f);
	int xArray = ((x) / 64.0f);
	int yArrayThis = pos[1] / 64;
	int xArrayThis = pos[0] / 64;
	if (maps[0][yArray][xArray] == 1) { //If the position isn't even valid to place a tower then no need to even check if a tower is already there
		return true;
	}
	else if (xArray == xArrayThis && yArray == yArrayThis && this->isActive) {
		return true;
	}
	
	return false;
}

fastTower::fastTower(float x, float y, int spriteID, float shotCoolDownPass) : towers(x, y, spriteID, shotCoolDownPass)
{
	pos[0] = x;
	pos[1] = y;
	isActive = false;
	dir = -1; //up = 1, left = 0, down = -1, right = -2
	static int ID = -1;
	ID++;
	objectID = ID;
	sprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 13);
	sprite->SetPosition(-1000.0f, -1000.0f);
	sprite->SetFrame(spriteID);
	sprite->SetScale(1.0f);
	shotCoolDown = shotCoolDownPass;
	shotCoolDownSaved = shotCoolDownPass;
}

void fastTower::Update(float a_DeltaTime)
{
	if (this->getActive()) {

		sprite->SetPosition(pos[0], pos[1]);
		sprite->Update(a_DeltaTime);
		static float unitVector[2];
		static float denominator;

		//Take aim
		float* posToAimAt = enemyManager::Get().getFurthestEnemy();

		unitVector[0] = posToAimAt[0] - pos[0];
		unitVector[1] = posToAimAt[1] - pos[1];
		denominator = (unitVector[0] > unitVector[1] ? unitVector[0] : unitVector[1]);
		denominator < 0 ? denominator *= -1 : denominator;
		unitVector[0] /= denominator;
		unitVector[1] /= denominator;

		//Fire bullet starting at this position with certain speed
		if (shotCoolDown <= 0) {
			enemyManager::Get().getBulletToSpawn(pos[0], pos[1], 5, unitVector[0], unitVector[1]);
			shotCoolDown = shotCoolDownSaved;
		}
		shotCoolDown -= a_DeltaTime / 1000;
	}
}

void fastTower::Render()
{
	if (this->getActive() == true) {
		sprite->Draw();
	}
}

bool fastTower::doesTowerExistAtPos(float& x, float& y)
{
	int yArray = ((y) / 64.0f);
	int xArray = ((x) / 64.0f);
	int yArrayThis = pos[1] / 64;
	int xArrayThis = pos[0] / 64;
	if (maps[0][yArray][xArray] == 1) { //If the position isn't even valid to place a tower then no need to even check if a tower is already there
		return true;
	}
	else if (xArray == xArrayThis && yArray == yArrayThis && this->isActive) {
		return true;
	}

	return false;
}



fasterTower::fasterTower(float x, float y, int spriteID, float shotCoolDownPass) : towers(x, y, spriteID, shotCoolDownPass)
{
	pos[0] = x;
	pos[1] = y;
	isActive = false;
	dir = -1; //up = 1, left = 0, down = -1, right = -2
	static int ID = -1;
	ID++;
	objectID = ID;
	sprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 13);
	sprite->SetPosition(-1000.0f, -1000.0f);
	sprite->SetFrame(spriteID);
	sprite->SetScale(1.0f);
	shotCoolDown = shotCoolDownPass;
	shotCoolDownSaved = shotCoolDownPass;
}

void fasterTower::Update(float a_DeltaTime)
{
	if (this->getActive()) {

		sprite->SetPosition(pos[0], pos[1]);
		sprite->Update(a_DeltaTime);
		static float unitVector[2];
		static float denominator;

		//Take aim
		float* posToAimAt = enemyManager::Get().getFurthestEnemy();

		unitVector[0] = posToAimAt[0] - pos[0];
		unitVector[1] = posToAimAt[1] - pos[1];
		denominator = (unitVector[0] > unitVector[1] ? unitVector[0] : unitVector[1]);
		denominator < 0 ? denominator *= -1 : denominator;
		unitVector[0] /= denominator;
		unitVector[1] /= denominator;

		//Fire bullet starting at this position with certain speed
		if (shotCoolDown <= 0) {
			enemyManager::Get().getBulletToSpawn(pos[0], pos[1], 5, unitVector[0], unitVector[1]);
			shotCoolDown = shotCoolDownSaved;
		}
		shotCoolDown -= a_DeltaTime / 1000;
	}
}

void fasterTower::Render()
{
	if (this->getActive() == true) {
		sprite->Draw();
	}
}

bool fasterTower::doesTowerExistAtPos(float& x, float& y)
{
	int yArray = ((y) / 64.0f);
	int xArray = ((x) / 64.0f);
	int yArrayThis = pos[1] / 64;
	int xArrayThis = pos[0] / 64;
	if (maps[0][yArray][xArray] == 1) { //If the position isn't even valid to place a tower then no need to even check if a tower is already there
		return true;
	}
	else if (xArray == xArrayThis && yArray == yArrayThis && this->isActive) {
		return true;
	}

	return false;
}



fastestTower::fastestTower(float x, float y, int spriteID, float shotCoolDownPass) : towers(x, y, spriteID, shotCoolDownPass)
{
	pos[0] = x;
	pos[1] = y;
	isActive = false;
	dir = -1; //up = 1, left = 0, down = -1, right = -2
	static int ID = -1;
	ID++;
	objectID = ID;
	sprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 13);
	sprite->SetPosition(-1000.0f, -1000.0f);
	sprite->SetFrame(spriteID);
	sprite->SetScale(1.0f);
	shotCoolDown = shotCoolDownPass;
	shotCoolDownSaved = shotCoolDownPass;
}

void fastestTower::Update(float a_DeltaTime)
{
	if (this->getActive()) {

		sprite->SetPosition(pos[0], pos[1]);
		sprite->Update(a_DeltaTime);
		static float unitVector[2];
		static float denominator;

		//Take aim
		float* posToAimAt = enemyManager::Get().getFurthestEnemy();

		unitVector[0] = posToAimAt[0] - pos[0];
		unitVector[1] = posToAimAt[1] - pos[1];
		denominator = (unitVector[0] > unitVector[1] ? unitVector[0] : unitVector[1]);
		denominator < 0 ? denominator *= -1 : denominator;
		unitVector[0] /= denominator;
		unitVector[1] /= denominator;

		//Fire bullet starting at this position with certain speed
		if (shotCoolDown <= 0) {
			enemyManager::Get().getBulletToSpawn(pos[0], pos[1], 5, unitVector[0], unitVector[1]);
			shotCoolDown = shotCoolDownSaved;
		}
		shotCoolDown -= a_DeltaTime / 1000;
	}
}

void fastestTower::Render()
{
	if (this->getActive() == true) {
		sprite->Draw();
	}
}

bool fastestTower::doesTowerExistAtPos(float& x, float& y)
{
	int yArray = ((y) / 64.0f);
	int xArray = ((x) / 64.0f);
	int yArrayThis = pos[1] / 64;
	int xArrayThis = pos[0] / 64;
	if (maps[0][yArray][xArray] == 1) { //If the position isn't even valid to place a tower then no need to even check if a tower is already there
		return true;
	}
	else if (xArray == xArrayThis && yArray == yArrayThis && this->isActive) {
		return true;
	}

	return false;
}
