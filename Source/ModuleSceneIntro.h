#pragma once
#include "Module.h"
#include "Globals.h"



class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

public:
	SDL_Texture* background;
	SDL_Texture* title;
	SDL_Texture* subtitle;
	SDL_Texture* playButton;
	int counter;
	int yesSFX;
	
	
};
