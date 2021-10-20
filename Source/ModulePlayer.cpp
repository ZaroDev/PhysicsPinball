#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"


ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	lives = 3;
	ball = App->textures->Load("pinball/Sprites/ballxd.png");
	

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		ballCol.add(App->physics->CreateCircle(App->input->GetMouseX(), App->input->GetMouseY(), 12, DYNAMIC));
		LOG("ADDED BALL");
	}

	p2List_item<PhysBody*>* c = ballCol.getFirst();

	while (c != NULL)
	{
		int x, y;
		c->data->GetPosition(x, y);
		
		App->renderer->Blit(ball, x, y, NULL, 1.0f, c->data->GetRotation());
		c = c->next;
	}
	

	return UPDATE_CONTINUE;
}



