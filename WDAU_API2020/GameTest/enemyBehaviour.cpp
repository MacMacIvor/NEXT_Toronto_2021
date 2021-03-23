#include "stdafx.h"
#include "maps.h" //This is the only script that needs to use it so no need to add it anywhere else

baseEnemy::baseEnemy(float x, float y, float speedPas, int hp)
{
	pos[0] = x; 
	pos[1] = y; 
	speed = speedPas; 
	isActive = false; 
	dir = -1; //up = 1, left = 0, down = -1, right = -2
	static int ID = -1; 
	ID++; 
	objectID = ID;
	sprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 13);
	sprite->SetPosition(900.0f, 600.0f);
	sprite->SetFrame(2);
	sprite->SetScale(1.0f);
	health = hp;
}

void baseEnemy::Update(float a_DeltaTime)
{
	float futurePosition[2] = { pos[0], pos[1] };
	if (this->getActive() == true) {
		switch (dir) {
		case 1:
			pos[1] -= speed * a_DeltaTime / 1000.0f;
			futurePosition[1] -= 5 * speed * a_DeltaTime / 1000.0f;
			break;
		case 0:
			pos[0] += speed * a_DeltaTime / 1000.0f;
			futurePosition[0] += 5 * speed * a_DeltaTime / 1000.0f;
			break;
		case -1:
			pos[1] += speed * a_DeltaTime / 1000.0f;
			futurePosition[1] += 5 * speed * a_DeltaTime / 1000.0f;
			break;
		case -2:
			pos[0] -= speed * a_DeltaTime / 1000.0f;
			futurePosition[0] -= 5 * speed * a_DeltaTime / 1000.0f;
			break;
		}
		
		sprite->SetPosition(pos[0], pos[1]);

		sprite->Update(a_DeltaTime);
		

		if (HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
			switch (dir) {
			case 1:
				//Need to check if it can move left or right
				futurePosition[1] = pos[1];
				futurePosition[0] = pos[0] + 4 * speed * a_DeltaTime / 1000.0f; // left
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = 0;
				}

				futurePosition[0] = pos[0] - 4 * speed * a_DeltaTime / 1000.0f; // right
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == 1) {
					dir = -2;
				}

				break;
			case 0:
				//Need to check if it can move up or down
				futurePosition[0] = pos[0];
				futurePosition[1] = pos[1] + 4 * speed * a_DeltaTime / 1000.0f; // down
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = -1;
				}

				futurePosition[1] = pos[1] - 4 * speed * a_DeltaTime / 1000.0f; // up
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == 0) {
					dir = 1;
				}
				break;
			case -1:
				//Need to check if it can move left or right
				futurePosition[1] = pos[1];
				futurePosition[0] = pos[0] + 4 * speed * a_DeltaTime / 1000.0f; // left
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = 0;
				}

				futurePosition[0] = pos[0] - 4 * speed * a_DeltaTime / 1000.0f; // right
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == -1) {
					dir = -2;
				}

				break;
			case -2:
				//Need to check if it can move up or down
				futurePosition[0] = pos[0];
				futurePosition[1] = pos[1] + 4 * speed * a_DeltaTime / 1000.0f; // down
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = -1;
				}

				futurePosition[1] = pos[1] - 4 * speed * a_DeltaTime / 1000.0f; // up
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == -2) {
					dir = 1;
				}
				break;
			}
		}
		if (pos[1] <= 64) {
			enemyManager::Get().resetEnemy(this);
			this->distTrav = 0;
			enemyManager::Get().modHealth(this->health);
			this->health = 1;
		}
		distTrav += (pos[0] < 0 ? pos[0] * -1 : pos[0]) + (pos[1] < 0 ? pos[1] * -1 : pos[1]);
		if (enemyManager::Get().checkHit(pos[0], pos[1])) {
			health--;
			if (health <= 0) {
				enemyManager::Get().resetEnemy(this);
				this->distTrav = 0;
				this->health = 1;
			}
		}
	}
}

void baseEnemy::Render()
{
	if (this->getActive() == true) {
		sprite->Draw();
	}
}

