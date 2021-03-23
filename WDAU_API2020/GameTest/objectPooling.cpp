#include "stdafx.h"


const int SAVED_AMOUNT_OF_ENEMIES = 100;
void enemyManager::_BuildEnemyPool()
{
    int i = 0;
    index = 0;
    //enemySmallMelee = new List<GameObject>();

    static tankEnemy tankList[SAVED_AMOUNT_OF_ENEMIES];
    tankListPtr = tankList;
    static baseEnemy baseList[SAVED_AMOUNT_OF_ENEMIES];
    baseListPtr = baseList;
    static speedEnemy speedList[SAVED_AMOUNT_OF_ENEMIES];
    speedListPtr = speedList;
    static beastEnemy beastList[SAVED_AMOUNT_OF_ENEMIES];
    beastListPtr = beastList;
}

void enemyManager::_BuildHitBox()
{
    static HitBoxes hitBoxList[192];
    for (int i = 0; i < 192; i++) {
        hitBoxList[i].setHitBoxes(0, i);
    }
    hitBoxListPtr = hitBoxList;
}

void enemyManager::_BuildUI()
{
    static uiSelection choices[4];
    uiThingPtr = choices;
}

void enemyManager::_BuildTowers()
{
    static towers towerList[SAVED_AMOUNT_OF_ENEMIES];
    towerListPtr = towerList;
    static fastTower towerListFast[SAVED_AMOUNT_OF_ENEMIES];
    fastTowerListPtr = towerListFast;
    static fasterTower towererListFast[SAVED_AMOUNT_OF_ENEMIES];
    fasterTowerListPtr = towererListFast;
    static fastestTower towerestListFast[SAVED_AMOUNT_OF_ENEMIES];
    fastestTowerListPtr = towerestListFast;
}

void enemyManager::_BuildBullets()
{
    static bullet bulletList[10000];
    bulletListPtr = bulletList;
}

void enemyManager::_BuildAll()
{
    enemyManager::Get()._BuildEnemyPool();
    enemyManager::Get()._BuildHitBox();
    enemyManager::Get()._BuildUI();
    enemyManager::Get()._BuildTowers();
    enemyManager::Get()._BuildBullets();
}



//I remembered wayyyyy too late that you can have the same function name as long as the passed data is different, dang
void enemyManager::resetEnemy(baseEnemy* enemy)
{
    enemyManager::Get().modMoney(10);
    enemy->setPosition(-1000.0f, -1000.0f);
    enemy->setActive(false);

}

void enemyManager::resetEnemy(tankEnemy* enemy)
{
    enemyManager::Get().modMoney(20);
    enemy->setPosition(-1000.0f, -1000.0f);
    enemy->setActive(false);
}

void enemyManager::resetEnemy(speedEnemy* enemy)
{
    enemyManager::Get().modMoney(30);
    enemy->setPosition(-1000.0f, -1000.0f);
    enemy->setActive(false);
}

void enemyManager::resetEnemy(beastEnemy* enemy)
{
    enemyManager::Get().modMoney(60);
    enemy->setPosition(-1000.0f, -1000.0f);
    enemy->setActive(false);
}

void enemyManager::resetTower(towers* enemy)
{
    enemy->setPosition(-1000.0f, -1000.0f);
    enemy->setActive(false);
}

void enemyManager::resetBullets(bullet* enemy)
{
    enemy->setPosition(-1000.0f, -1000.0f);
    enemy->setActive(false);
}

