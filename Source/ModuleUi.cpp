#include "ModuleUi.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

ModuleUi::ModuleUi(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	score = 0;
	prevScore = 0;
	highScore = 0;



}

ModuleUi::~ModuleUi()
{
	
}

bool ModuleUi::Start() {

	nums = App->textures->Load("pinball/Sprites/numbers.png");

	return true;
}

update_status ModuleUi::Update()
{
	
	Draw();
	//int drawn = 0;
	//SDL_Rect rect = { 0,0,20,19 };
	////if (nums=nullptr) drawn=0;
	//App->renderer->Blit(nums, 500, 0, &rect, 1.0);
	//if (App->renderer->Blit(nums, 500, 50, NULL, 1.0) == true) drawn = 1;
	//printf("drawn %i", drawn);

	return UPDATE_CONTINUE;
}

bool ModuleUi::CleanUp()
{


	return true;
}

void ModuleUi::Draw()
{
	//bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section = NULL, float speed = 1.0f, double angle = 0, int pivot_x = INT_MAX, int pivot_y = INT_MAX);
	int spacing = 12;
	int position = 0;
	for (int i = 5; i > 1; i--)
	{

	}
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