void HitBoxes::setHitBoxes(int mapToLoad, int index)
{
	int y = index / 16;
	int x = (index - (16 * y));
	if (x == -1) {
		y -= 1;
		x = 16;
	}
	if (maps[mapToLoad][y][x] == 0) {
		sprite = App::CreateSprite(".\\TestData\\HitBox.bmp", 2, 1);
		sprite->SetPosition(32.0f + 64.0f * (x), 32.0f + 64.0f * (y));
		positionOfHitBoxes[0] = 32.0f + 64.0f * x;
		positionOfHitBoxes[1] = 32.0f + 64.0f * y;
		sprite->SetFrame(3);
		sprite->SetScale(2.0f);
	}
}

void HitBoxes::Update(float a_DeltaTime)
{
}

void HitBoxes::Render()
{
	if (sprite != nullptr)
		sprite->Draw();

}

bool HitBoxes::isColliding(float x, float y)
{
	int yArray = ((y) / 64.0f);
	int xArray = ((x) / 64.0f);
	if (maps[0][yArray][xArray] == 0) {
		return true;
	}
	return false;
}

tankEnemy::tankEnemy(float x, float y, float speedPas, int hp):baseEnemy(x, y, speedPas, hp)
{
	sprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 13);
	sprite->SetPosition(900.0f, 600.0f);
	sprite->SetFrame(0);
	sprite->SetScale(1.0f);
	isActive = false;
	pos[0] = x;
	pos[1] = y;
	speed = speedPas;
	dir = -1; //up = 1, left = 0, down = -1, right = -2
	health = hp;

}

void tankEnemy::Update(float a_DeltaTime)
{
	float futurePosition[2] = { pos[0], pos[1] }; //Checks where the enemy will end up in the near future
	if (this->getActive() == true) {
		switch (dir) {
		case 1:
			pos[1] -= speed * a_DeltaTime / 1000.0f;
			futurePosition[1] -= 5 * speed * a_DeltaTime / 1000.0f;
			break;
		case 0:
			pos[0] += speed * a_DeltaTime / 1000.0f;
			futurePosition[0] += 5 * speed * a_DeltaTime / 1000.0f;
			break;
		case -1:
			pos[1] += speed * a_DeltaTime / 1000.0f;
			futurePosition[1] += 5 * speed * a_DeltaTime / 1000.0f;
			break;
		case -2:
			pos[0] -= speed * a_DeltaTime / 1000.0f;
			futurePosition[0] -= 5 * speed * a_DeltaTime / 1000.0f;
			break;
		}

		sprite->SetPosition(pos[0], pos[1]);

		sprite->Update(a_DeltaTime);


		if (HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
			switch (dir) {
			case 1:
				//Need to check if it can move left or right
				futurePosition[1] = pos[1];
				futurePosition[0] = pos[0] + 4 * speed * a_DeltaTime / 1000.0f; // left
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = 0;
				}

				futurePosition[0] = pos[0] - 4 * speed * a_DeltaTime / 1000.0f; // right
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == 1) {
					dir = -2;
				}

				break;
			case 0:
				//Need to check if it can move up or down
				futurePosition[0] = pos[0];
				futurePosition[1] = pos[1] + 4 * speed * a_DeltaTime / 1000.0f; // down
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = -1;
				}

				futurePosition[1] = pos[1] - 4 * speed * a_DeltaTime / 1000.0f; // up
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == 0) {
					dir = 1;
				}
				break;
			case -1:
				//Need to check if it can move left or right
				futurePosition[1] = pos[1];
				futurePosition[0] = pos[0] + 4 * speed * a_DeltaTime / 1000.0f; // left
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = 0;
				}

				futurePosition[0] = pos[0] - 4 * speed * a_DeltaTime / 1000.0f; // right
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == -1) {
					dir = -2;
				}

				break;
			case -2:
				//Need to check if it can move up or down
				futurePosition[0] = pos[0];
				futurePosition[1] = pos[1] + 4 * speed * a_DeltaTime / 1000.0f; // down
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = -1;
				}

				futurePosition[1] = pos[1] - 4 * speed * a_DeltaTime / 1000.0f; // up
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == -2) {
					dir = 1;
				}
				break;
			}
		}
		if (pos[1] <= 64) {
			enemyManager::Get().resetEnemy(this);
			this->distTrav = 0;
			enemyManager::Get().modHealth(this->health);
			this->health = 3;
		}
		distTrav += (pos[0] < 0 ? pos[0] * -1 : pos[0]) + (pos[1] < 0 ? pos[1] * -1 : pos[1]);
		if (enemyManager::Get().checkHit(pos[0], pos[1])) {
			health--;
			if (health <= 0) {
				enemyManager::Get().resetEnemy(this);
				this->distTrav = 0;
				this->health = 3;
			}
		}
	}
}

