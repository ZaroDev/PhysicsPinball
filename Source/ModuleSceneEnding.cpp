#include "ModuleSceneEnding.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"

ModuleSceneEnding::ModuleSceneEnding(Application* app, bool start_enabled) : Module(app, start_enabled)
{

}

ModuleSceneEnding::~ModuleSceneEnding()
{}

// Load assets
bool ModuleSceneEnding::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;


	return ret;
}

// Load assets
bool ModuleSceneEnding::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneEnding::Update()
{
	

	return UPDATE_CONTINUE;
}

update_status ModuleSceneEnding::PostUpdate()
{

	return update_status();
}

void ModuleSceneEnding::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{


}