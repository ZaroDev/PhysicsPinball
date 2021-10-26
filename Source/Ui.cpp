#include "Score.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

Ui::Ui(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	points = 0;
	prevScore = 0;
	highScore = 0;

	/*scoreTex = App->textures->Load("");
	prevScoreTex = App->textures->Load("");
	highScoreTex = App->textures->Load("");
	nums = App->textures->Load("");*/
}

Ui::~Ui()
{
	
}

bool Ui::Start() {


	return true;
}

update_status Ui::Update()
{
	
	//Draw();

	return UPDATE_CONTINUE;
}

bool Ui::CleanUp()
{


	return true;
}

void Ui::Draw()
{
	//bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section = NULL, float speed = 1.0f, double angle = 0, int pivot_x = INT_MAX, int pivot_y = INT_MAX);
	int spacing = 1;
	int position = 0;
	for (int i = 5; i > 1; i--)
	{
		int numToDraw = points / (10^(i-1));
		SDL_Rect rect = { numToDraw*xOffset,0,xOffset,yOffset };
		bool drawn = App->renderer->Blit(nums, position * xOffset, 0, &rect, 1.0, 0, 0, 0);
	}
}

void Ui::AddScore(int value)
{
	switch (comboCount)
	{
	case 0: points += value;
		break;
	case 1: points += value * 2;
		break;
	case 2: points += value * 2;
		break;
	case 3: points += value * 3;
		break;
	case 4: points += value * 4;
		break;
	case 5: points += value * 4;
		break;
	default: points += value * 5;
		break;
	}

	switch (specialCount)
	{
	case 0: points += value;
		break;
	case 1: points += value * 2;
		break;
	case 2: points += value * 2;
		break;
	case 3: points += value * 3;
		break;
	case 4: points += value * 4;
		break;
	case 5: points += value * 4;
		break;
	default: points += value * 5;
		break;
	}


}