void tankEnemy::Render()
{
	if (this->getActive() == true) {
		sprite->Draw();
	}
}

speedEnemy::speedEnemy(float x, float y, float speedPas, int hp) :baseEnemy(x, y, speedPas, hp)
{
	sprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 13);
	sprite->SetPosition(900.0f, 600.0f);
	sprite->SetFrame(12);
	sprite->SetScale(1.0f);
	isActive = false;
	pos[0] = x;
	pos[1] = y;
	speed = speedPas;
	dir = -1; //up = 1, left = 0, down = -1, right = -2
	health = hp;

}

void speedEnemy::Update(float a_DeltaTime)
{
	float futurePosition[2] = { pos[0], pos[1] }; //Checks where the enemy will end up in the near future
	if (this->getActive() == true) {
		switch (dir) {
		case 1:
			pos[1] -= speed * a_DeltaTime / 1000.0f;
			futurePosition[1] -= 5 * speed * a_DeltaTime / 1000.0f;
			break;
		case 0:
			pos[0] += speed * a_DeltaTime / 1000.0f;
			futurePosition[0] += 5 * speed * a_DeltaTime / 1000.0f;
			break;
		case -1:
			pos[1] += speed * a_DeltaTime / 1000.0f;
			futurePosition[1] += 5 * speed * a_DeltaTime / 1000.0f;
			break;
		case -2:
			pos[0] -= speed * a_DeltaTime / 1000.0f;
			futurePosition[0] -= 5 * speed * a_DeltaTime / 1000.0f;
			break;
		}

		sprite->SetPosition(pos[0], pos[1]);

		sprite->Update(a_DeltaTime);


		if (HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
			switch (dir) {
			case 1:
				//Need to check if it can move left or right
				futurePosition[1] = pos[1];
				futurePosition[0] = pos[0] + 4 * speed * a_DeltaTime / 1000.0f; // left
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = 0;
				}

				futurePosition[0] = pos[0] - 4 * speed * a_DeltaTime / 1000.0f; // right
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == 1) {
					dir = -2;
				}

				break;
			case 0:
				//Need to check if it can move up or down
				futurePosition[0] = pos[0];
				futurePosition[1] = pos[1] + 4 * speed * a_DeltaTime / 1000.0f; // down
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = -1;
				}

				futurePosition[1] = pos[1] - 4 * speed * a_DeltaTime / 1000.0f; // up
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == 0) {
					dir = 1;
				}
				break;
			case -1:
				//Need to check if it can move left or right
				futurePosition[1] = pos[1];
				futurePosition[0] = pos[0] + 4 * speed * a_DeltaTime / 1000.0f; // left
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = 0;
				}

				futurePosition[0] = pos[0] - 4 * speed * a_DeltaTime / 1000.0f; // right
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == -1) {
					dir = -2;
				}

				break;
			case -2:
				//Need to check if it can move up or down
				futurePosition[0] = pos[0];
				futurePosition[1] = pos[1] + 4 * speed * a_DeltaTime / 1000.0f; // down
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = -1;
				}

				futurePosition[1] = pos[1] - 4 * speed * a_DeltaTime / 1000.0f; // up
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == -2) {
					dir = 1;
				}
				break;
			}
		}
		if (pos[1] <= 64) {
			enemyManager::Get().resetEnemy(this);
			this->distTrav = 0;
			enemyManager::Get().modHealth(this->health);
			this->health = 3;
		}
		distTrav += (pos[0] < 0 ? pos[0] * -1 : pos[0]) + (pos[1] < 0 ? pos[1] * -1 : pos[1]);
		if (enemyManager::Get().checkHit(pos[0], pos[1])) {
			health--;
			if (health <= 0) {
				enemyManager::Get().resetEnemy(this);
				this->distTrav = 0;
				this->health = 3;
			}
		}
	}
}

