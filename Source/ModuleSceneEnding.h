#pragma once
#include "Module.h"
#include "Globals.h"

class PhysBody;

class ModuleSceneEnding : public Module
{
public:
	ModuleSceneEnding(Application* app, bool start_enabled = true);
	~ModuleSceneEnding();

	bool Start();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

public:
	
	


};

