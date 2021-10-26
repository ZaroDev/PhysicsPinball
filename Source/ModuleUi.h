#ifndef __UI_H__
#define __UI_H__


#pragma once
#include "Module.h"


class ModuleUi : public Module
{
public:
	ModuleUi(Application* app, bool start_enabled);
	virtual ~ModuleUi();

	void AddScore(int value);
	void Draw();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	int score;
	int prevScore;
	int highScore;

	int comboCount;
	int specialCount;

private:
	SDL_Texture* nums = nullptr;
	int numW = 20;
	int numH= 19;
	int maxDrawNums = 5;
};

#endif // !__UI_H__
