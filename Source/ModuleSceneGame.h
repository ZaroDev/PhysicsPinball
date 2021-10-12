#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2List.h"


class ModuleSceneGame : public Module
{
public:
	SDL_Texture* tex;
	SDL_Texture* templateTex;
	int score;

	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> chains;

public:
	ModuleSceneGame(Application* app, bool start_enabled = true);
	~ModuleSceneGame();

	bool Start();
	update_status Update();
	bool CleanUp();
	//void OnCollision(PhysBody* bodyA, PhysBody* bodyB);
	


};
