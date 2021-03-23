//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Eample data....
//------------------------------------------------------------------------
CSimpleSprite *testSprite;
CSimpleSprite* testSprite2;
CSimpleSprite* testSprite3;
CSimpleSprite* testSprite4;
enum
{
	ANIM_FORWARDS,
	ANIM_BACKWARDS,
	ANIM_LEFT,
	ANIM_RIGHT,
};
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------

enum gameState {
	START,
	PLAY,
	END
};

static gameState stateOfGame = START;

void Init()
{
	
	enemyManager::Get()._BuildAll();
}
//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	static wave waveController;
	static bool onDownL = false;
	static bool onDownR = false;
	static float mousePos[2];
	static POINT p;

	switch (stateOfGame) {
	case START:
		if (App::IsKeyPressed(VK_RETURN)) {
			stateOfGame = PLAY;
		}
		break;
	case PLAY:
		//------------------------------------------------------------------------
		// Example Sprite Code....
		enemyManager::Get().Update(deltaTime);
		
		if (App::IsKeyPressed(VK_RBUTTON)) {
			if (onDownR != true) {
				enemyManager::Get().changeSelectedUI();
			}
			onDownR = true;
		}
		else {
			onDownR = false;
		}
		if (App::IsKeyPressed(VK_LBUTTON)) {
			if (onDownL != true) {
				App::GetMousePos(mousePos[0], mousePos[1]);
				switch (enemyManager::Get().getSelectedUI()) {
				case 0:
					enemyManager::Get().modMoney(-75);
					if (!(enemyManager::Get().getMoney() < 0))
						enemyManager::Get().getEnemyTowerToSpawn(mousePos[0], mousePos[1], 0);
					else {
						enemyManager::Get().modMoney(75); //Can't buy
					}
					break;
				case 1:
					enemyManager::Get().modMoney(-125);
					if (!(enemyManager::Get().getMoney() < 0))
						enemyManager::Get().getEnemyTowerToSpawn(mousePos[0], mousePos[1], 1);
					else {
						enemyManager::Get().modMoney(125); //Can't buy
					}
					break;
				case 2:
					enemyManager::Get().modMoney(-175);
					if (!(enemyManager::Get().getMoney() < 0))
						enemyManager::Get().getEnemyTowerToSpawn(mousePos[0], mousePos[1], 2);
					else {
						enemyManager::Get().modMoney(175); //Can't buy
					}
					break;
				case 3:
					enemyManager::Get().modMoney(-550);
					if (!(enemyManager::Get().getMoney() < 0))
						enemyManager::Get().getEnemyTowerToSpawn(mousePos[0], mousePos[1], 3);
					else {
						enemyManager::Get().modMoney(550); //Can't buy
					}
					break;
				}

			}
			onDownL = true;
		}
		else {
			onDownL = false;
		}

		waveController.spawn(deltaTime);
		if (enemyManager::Get().getHealth() <= 0) {
			stateOfGame = END;
		}
		break;
	case END:
		exit(1);
		break;
	}
	

}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	char sentence[] = "Selected tower =  ";
	int selected;
	char sentence2[] = "Current money: 00000";
	int tempMoney;
	int index;
	char sentence3[] = "Current health: 000";
	int temphealth;
	int index2;
	int d;
	switch (stateOfGame) {
	case START:
		App::Print(700, 700, "PressEnterToStart");

		break;
	case PLAY:
		enemyManager::Get().Render();
		
		
		selected = enemyManager::Get().getSelectedUI();
		switch (selected) {
	case 0:
		sentence[17] = '1';
		break;
	case 1:
		sentence[17] = '2';
		break;
	case 2:
		sentence[17] = '3';
		break;
	case 3:
		sentence[17] = '4';
		break;
	}
		tempMoney = enemyManager::Get().getMoney();
		index = 19;
		do {
		if (index != 19) {
			tempMoney /= 10;
		}
		int d = tempMoney % 10;
		switch (d) {
		case 1:
			sentence2[index] = '1';
			break;
		case 2:
			sentence2[index] = '2';
			break;
		case 3:
			sentence2[index] = '3';
			break;
		case 4:
			sentence2[index] = '4';
			break;
		case 5:
			sentence2[index] = '5';
			break;
		case 6:
			sentence2[index] = '6';
			break;
		case 7:
			sentence2[index] = '7';
			break;
		case 8:
			sentence2[index] = '8';
			break;
		case 9:
			sentence2[index] = '9';
			break;
		case 0:
			sentence2[index] = '0';
			break;
		}
		index--;
	} while (tempMoney >= 10);

		temphealth = enemyManager::Get().getHealth();
		index2 = 18;
		do {
		if (index2 != 18) {
			temphealth /= 10;
		}
		d = temphealth % 10;
		switch (d) {
		case 1:
			sentence3[index2] = '1';
			break;
		case 2:
			sentence3[index2] = '2';
			break;
		case 3:
			sentence3[index2] = '3';
			break;
		case 4:
			sentence3[index2] = '4';
			break;
		case 5:
			sentence3[index2] = '5';
			break;
		case 6:
			sentence3[index2] = '6';
			break;
		case 7:
			sentence3[index2] = '7';
			break;
		case 8:
			sentence3[index2] = '8';
			break;
		case 9:
			sentence3[index2] = '9';
			break;
		case 0:
			sentence3[index2] = '0';
			break;
		}
		index2--;
	} while (temphealth >= 10);

		App::Print(30, 550, sentence);
		App::Print(30, 535, "RightClick to change selection");
		App::Print(30, 520, "Costs are 75, 125, 175, 550");
		App::Print(30, 505, sentence2);
		App::Print(30, 490, sentence3);

		break;
	case END:

		break;
	}
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	//------------------------------------------------------------------------
	// Example Sprite Code....
	delete testSprite;
	delete testSprite2;
	//------------------------------------------------------------------------
}