baseEnemy enemyManager::getEnemyBaseToSpawn(float x, float y)
{
    static int timesAddedNewResources = 0;
    //This pointer is to make it easier and lowers needing to retype the words elsewhere
    auto ptr = baseListPtr;
    bool spawned = false;
    int indexStartedAt = index;
    const int* times = &timesAddedNewResources;
    
    do {
        if (index >= SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased && spawned == false) {
            index = 0;
        }
        switch (ptr[index].getActive()) {
        case true:
            index++;
            break;
        case false:
            ptr[index].setPosition(x, y);
            ptr[index].setActive(true);
            spawned = true;
            break;
        }
        if (index == indexStartedAt && spawned == false) {
            //We have gone through the entire list of objects, now we must create some more
            timesAddedNewResources++;
            int exponential = 2;
            for (int i = 0; i < timesAddedNewResources; i++) {
                exponential *= 2;
            }
            if (timesAddedNewResources == 1) {

                baseEnemy baseList[SAVED_AMOUNT_OF_ENEMIES * 2]; //Now that the new list is created we need to transfer data
                for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * 2 * exponential; i++) {
                    baseList[i] = ptr[i];
                }
                ptr = baseList;
            }
            else if (timesAddedNewResources == 2) {

                baseEnemy baseList[SAVED_AMOUNT_OF_ENEMIES * 4];
                for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * exponential; i++) {
                    baseList[i] = ptr[i];
                }
                ptr = baseList;
            }
            else if (timesAddedNewResources == 3) {
                baseEnemy baseList[SAVED_AMOUNT_OF_ENEMIES * 8];
                for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * exponential; i++) {
                    baseList[i] = ptr[i];
                }
                ptr = baseList;
                timesSizeIncreased = exponential;
            }
            else {

            }
            //Now we can go back into the loop and for sure get an enemy
            index++;

        }
    } while (spawned == false);

    return ptr[index];
}

tankEnemy enemyManager::getEnemyTankToSpawn(float x, float y)
{
    static int timesAddedNewResources = 0;
    //This pointer is to make it easier and lowers needing to retype the words elsewhere
    auto ptr = tankListPtr;
    bool spawned = false;
    int indexStartedAt = index;
    const int* times = &timesAddedNewResources;

    do {
        if (index >= SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased && spawned == false) {
            index = 0;
        }
        switch (ptr[index].getActive()) {
        case true:
            index++;
            break;
        case false:
            ptr[index].setPosition(x, y);
            ptr[index].setActive(true);
            spawned = true;
            break;
        }
        if (index == indexStartedAt && spawned == false) {
            //We have gone through the entire list of objects, now we must create some more
            timesAddedNewResources++;
            int exponential = 2;
            for (int i = 0; i < timesAddedNewResources; i++) {
                exponential *= 2;
            }
            if (timesAddedNewResources == 1) {

                tankEnemy baseList[SAVED_AMOUNT_OF_ENEMIES * 2]; //Now that the new list is created we need to transfer data
                for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * 2 * exponential; i++) {
                    baseList[i] = ptr[i];
                }
                ptr = baseList;
            }
            else if (timesAddedNewResources == 2) {

                tankEnemy baseList[SAVED_AMOUNT_OF_ENEMIES * 4];
                for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * exponential; i++) {
                    baseList[i] = ptr[i];
                }
                ptr = baseList;
            }
            else if (timesAddedNewResources == 3) {
                tankEnemy baseList[SAVED_AMOUNT_OF_ENEMIES * 8];
                for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * exponential; i++) {
                    baseList[i] = ptr[i];
                }
                ptr = baseList;
                timesSizeIncreased = exponential;
            }
            else {

            }
            //Now we can go back into the loop and for sure get an enemy
            index++;

        }
    } while (spawned == false);

    return ptr[index];
}

speedEnemy enemyManager::getEnemySpeedToSpawn(float x, float y)
{
    static int timesAddedNewResources = 0;
    //This pointer is to make it easier and lowers needing to retype the words elsewhere
    auto ptr = speedListPtr;
    bool spawned = false;
    int indexStartedAt = index;
    const int* times = &timesAddedNewResources;

    do {
        if (index >= SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased && spawned == false) {
            index = 0;
        }
        switch (ptr[index].getActive()) {
        case true:
            index++;
            break;
        case false:
            ptr[index].setPosition(x, y);
            ptr[index].setActive(true);
            spawned = true;
            break;
        }
        if (index == indexStartedAt && spawned == false) {
            //We have gone through the entire list of objects, now we must create some more
            timesAddedNewResources++;
            int exponential = 2;
            for (int i = 0; i < timesAddedNewResources; i++) {
                exponential *= 2;
            }
            if (timesAddedNewResources == 1) {

                speedEnemy baseList[SAVED_AMOUNT_OF_ENEMIES * 2]; //Now that the new list is created we need to transfer data
                for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * 2 * exponential; i++) {
                    baseList[i] = ptr[i];
                }
                ptr = baseList;
            }
            else if (timesAddedNewResources == 2) {

                speedEnemy baseList[SAVED_AMOUNT_OF_ENEMIES * 4];
                for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * exponential; i++) {
                    baseList[i] = ptr[i];
                }
                ptr = baseList;
            }
            else if (timesAddedNewResources == 3) {
                speedEnemy baseList[SAVED_AMOUNT_OF_ENEMIES * 8];
                for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * exponential; i++) {
                    baseList[i] = ptr[i];
                }
                ptr = baseList;
                timesSizeIncreased = exponential;
            }
            else {

            }
            //Now we can go back into the loop and for sure get an enemy
            index++;

        }
    } while (spawned == false);

    return ptr[index];
}

