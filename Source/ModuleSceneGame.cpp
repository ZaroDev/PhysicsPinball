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
	
	templateTex = App->textures->Load("pinball/Backgrounds/template.png");


	chains.add(App->physics->CreateChain(0, 0, staticBody01, 18, STATIC));


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





	App->renderer->Blit(templateTex, 0, 0);


	return UPDATE_CONTINUE;
}


