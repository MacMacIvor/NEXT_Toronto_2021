#pragma once
#include "stdafx.h"
#include "enemyBehaviour.h"
#include "towers.h"
#include "UI.h"
#include "bullet.h"

class enemyManager { //Started as a enemy manager but now should be named everything manager xD
public:
	static enemyManager& Get() {
		static enemyManager* singleton = new enemyManager();
		return *singleton;
	}

	void _BuildEnemyPool(); //Builds the pool of enemies needed for the game    
	void _BuildHitBox();
	void _BuildUI();
	void _BuildTowers();
	void _BuildBullets();
	void _BuildAll(); //Calls all the builds

	void resetEnemy(baseEnemy* enemy); //Kills an enemy
	void resetEnemy(tankEnemy* enemy);
	void resetEnemy(speedEnemy* enemy);
	void resetEnemy(beastEnemy* enemy);


	void resetTower(towers* enemy); 
	void resetBullets(bullet* enemy); 

    baseEnemy getEnemyBaseToSpawn(float x, float y); //Gets an available enemy to activate, if none available increases the pool size
	tankEnemy getEnemyTankToSpawn(float x, float y);
	speedEnemy getEnemySpeedToSpawn(float x, float y);
	beastEnemy getEnemyBeastToSpawn(float x, float y);
	void getEnemyTowerToSpawn(float &x, float &y, int selection);
	bullet getBulletToSpawn(float x, float y, float speed, float dirX, float dirY);

	float* getFurthestEnemy(); //Get the enemy that travelled the furthest distance
	bool checkHit(float x, float y);

	int getSelectedUI();
	void changeSelectedUI();

	void Update(float deltaTime);
	void Render();

	int getMoney() { return money; };
	int modMoney(int amount) { money += amount; return money; };

	int getHealth() { return health; };
	int modHealth(int amount) { health -= amount; return health; };

private:
	int money = 100;
	int health = 50;
    enemyManager() {}
	int index;
	tankEnemy* tankListPtr;
	baseEnemy* baseListPtr;
	speedEnemy* speedListPtr;
	beastEnemy* beastListPtr;
	HitBoxes* hitBoxListPtr;
	uiSelection* uiThingPtr;
	towers* towerListPtr;
	fastTower* fastTowerListPtr;
	fasterTower* fasterTowerListPtr;
	fastestTower* fastestTowerListPtr;
	bullet* bulletListPtr;
	int timesSizeIncreased = 1;
	int furthest = 20;
	int furthestType = 1;
	int somethingForPsudorandom;

};
