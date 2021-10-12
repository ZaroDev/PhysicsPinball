#pragma once
#include "Module.h"
#include "Globals.h"



class ModuleSceneEnding : public Module
{
public:
	ModuleSceneEnding(Application* app, bool start_enabled = true);
	~ModuleSceneEnding();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);
private:

	SDL_Texture* background;
	SDL_Texture* gameover;
	SDL_Texture* highscore;
	SDL_Texture* playAgain;
	int counter;
	int yareSFX;
	


};

