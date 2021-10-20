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
	score = 0;
	App->renderer->camera.x = App->renderer->camera.y = 0;

	App->audio->PlayMusic("pinball/Music/gameMusic.ogg");
	background = App->textures->Load("pinball/Backgrounds/game1.png");
	leftP = App->textures->Load("pinball/Sprites/leftP.png");
	rightP = App->textures->Load("pinball/Sprites/rightP.png");

	
	App->physics->Enable();
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
	circles.add(App->physics->CreateCircle(238, 59, 16, STATIC));				//238 es el centro 
	circles.add(App->physics->CreateCircle(180, 100, 28, STATIC));
	circles.add(App->physics->CreateCircle(295, 100, 28, STATIC));
	circles.add(App->physics->CreateCircle(213, 138, 10, STATIC));
	circles.add(App->physics->CreateCircle(262, 138, 10, STATIC));
	//midle circles
	circles.add(App->physics->CreateCircle(123, 250, 45, STATIC));
	circles.add(App->physics->CreateCircle(350, 250, 45, STATIC));
	//down circles
	circles.add(App->physics->CreateCircle(28, 538, 8, STATIC));
	circles.add(App->physics->CreateCircle(447, 538, 8, STATIC));
	circles.add(App->physics->CreateCircle(56, 575, 23, STATIC));
	circles.add(App->physics->CreateCircle(418, 575, 23, STATIC));

	CreateSensor(App->physics->CreateRectangleSensor(0, 1024, 512, 30, STATIC), Sensor::DEATH, true);

	pLeft = new Puller();
	pRight = new Puller();

	pLeft->Rect = App->physics->CreateRectangle(190, 828, 50, 12, DYNAMIC);
	pRight->Rect = App->physics->CreateRectangle(277, 828, 50, 12, DYNAMIC);
	pRight->rightSide = true;
	pLeft->rightSide = false;
	pLeft->Circle = App->physics->CreateCircle(170, 828, 2, STATIC);
	pRight->Circle = App->physics->CreateCircle(295, 828, 2, STATIC);
	App->physics->CreateRevoluteJoint(pLeft->Circle, { 0, 0 }, pLeft->Rect, {-0.5, 0}, 35.0f, true, true);
	App->physics->CreateRevoluteJoint(pRight->Circle, { 0, 0 }, pRight->Rect, { 0.5, 0 }, 35.0f, false, true);


	piston.pivot = App->physics->CreateRectangle(485, 894, 20, 8, STATIC);
	piston.mobile = App->physics->CreateRectangle(485, 794, 20, 8, DYNAMIC);
	App->physics->CreatePrismaticJoint(piston.mobile, { 0,0 }, piston.pivot, { 0,0 }, { 0,1 }, 1.9f, false, true);

	pullers.add(pLeft);
	pullers.add(pRight);


	return ret;
}

// Load assets
bool ModuleSceneGame::CleanUp()
{
	LOG("Unloading Intro scene");
	App->physics->Disable();
	App->player->Disable();
	App->textures->Unload(leftP);
	App->textures->Unload(rightP);
	App->textures->Unload(background);
	delete pLeft;
	delete pRight;

	return true;
}

void ModuleSceneGame::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	LOG("ONCOLLISION");
	p2List_item<Sensor*>* death = sensors.getFirst();
	p2List_item<PhysBody*>* player = App->player->ballCol.getFirst();
	while (death != NULL)
	{
		if (bodyA == death->data->sensor && bodyB->body == player->data->body)
		{

			App->player->lives--;
			LOG("DEAD");
		}
		death = death->next;
	}
	player = player->next;
}

// Update: draw background
update_status ModuleSceneGame::Update()
{
	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
		App->fade_to_black->FadeToBlack(this, (Module*)App->scene_ending);

	if(App->player->lives <= 0)
		App->fade_to_black->FadeToBlack(this, (Module*)App->scene_ending);


	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		p2List_item<Puller*>* p = pullers.getFirst();
		while (p != NULL)
		{
			if (p->data->rightSide == false)
			{
				p->data->Rect->body->ApplyForce({ -3,0 }, { 0,0 }, true);
			}
			p = p->next;
		}
	}
	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		p2List_item<Puller*>* p = pullers.getFirst();
		while (p != NULL)
		{
			if (p->data->rightSide == true)
			{
				p->data->Rect->body->ApplyForce({ 3,0 }, { 0,0 }, true);
			}
			p = p->next;
		}
	}
	piston.mobile->body->ApplyForce({ 0,-18 }, { 0,0 }, true);
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		piston.mobile->body->ApplyForce({ 0,18 }, { 0,0 }, true);
	}
	else if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_UP)
	{
		piston.mobile->body->ApplyForce({ 0, -50 }, { 0,0 }, true);
	}


	
	
	App->renderer->Blit(background, 0, 0);
	int x, y;
	pLeft->Rect->GetPosition(x, y);
	App->renderer->Blit(leftP, x, y, NULL, 1.0f, pLeft->Rect->GetRotation());
	pRight->Rect->GetPosition(x, y);
	App->renderer->Blit(rightP, x, y, NULL, 1.0f, pRight->Rect->GetRotation());

	return UPDATE_CONTINUE;
}

update_status ModuleSceneGame::PostUpdate()
{

	
	return update_status();
}

void ModuleSceneGame::CreateSensor(PhysBody* sensor, Sensor::sensorValue sensorType, bool isActive)
{
	Sensor* newSensor = new Sensor;
	newSensor->sensor = sensor;
	newSensor->sensor->listener = this;
	newSensor->value = sensorType;
	newSensor->isActive = isActive;
	sensors.add(newSensor);
}
