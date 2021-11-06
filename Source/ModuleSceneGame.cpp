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
	background = App->textures->Load("pinball/Backgrounds/placeholder.png");
	leftP = App->textures->Load("pinball/Sprites/leftP.png");
	rightP = App->textures->Load("pinball/Sprites/rightP.png");

	
	App->physics->Enable();
	App->player->Enable();

	openDoor = true;
	chains.add(App->physics->CreateChain(0, 0, borders, 134, STATIC));
	chains.add(App->physics->CreateChain(0, 0, limitRight, 12, STATIC));
	chains.add(App->physics->CreateChain(0, 0, limitLeft, 12, STATIC));
	
	// down chains
	Bumper* chdl = new Bumper;
	chdl->bumper = App->physics->CreateChain(0, 0, leftBumper, 10, STATIC);
	chdl->bumper->listener = this;
	sideBump.add(chdl);

	Bumper* chdr = new Bumper;
	chdr->bumper = App->physics->CreateChain(0, 0, rightBumper, 10, STATIC);
	chdr->bumper->listener = this;
	sideBump.add(chdr);


	Bumper* top1 = new Bumper;
	top1->bumper = App->physics->CreateCircle(243, 132, 10, STATIC);
	top1->bumper->listener = this;

	bumpers.add(top1);

	Bumper* top2 = new Bumper;
	top2->bumper = App->physics->CreateCircle(205, 145, 7, STATIC);
	top2->bumper->listener = this;

	bumpers.add(top2);

	Bumper* top3 = new Bumper;
	top3->bumper = App->physics->CreateCircle(175, 158, 6, STATIC);
	top3->bumper->listener = this;

	bumpers.add(top3);
	
	Bumper* top4 = new Bumper;
	top4->bumper = App->physics->CreateCircle(205, 181, 6, STATIC);
	top4->bumper->listener = this;

	bumpers.add(top4);

	Bumper* mid1 = new Bumper;
	mid1->bumper = App->physics->CreateCircle(254, 181, 6, STATIC);
	mid1->bumper->listener = this;

	bumpers.add(mid1);

	Bumper* mid2 = new Bumper;
	mid2->bumper = App->physics->CreateCircle(225, 225, 6, STATIC);
	mid2->bumper->listener = this;

	bumpers.add(mid2);
	

	Bumper* d1 = new Bumper;
	d1->bumper = App->physics->CreateCircle(275, 224, 6, STATIC);
	d1->bumper->listener = this;

	bumpers.add(d1);

	Bumper* d2 = new Bumper;
	d2->bumper = App->physics->CreateCircle(276, 304, 28, STATIC);
	d2->bumper->listener = this;

	bumpers.add(d2);

	Bumper* d3 = new Bumper;
	d3->bumper = App->physics->CreateCircle(212, 380, 28, STATIC);
	d3->bumper->listener = this;

	bumpers.add(d3);

	Bumper* d4 = new Bumper;
	d4->bumper = App->physics->CreateCircle(332, 385, 28, STATIC);
	d4->bumper->listener = this;

	bumpers.add(d4);



	CreateSensor(App->physics->CreateRectangleSensor(0, 924, 1000, 1, STATIC), Sensor::DEATH, true);
	CreateSensor(App->physics->CreateRectangleSensor(241, 540, 21, 14, STATIC), Sensor::DIO, true);

	CreateSensor(App->physics->CreateRectangleSensor(405, 120, 20, 77, STATIC), Sensor::CLOSE, true);


	CreateSensor(App->physics->CreateCircleSensor(238, 59, 16, STATIC), Sensor::BUTTON, true);
	CreateSensor(App->physics->CreateCircleSensor(97, 515+16, 14, STATIC), Sensor::BUTTON, true);
	CreateSensor(App->physics->CreateCircleSensor(365+16, 515+16, 14, STATIC), Sensor::BUTTON, true);
	CreateSensor(App->physics->CreateCircleSensor(104+16, 589+16, 14, STATIC), Sensor::BUTTON, true);
	CreateSensor(App->physics->CreateCircleSensor(343+16, 589+16, 14, STATIC), Sensor::BUTTON, true);
	CreateSensor(App->physics->CreateRectangleSensor(455, 500, 20, 8, STATIC), Sensor::START, true);
	l = new PhysBody();
	l = App->physics->CreateRectangle(435, 120, 10, 50, STATIC);
	limit.add(l);

	pLeft = new Puller();
	pRight = new Puller();
	
	pLeft->Rect = App->physics->CreateRectangle(165, 840, 60, 12, DYNAMIC);
	pRight->Rect = App->physics->CreateRectangle(314, 840, 60, 12, DYNAMIC);
	pLeft->Rect->body->SetAwake(true);
	pRight->Rect->body->SetAwake(true);
	pLeft->Rect->listener = this;
	pRight->Rect->listener = this;
	pRight->rightSide = true;
	pLeft->rightSide = false;
	cLeft = App->physics->CreateCircle(170, 842, 2, STATIC);
	cRight= App->physics->CreateCircle(310, 842, 2, STATIC);
	App->physics->CreateRevoluteJoint(cLeft, { 0, 0 }, pLeft->Rect, {-0.5, 0}, 35.0f, true, true);
	App->physics->CreateRevoluteJoint(cRight, { 0, 0 }, pRight->Rect, { 0.5, 0 }, 35.0f, true, true);

	/*App->physics->CreateRectangle(445, 795, 8, 5, STATIC);
	App->physics->CreateRectangle(465, 795, 8, 5, STATIC);*/

	piston.pivot = App->physics->CreateRectangle(455, 894, 8, 8, STATIC);
	piston.mobile = App->physics->CreateRectangle(455, 794, 8, 8, DYNAMIC);
	App->physics->CreatePrismaticJoint(piston.mobile, { 0,0 }, piston.pivot, { 0,0 }, { 0,1 }, 1.9f, false, true);

	pullers.add(pLeft);
	pullers.add(pRight);

	dioFX = App->audio->LoadFx("pinball/SFX/daworldo.wav");
	oraSFX = App->audio->LoadFx("pinball/SFX/ora.wav");
	bumperSFX = App->audio->LoadFx("pinball/SFX/bumperSFX.wav");
	sideBumperSFX = App->audio->LoadFx("pinball/SFX/sideBumperSFX.wav");

	oraL = App->textures->Load("pinball/FX/oraoraL.png");
	oraR = App->textures->Load("pinball/FX/oraoraR.png");
	oraLeft = false;
	oraRight = false;
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
	p2List_item<Sensor*>* s = sensors.getFirst();

	while (s != NULL)
	{

		if (bodyA == s->data->sensor && bodyB->listener == (Module*)App->player && s->data->isActive)
		{
			
			if (s->data->value == Sensor::DEATH)
			{
				App->player->lives--;
				App->player->spawnBall = true;
				s->data->isActive = false;

			}
			if (s->data->value == Sensor::START)
			{
				p2List_item<Sensor*>* reset = sensors.getFirst();
				while (reset != NULL)
				{
					s->data->isActive = false;
					reset->data->isActive = true;
					reset = reset->next;

				}
				openDoor = true;
				
			}
			
			if (s->data->value == Sensor::CLOSE)
			{
				openDoor = false;
			}
			if (s->data->value == Sensor::DIO)
			{
				App->audio->PlayFx(dioFX);
				s->data->isActive = false;
			}

		}

		s = s->next;

	}
	p2List_item<Puller*>* p = pullers.getFirst();
	while (p != NULL)
	{
		if (bodyA == p->data->Rect && p->data->rightSide == false && bodyB->listener == (Module*)App->player)
		{
			App->audio->PlayFx(oraSFX);
			oraLeft = true;
			App->renderer->Blit(oraL, 150, 728, NULL);
		}
		if (bodyA == p->data->Rect && p->data->rightSide == true && bodyB->listener == (Module*)App->player)
		{
			App->audio->PlayFx(oraSFX);
			oraRight = true;
			App->renderer->Blit(oraR, 270, 728, NULL);
		}
		p = p->next;
	}
	p2List_item<Bumper*>* b = bumpers.getFirst();
	
	while (b != NULL)
	{

 		if (bodyA == b->data->bumper && bodyB->listener == (Module*)App->player)
		{
			App->audio->PlayFx(bumperSFX);
			b2Vec2 force(bodyB->body->GetWorldCenter() - bodyA->body->GetWorldCenter());
			force *= 2;
			bodyB->body->ApplyLinearImpulse(force, bodyB->body->GetWorldCenter(), true);
			b->data->animation.Update();
			//App->player->currentScore += 100;
			return;
		}
		b = b->next;
	}
	int r = (rand() % 100) / 20;
	if (bodyA == sideBump.getFirst()->data->bumper && bodyB->listener == (Module*)App->player)
	{
		App->audio->PlayFx(sideBumperSFX);
		bodyB->body->ApplyLinearImpulse(b2Vec2(r, -r), bodyB->body->GetWorldCenter(), true);
		//App->player->currentScore += 10;
		return;
	}
	if (bodyA == sideBump.getLast()->data->bumper && bodyB->listener == (Module*)App->player)
	{
		App->audio->PlayFx(sideBumperSFX);
		bodyB->body->ApplyLinearImpulse(b2Vec2(-r,-r), bodyB->body->GetWorldCenter(), true);
		//App->player->currentScore += 10;
		return;
	}
	if (bodyA == l && bodyB->listener == (Module*)App->player)
	{
		b2Vec2 force(bodyB->body->GetWorldCenter() - bodyA->body->GetWorldCenter());
		force *= 0.1f;
		bodyB->body->ApplyAngularImpulse(force.y, true);
	}
}

// Update: draw background
update_status ModuleSceneGame::Update()
{

	if (App->input->GetKey(SDL_SCANCODE_F2) == KEY_DOWN)
		App->fade_to_black->FadeToBlack(this, (Module*)App->scene_ending);

	if(App->player->lives <= 0)
		App->fade_to_black->FadeToBlack(this, (Module*)App->scene_ending);

	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_STATE::KEY_REPEAT)
	{
		App->renderer->camera.y -= 1;
	}
	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		App->renderer->camera.y += 1;
	}


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

	if (openDoor)
	{
		l->body->SetTransform({PIXEL_TO_METERS(535),PIXEL_TO_METERS(120)}, 0);
	}
	else
	{
		l->body->SetTransform({ PIXEL_TO_METERS(435),PIXEL_TO_METERS(120) }, 0);
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
