#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2List.h"
#include "p2Point.h"
#include "ModulePhysics.h"
struct Puller
{
	PhysBody* Rect;
	PhysBody* Circle;
	bool rightSide;
};

class ModuleSceneGame : public Module
{
public:
	SDL_Texture* background;
	int score;

	SDL_Texture* leftP;
	SDL_Texture* rightP;

	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> chains;
	p2List<Puller*> pullers;
	Puller* pLeft;
	Puller* pRight;
	

public:
	ModuleSceneGame(Application* app, bool start_enabled = true);
	~ModuleSceneGame();

	bool Start();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	//void OnCollision(PhysBody* bodyA, PhysBody* bodyB);
	


};
