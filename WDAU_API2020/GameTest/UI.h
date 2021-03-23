#pragma once
#include "app\app.h"

class uiSelection {
public:
	uiSelection();
	void Update(float deltaTime);
	void Render();
	int getSelected();
	void changeSelected();
private:
	int uiSelected;
	CSimpleSprite* sprite;
};