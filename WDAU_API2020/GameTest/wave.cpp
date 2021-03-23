#include "stdafx.h"
#include "wave.h"

wave::wave()
{
	timer = 4;
	waveAt = 1;

	time_t timeNow = time_t(&timeNow);
	somethingForPsudorandom = timeNow;
}

void wave::spawn(float a_DeltaTime)
{
	static bool doneSpawning = true;
	static int amountToSpawn = 1;
	static int amountSpawned = 0;
	static bool entered = false;
	time_t timeNow = time_t(&timeNow);

	static int lastRand = 5;

	lastRand--;
	somethingForPsudorandom *= 1.5;

	if (timer <= 0 || doneSpawning == false) {
		//Spawn wave
		if (!entered) {
			timer = 6;
		}
		doneSpawning = false;
		static float mimiTimer = 0.2f;
		if (mimiTimer <= 0) {
			mimiTimer = 0.6f;
			
			if (amountSpawned < amountToSpawn) {
				if (waveAt < 19) {
					if (amountSpawned >= 0 && amountSpawned < 7) {
						enemyManager::Get().getEnemyBaseToSpawn(928, 736);
						amountSpawned++;
					}
					else if (amountSpawned > 6 && amountSpawned < 13) {
						enemyManager::Get().getEnemyTankToSpawn(928, 736);
						amountSpawned++;
					}
					else if (amountSpawned > 12 && amountSpawned < 19) {
						enemyManager::Get().getEnemySpeedToSpawn(928, 736);
						amountSpawned++;
					}
				}
				else {
					int randomNumber = (lastRand + somethingForPsudorandom);
					int test = somethingForPsudorandom;
					lastRand = randomNumber;
					randomNumber = randomNumber % 10;
					randomNumber < 0 ? randomNumber *= -1 : randomNumber;
					switch (randomNumber) {
					case 0:
						enemyManager::Get().getEnemyBaseToSpawn(928, 736);
						amountSpawned++;
						break;
						enemyManager::Get().getEnemyTankToSpawn(928, 736);
						break;
						enemyManager::Get().getEnemySpeedToSpawn(928, 736);
						amountSpawned++;
						break;
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
					case 7:
					case 8:
					case 9:
						enemyManager::Get().getEnemyBeastToSpawn(928, 736);
						amountSpawned++;
						break;
					}
				}
			}
			else {
				doneSpawning = true;
				waveAt++;
				amountToSpawn = waveAt * 2;
				amountSpawned = 0;
			}
		}
		mimiTimer -= a_DeltaTime / 1000;
		entered = true;
	}
	else {
		entered = false;
		timer -= a_DeltaTime / 1000;
	}
}