void speedEnemy::Render()
{
	if (this->getActive() == true) {
		sprite->Draw();
	}
}

beastEnemy::beastEnemy(float x, float y, float beastPas, int hp) :baseEnemy(x, y, beastPas, hp)
{
	sprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 13);
	sprite->SetPosition(900.0f, 600.0f);
	sprite->SetFrame(18);
	sprite->SetScale(1.0f);
	isActive = false;
	pos[0] = x;
	pos[1] = y;
	speed = beastPas;
	dir = -1; //up = 1, left = 0, down = -1, right = -2
	health = hp;

}

void beastEnemy::Update(float a_DeltaTime)
{
	float futurePosition[2] = { pos[0], pos[1] }; //Checks where the enemy will end up in the near future
	if (this->getActive() == true) {
		switch (dir) {
		case 1:
			pos[1] -= speed * a_DeltaTime / 1000.0f;
			futurePosition[1] -= 5 * speed * a_DeltaTime / 1000.0f;
			break;
		case 0:
			pos[0] += speed * a_DeltaTime / 1000.0f;
			futurePosition[0] += 5 * speed * a_DeltaTime / 1000.0f;
			break;
		case -1:
			pos[1] += speed * a_DeltaTime / 1000.0f;
			futurePosition[1] += 5 * speed * a_DeltaTime / 1000.0f;
			break;
		case -2:
			pos[0] -= speed * a_DeltaTime / 1000.0f;
			futurePosition[0] -= 5 * speed * a_DeltaTime / 1000.0f;
			break;
		}

		sprite->SetPosition(pos[0], pos[1]);

		sprite->Update(a_DeltaTime);


		if (HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
			switch (dir) {
			case 1:
				//Need to check if it can move left or right
				futurePosition[1] = pos[1];
				futurePosition[0] = pos[0] + 4 * speed * a_DeltaTime / 1000.0f; // left
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = 0;
				}
				futurePosition[0] = pos[0] - 4 * speed * a_DeltaTime / 1000.0f; // right
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == 1) {
					dir = -2;
				}

				break;
			case 0:
				//Need to check if it can move up or down
				futurePosition[0] = pos[0];
				futurePosition[1] = pos[1] + 4 * speed * a_DeltaTime / 1000.0f; // down
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = -1;
				}

				futurePosition[1] = pos[1] - 4 * speed * a_DeltaTime / 1000.0f; // up
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == 0) {
					dir = 1;
				}
				break;
			case -1:
				//Need to check if it can move left or right
				futurePosition[1] = pos[1];
				futurePosition[0] = pos[0] + 4 * speed * a_DeltaTime / 1000.0f; // left
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = 0;
				}

				futurePosition[0] = pos[0] - 4 * speed * a_DeltaTime / 1000.0f; // right
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == -1) {
					dir = -2;
				}

				break;
			case -2:
				//Need to check if it can move up or down
				futurePosition[0] = pos[0];
				futurePosition[1] = pos[1] + 4 * speed * a_DeltaTime / 1000.0f; // down
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1])) {
					dir = -1;
				}

				futurePosition[1] = pos[1] - 4 * speed * a_DeltaTime / 1000.0f; // up
				if (!HitBoxes::isColliding(futurePosition[0], futurePosition[1]) && dir == -2) {
					dir = 1;
				}
				break;
			}
		}
		if (pos[1] <= 64) {
			enemyManager::Get().resetEnemy(this);
			this->distTrav = 0;
			enemyManager::Get().modHealth(this->health);
			this->health = 3;
		}
		distTrav += (pos[0] < 0 ? pos[0] * -1 : pos[0]) + (pos[1] < 0 ? pos[1] * -1 : pos[1]);
		if (enemyManager::Get().checkHit(pos[0], pos[1])) {
			health--;
			if (health <= 0) {
				enemyManager::Get().resetEnemy(this);
				this->distTrav = 0;
				this->health = 3;
			}
		}
	}
}

void beastEnemy::Render()
{
	if (this->getActive() == true) {
		sprite->Draw();
	}
}
