#include "stdafx.h"
#include "UI.h"

uiSelection::uiSelection()
{
	uiSelected = 0;
	static int tower = -1;
	tower++;
	sprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 13);
	switch (tower) {
	case 0:
		sprite->SetPosition(64.0f, 64.0f);
		sprite->SetFrame(10);
		break;
	case 1:
		sprite->SetPosition(64.0f, 192);
		sprite->SetFrame(8);
		break;
	case 2:
		sprite->SetPosition(64.0f, 320);
		sprite->SetFrame(6);
		break;
	case 3:
		sprite->SetPosition(64.0f, 448);
		sprite->SetFrame(4);
		break;
	}
	sprite->SetScale(1.0f);
}

void uiSelection::Update(float deltaTime)
{
	
}

void uiSelection::Render()
{
	sprite->Draw();
}

int uiSelection::getSelected()
{
	return uiSelected;
}

void uiSelection::changeSelected()
{
	uiSelected++;
	if (uiSelected > 3) {
		uiSelected = 0;
	}
}