beastEnemy enemyManager::getEnemyBeastToSpawn(float x, float y)
{

    static int timesAddedNewResources = 0;
    //This pointer is to make it easier and lowers needing to retype the words elsewhere
    auto ptr = beastListPtr;
    bool spawned = false;
    int indexStartedAt = index;
    const int* times = &timesAddedNewResources;

    do {
        if (index >= SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased && spawned == false) {
            index = 0;
        }
        switch (ptr[index].getActive()) {
        case true:
            index++;
            break;
        case false:
            ptr[index].setPosition(x, y);
            ptr[index].setActive(true);
            spawned = true;
            break;
        }
        if (index == indexStartedAt && spawned == false) {
            //We have gone through the entire list of objects, now we must create some more
            timesAddedNewResources++;
            int exponential = 2;
            for (int i = 0; i < timesAddedNewResources; i++) {
                exponential *= 2;
            }
            if (timesAddedNewResources == 1) {

                beastEnemy baseList[SAVED_AMOUNT_OF_ENEMIES * 2]; //Now that the new list is created we need to transfer data
                for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * 2 * exponential; i++) {
                    baseList[i] = ptr[i];
                }
                ptr = baseList;
            }
            else if (timesAddedNewResources == 2) {

                beastEnemy baseList[SAVED_AMOUNT_OF_ENEMIES * 4];
                for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * exponential; i++) {
                    baseList[i] = ptr[i];
                }
                ptr = baseList;
            }
            else if (timesAddedNewResources == 3) {
                beastEnemy baseList[SAVED_AMOUNT_OF_ENEMIES * 8];
                for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * exponential; i++) {
                    baseList[i] = ptr[i];
                }
                ptr = baseList;
                timesSizeIncreased = exponential;
            }
            else {

            }
            //Now we can go back into the loop and for sure get an enemy
            index++;

        }
    } while (spawned == false);

    return ptr[index];

}

