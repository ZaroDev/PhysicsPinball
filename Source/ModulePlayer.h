#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModulePhysics.h"
#include "p2List.h"

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	iPoint pos;
	int lives;
	SDL_Texture* ball;
	bool spawnBall;
	p2List<PhysBody*> ballCol;
};