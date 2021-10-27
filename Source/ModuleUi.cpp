#include "ModuleUi.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFonts.h"
#include "SString.h"

#include <stdio.h>
#include <cstdio>

ModuleUi::ModuleUi(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	score = 4520;
	prevScore = 0;
	highScore = 0;



}

ModuleUi::~ModuleUi()
{
	
}

bool ModuleUi::Start() {

	nums = App->textures->Load("pinball/Sprites/numbers.png");
	App->fonts->Load("pinball/Sprites/numbers.png", "0123456789-", 1);

	return true;
}

update_status ModuleUi::Update()
{
	
	// DRAW SCORE
	SDL_Rect rect = { 0,0,20,19 };
	if (score >= 99999) App->fonts->BlitText(0, 0, 0, "99999");
	else if (score < 0) App->fonts->BlitText(0, 0, 0, "-----");
	else
	{
		SString text("%5d", score);

		
		
	}

	return UPDATE_CONTINUE;
}

bool ModuleUi::CleanUp()
{


	return true;
}

void ModuleUi::Draw()
{


}

void ModuleUi::AddScore(int value)
{
	switch (comboCount)
	{
	case 0: score += value;
		break;
	case 1: score += value * 2;
		break;
	case 2: score += value * 2;
		break;
	case 3: score += value * 3;
		break;
	case 4: score += value * 4;
		break;
	case 5: score += value * 4;
		break;
	default: score += value * 5;
		break;
	}

	switch (specialCount)
	{
	case 0: score += value;
		break;
	case 1: score += value * 2;
		break;
	case 2: score += value * 2;
		break;
	case 3: score += value * 3;
		break;
	case 4: score += value * 4;
		break;
	case 5: score += value * 4;
		break;
	default: score += value * 5;
		break;
	}


}