void enemyManager::getEnemyTowerToSpawn(float &x, float &y, int selection)
{
    static int timesAddedNewResources = 0;
    
    bool spawned = false;
    int indexStartedAt = index;
    const int* times = &timesAddedNewResources;
    
    bool isInvalid = false;

    auto ptr = towerListPtr;
    auto ptr1 = fastTowerListPtr;
    auto ptr2 = fasterTowerListPtr;
    auto ptr3 = fastestTowerListPtr;

    
    switch (selection) {
    case 0:

        for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased; i++) {
            if (ptr[i].doesTowerExistAtPos(x, y)) {
                isInvalid = true;
                i = SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased;
            }
        }
        if (isInvalid) {
            return;
        }
        else {
            //Let's put the position to be in the center of the square
            int yArrayThis = ((y) / 64.0f);
            int xArrayThis = ((x) / 64.0f);
            x = 32.0f + 64.0f * xArrayThis;
            y = 32.0f + 64.0f * yArrayThis;
        }
        do {
            if (index >= SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased && spawned == false) {
                index = 0;
            }
            switch (ptr[index].getActive()) {
            case true:
                index++;
                break;
            case false:
                ptr[index].setPosition(x, y);
                ptr[index].setActive(true);
                spawned = true;
                break;
            }
            if (index == indexStartedAt && spawned == false) {
                //Resources used up so we will just not spawn anything
                spawned = true;
            }
        } while (spawned == false);
        break;
    case 1:

        for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased; i++) {
            if (ptr1[i].doesTowerExistAtPos(x, y)) {
                isInvalid = true;
                i = SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased;
            }
        }
        if (isInvalid) {
            return;
        }
        else {
            //Let's put the position to be in the center of the square
            int yArrayThis = ((y) / 64.0f);
            int xArrayThis = ((x) / 64.0f);
            x = 32.0f + 64.0f * xArrayThis;
            y = 32.0f + 64.0f * yArrayThis;
        }
        do {
            if (index >= SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased && spawned == false) {
                index = 0;
            }
            switch (ptr1[index].getActive()) {
            case true:
                index++;
                break;
            case false:
                ptr1[index].setPosition(x, y);
                ptr1[index].setActive(true);
                spawned = true;
                break;
            }
            if (index == indexStartedAt && spawned == false) {
                //Resources used up so we will just not spawn anything
                spawned = true;
            }
        } while (spawned == false);
        break;
    case 2:

        for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased; i++) {
            if (ptr2[i].doesTowerExistAtPos(x, y)) {
                isInvalid = true;
                i = SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased;
            }
        }
        if (isInvalid) {
            return;
        }
        else {
            //Let's put the position to be in the center of the square
            int yArrayThis = ((y) / 64.0f);
            int xArrayThis = ((x) / 64.0f);
            x = 32.0f + 64.0f * xArrayThis;
            y = 32.0f + 64.0f * yArrayThis;
        }
        do {
            if (index >= SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased && spawned == false) {
                index = 0;
            }
            switch (ptr2[index].getActive()) {
            case true:
                index++;
                break;
            case false:
                ptr2[index].setPosition(x, y);
                ptr2[index].setActive(true);
                spawned = true;
                break;
            }
            if (index == indexStartedAt && spawned == false) {
                //Resources used up so we will just not spawn anything
                spawned = true;
            }
        } while (spawned == false);
        break;
    case 3:

        for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased; i++) {
            if (ptr3[i].doesTowerExistAtPos(x, y)) {
                isInvalid = true;
                i = SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased;
            }
        }
        if (isInvalid) {
            return;
        }
        else {
            //Let's put the position to be in the center of the square
            int yArrayThis = ((y) / 64.0f);
            int xArrayThis = ((x) / 64.0f);
            x = 32.0f + 64.0f * xArrayThis;
            y = 32.0f + 64.0f * yArrayThis;
        }
        do {
            if (index >= SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased && spawned == false) {
                index = 0;
            }
            switch (ptr3[index].getActive()) {
            case true:
                index++;
                break;
            case false:
                ptr3[index].setPosition(x, y);
                ptr3[index].setActive(true);
                spawned = true;
                break;
            }
            if (index == indexStartedAt && spawned == false) {
                //Resources used up so we will just not spawn anything
                spawned = true;
            }
        } while (spawned == false);
        break;
    }
    
    return;

}

bullet enemyManager::getBulletToSpawn(float x, float y, float speed, float dirX, float dirY)
{
    static int timesAddedNewResources = 0;
    //This pointer is to make it easier and lowers needing to retype the words elsewhere
    auto ptr = bulletListPtr;
    bool spawned = false;
    int indexStartedAt = index;
    const int* times = &timesAddedNewResources;

    do {
        switch (ptr[index].getActive()) {
        case true:
            index++;
            break;
        case false:
            ptr[index].setPosition(x, y);
            ptr[index].setDir(dirX, dirY);
            ptr[index].setSpeed(speed);
            ptr[index].setActive(true);
            spawned = true;
            break;
        }
        if (index >= 10000 && spawned == false) {
            index = 0;
        }
        if (index == indexStartedAt && spawned == false) {
            //Resources used up so we will just not spawn anything
            spawned = true;

        }
    } while (spawned == false);

    return ptr[index];
}

