#pragma once
#include "ModuleSceneGame.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "Cordinates.h"
#include "ModulePlayer.h"

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
	background = App->textures->Load("pinball/Backgrounds/game1.png");
	leftP = App->textures->Load("pinball/Sprites/leftP.png");
	rightP = App->textures->Load("pinball/Sprites/rightP.png");

	
	App->player->Enable();


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


	pullL = App->physics->CreateRectangle(195, 928, 50, 12, DYNAMIC);
	pullR = App->physics->CreateRectangle(277, 928, 50, 12, DYNAMIC);
	pLeft = App->physics->CreateCircle(175, 928, 2, STATIC);
	pRight = App->physics->CreateCircle(290, 928, 2, STATIC);
	jLeft = App->physics->CreateRevoluteJoint(pullL, { -0.5, 0 }, pLeft, {0, 0}, 35.0f, false, true);
	jRight = App->physics->CreateRevoluteJoint(pullR, { 0.5, 0 }, pRight, { 0, 0 }, 35.0f, false, true);


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

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT) {
		pLeft->body->ApplyForce({ 0, -3 }, { 0, 0 }, true);
		

	

	}
	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT) {
		pRight->body->ApplyForce({ 0, 3 }, { 0, 0 }, true);




	}




	
	App->renderer->Blit(background, 0, 0);
	int x, y;
	pullL->GetPosition(x, y);
	App->renderer->Blit(leftP, x, y, NULL, 1.0f, pullL->GetRotation());
	pullR->GetPosition(x, y);
	App->renderer->Blit(rightP, x, y, NULL, 1.0f, pullR->GetRotation());

	return UPDATE_CONTINUE;
}

update_status ModuleSceneGame::PostUpdate()
{

	
	return update_status();
}


