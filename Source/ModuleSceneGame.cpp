#pragma once
#include "ModuleSceneGame.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "ModulePhysics.h"
#include "Cordinates.h"

ModuleSceneGame::ModuleSceneGame(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	
}

ModuleSceneGame::~ModuleSceneGame()
{}

// Load assets
bool ModuleSceneGame::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	App->physics->Enable();

	App->renderer->camera.x = App->renderer->camera.y = 0;

	App->audio->PlayMusic("pinball/Music/gameMusic.ogg");
	background = App->textures->Load("pinball/Backgrounds/jojosex.png");

	chains.add(App->physics->CreateChain(0, 0, staticBody01, 18, STATIC));
	chains.add(App->physics->CreateChain(0, 0, staticBody02, 18, STATIC));
	chains.add(App->physics->CreateChain(0, 0, staticBody03, 70, STATIC));
	chains.add(App->physics->CreateChain(0, 0, staticBody04, 52, STATIC));
	chains.add(App->physics->CreateChain(0, 0, staticBody05, 52, STATIC));
	chains.add(App->physics->CreateChain(0, 0, staticBody06, 52, STATIC));
	chains.add(App->physics->CreateChain(0, 0, staticBody07, 52, STATIC));
	chains.add(App->physics->CreateChain(0, 0, leftBorder, 24, STATIC));
	chains.add(App->physics->CreateChain(0, 0, midleBorder, 30, STATIC));
	chains.add(App->physics->CreateChain(0, 0, rightBorder, 58, STATIC));


	//upper circles
	circles.add(App->physics->CreateCircle(238, 159, 16, STATIC));				//238 es el centro 
	circles.add(App->physics->CreateCircle(180, 200, 28, STATIC));
	circles.add(App->physics->CreateCircle(295, 200, 28, STATIC));
	circles.add(App->physics->CreateCircle(213, 238, 10, STATIC));
	circles.add(App->physics->CreateCircle(262, 238, 10, STATIC));
	//midle circles
	circles.add(App->physics->CreateCircle(123, 350, 45, STATIC));
	circles.add(App->physics->CreateCircle(350, 350, 45, STATIC));
	//down circles
	circles.add(App->physics->CreateCircle(28, 638, 8, STATIC));
	circles.add(App->physics->CreateCircle(447, 638, 8, STATIC));
	circles.add(App->physics->CreateCircle(56, 675, 23, STATIC));
	circles.add(App->physics->CreateCircle(418, 675, 23, STATIC));


	
	return ret;
}

// Load assets
bool ModuleSceneGame::CleanUp()
{
	LOG("Unloading Intro scene");
	App->physics->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneGame::Update()
{
	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
		App->fade_to_black->FadeToBlack(this, (Module*)App->scene_ending);
	

	App->renderer->Blit(background, 0, 0);
	return UPDATE_CONTINUE;
}


