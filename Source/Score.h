#pragma once
#include "Module.h"
class Score : public Module
{
public:
	Score(Application* app, bool start_enabled = true);
	virtual ~Score();

	void AddScore(int value);
	void Draw();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	int points;
	int prevScore;
	int highScore;

	int comboCount;
	int specialCount;

private:
	SDL_Texture* scoreTex = nullptr;
	SDL_Texture* prevScoreTex = nullptr;
	SDL_Texture* highScoreTex = nullptr;
	SDL_Texture* nums = nullptr;

	int xOffset = 1;
	int yOffset = 1;
	int maxDrawNums = 5;
};

