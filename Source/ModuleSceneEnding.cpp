#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneEnding.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"

ModuleSceneEnding::ModuleSceneEnding(Application* app, bool start_enabled) : Module(app, start_enabled)
{

}

ModuleSceneEnding::~ModuleSceneEnding()
{}

// Load assets
bool ModuleSceneEnding::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;
	App->audio->PlayMusic("pinball/Music/endingMusic.ogg");
	background = App->textures->Load("pinball/Backgrounds/ending.png");
	gameover = App->textures->Load("pinball/Backgrounds/gameover.png");
	highscore = App->textures->Load("pinball/Backgrounds/highscore.png");
	playAgain = App->textures->Load("pinball/Backgrounds/playAgain.png");
	counter = 0;


	return ret;
}

// Load assets
bool ModuleSceneEnding::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneEnding::Update()
{
	counter++;
	App->renderer->Blit(background, 0, 0);
	if (counter < 270)
	{
		if((counter / 60) % 2 == 0)
			App->renderer->Blit(gameover, 0, 0);
	}
	else
	{
		App->renderer->Blit(gameover, 0, 0);
	}
	if (270 > counter < 540)
	{
		if ((counter / 60) % 2 == 0)
			App->renderer->Blit(highscore, 0, 0);
	}
	else
	{
		App->renderer->Blit(highscore, 0, 0);
	}
	if ((counter / 60) % 2 == 0)
		App->renderer->Blit(playAgain, 0, 0);

	return UPDATE_CONTINUE;
}



void ModuleSceneEnding::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{


}