#pragma once
#include "enemyBehaviour.h"

class wave {
public:
	wave();
	void spawn(float a_DeltaTime); //Spawns a wave of enemies when the timer is up
private:
	float timer;
	int waveAt;
	int somethingForPsudorandom;
};