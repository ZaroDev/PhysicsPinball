#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;
	
	background = App->textures->Load("pinball/Backgrounds/intro.png");
	title = App->textures->Load("pinball/Backgrounds/logo.png");
	subtitle = App->textures->Load("pinball/Backgrounds/subtitle.png");
	playButton = App->textures->Load("pinball/Backgrounds/playButton.png");

	App->audio->PlayMusic("pinball/Music/introMusic.ogg", 1.0f);
	yesSFX = App->audio->LoadFx("pinball/SFX/yesSFX.wav");

	counter = 0;

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	counter++;
	App->renderer->Blit(background, 0, 0);
	App->renderer->Blit(title, 71, 171);
	App->renderer->Blit(subtitle, 125, 360);
	if ((counter / 60) % 2 == 0)
		App->renderer->Blit(playButton, 70, 625);

	if (App->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN)
	{
		App->audio->PlayFx(yesSFX);
		App->fade_to_black->FadeToBlack(this, (Module*)App->scene_game);
	}

	return UPDATE_CONTINUE;
}


void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{

	
}
