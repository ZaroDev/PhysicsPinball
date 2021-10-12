#pragma once
#include "Module.h"
#include "Globals.h"


class ModuleSceneGame : public Module
{
public:
	SDL_Texture* tex;
	int score;
public:
	ModuleSceneGame(Application* app, bool start_enabled = true);
	~ModuleSceneGame();

	bool Start();
	update_status Update();
	bool CleanUp();
	//void OnCollision(PhysBody* bodyA, PhysBody* bodyB);
	


};