float* enemyManager::getFurthestEnemy()
{
    int currentFurthest = 0;
    static int timeCoolDown = SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased * 10; //
    timeCoolDown--;
    if ((furthestType == 0 ? baseListPtr[furthest].getActive() == false : (furthestType == 1 ? tankListPtr[furthest].getActive() == false : (furthestType == 3 ? speedListPtr[furthest].getActive() == false : beastListPtr[furthest].getActive() == false))) || timeCoolDown <= 0 ) {
        for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased; i++) {
            if (baseListPtr[i].getActive()) {
                if ((furthestType == 0 ? baseListPtr[furthest].getDistanceTravelled() : (furthestType == 1 ? tankListPtr[furthest].getDistanceTravelled() : (furthestType == 2 ? speedListPtr[furthest].getDistanceTravelled() : beastListPtr[furthest].getDistanceTravelled()))) < baseListPtr[i].getDistanceTravelled()) {
                    furthest = i;
                    furthestType = 0;
                }

            }
            if (tankListPtr[i].getActive()) {
                if ((furthestType == 0 ? baseListPtr[furthest].getDistanceTravelled() : (furthestType == 1 ? tankListPtr[furthest].getDistanceTravelled() : (furthestType == 2 ? speedListPtr[furthest].getDistanceTravelled() : beastListPtr[furthest].getDistanceTravelled()))) < tankListPtr[i].getDistanceTravelled()) {
                    furthest = i;
                    furthestType = 1;
                }

            }
            if (speedListPtr[i].getActive()) {
                if ((furthestType == 0 ? baseListPtr[furthest].getDistanceTravelled() : (furthestType == 1 ? tankListPtr[furthest].getDistanceTravelled() : (furthestType == 2 ? speedListPtr[furthest].getDistanceTravelled() : beastListPtr[furthest].getDistanceTravelled()))) < speedListPtr[i].getDistanceTravelled()) {
                    furthest = i;
                    furthestType = 2;
                }

            }
            if (beastListPtr[i].getActive()) {
                if ((furthestType == 0 ? baseListPtr[furthest].getDistanceTravelled() : (furthestType == 1 ? tankListPtr[furthest].getDistanceTravelled() : (furthestType == 2 ? speedListPtr[furthest].getDistanceTravelled() : beastListPtr[furthest].getDistanceTravelled()))) < beastListPtr[i].getDistanceTravelled()) {
                    furthest = i;
                    furthestType = 3;
                }
            }
        }

    }
    if (timeCoolDown <= 0) {
        timeCoolDown = SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased * 10;
    }
    static float posToReturn[2];
    posToReturn[0] = (furthestType == 0 ? baseListPtr[furthest].getPosition()[0] : (furthestType == 1 ? tankListPtr[furthest].getPosition()[0] : (furthestType == 2 ? speedListPtr[furthest].getPosition()[0] : beastListPtr[furthest].getPosition()[0])));
    posToReturn[1] = (furthestType == 0 ? baseListPtr[furthest].getPosition()[1] : (furthestType == 1 ? tankListPtr[furthest].getPosition()[1] : (furthestType == 2 ? speedListPtr[furthest].getPosition()[1] : beastListPtr[furthest].getPosition()[1])));
    return posToReturn;
}

bool enemyManager::checkHit(float x, float y)
{
    bool wasHit = false;
    for (int i = 0; i < 10000; i++) {
        if (bulletListPtr[i].getActive()) {
            if (bulletListPtr[i].isCollide(x, y)) {
                wasHit = true;
                enemyManager::Get().resetBullets(&bulletListPtr[i]);
                i = 10000;
            }
        }
    }
    return wasHit;
}

int enemyManager::getSelectedUI()
{
    return uiThingPtr[0].getSelected();
}

void enemyManager::changeSelectedUI()
{
    for (int i = 0; i < 4; i++) {

        uiThingPtr[i].changeSelected();
    }
}

void enemyManager::Update(float deltaTime)
{
    for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased; i++) {
        baseListPtr[i].Update(deltaTime);
        tankListPtr[i].Update(deltaTime);
        speedListPtr[i].Update(deltaTime);
        beastListPtr[i].Update(deltaTime);
        towerListPtr[i].Update(deltaTime);
        fastTowerListPtr[i].Update(deltaTime);
        fasterTowerListPtr[i].Update(deltaTime);
        fastestTowerListPtr[i].Update(deltaTime);
    }
    for (int i = 0; i < 10000; i++) {
        bulletListPtr[i].Update(deltaTime);
    }
}

void enemyManager::Render()
{
    for (int i = 0; i < SAVED_AMOUNT_OF_ENEMIES * timesSizeIncreased; i++) {
        
        baseListPtr[i].Render();
        tankListPtr[i].Render();
        speedListPtr[i].Render();
        beastListPtr[i].Render();
        towerListPtr[i].Render();
        fastTowerListPtr[i].Render();
        fasterTowerListPtr[i].Render();
        fastestTowerListPtr[i].Render();
    }
    for (int i = 0; i < 192; i++) {
        hitBoxListPtr[i].Render();
    }
    for (int i = 0; i < 4; i++) {
        uiThingPtr[i].Render();
    }
    for (int i = 0; i < 10000; i++) {
        bulletListPtr[i].Render();
    }
}
