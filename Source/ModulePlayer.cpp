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
	
	spawnBall = true;
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	App->textures->Unload(ball);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		b2BodyDef body;

		body.type = b2_dynamicBody;

		body.position.Set(PIXEL_TO_METERS(App->input->GetMouseX()), PIXEL_TO_METERS(App->input->GetMouseY()));
	
		b2Body* b = App->physics->world->CreateBody(&body);

		b2CircleShape shape;
		shape.m_radius = PIXEL_TO_METERS(13);
		b2FixtureDef fixture;
		fixture.shape = &shape;
		fixture.density = 1.0f;
		
		b->CreateFixture(&fixture);

		PhysBody* pbody = new PhysBody();
		pbody->body = b;
		b->SetUserData(pbody);
		pbody->width = pbody->height = 13;
		ballCol.add(pbody);
		
		ballCol.getLast()->data->listener = this;
	}
	if (spawnBall && lives > 0)
	{
		b2BodyDef body;

		body.type = b2_dynamicBody;

		body.position.Set(PIXEL_TO_METERS(485), PIXEL_TO_METERS(700));

		b2Body* b = App->physics->world->CreateBody(&body);

		b2CircleShape shape;
		shape.m_radius = PIXEL_TO_METERS(13);
		b2FixtureDef fixture;
		fixture.shape = &shape;
		fixture.density = 1.0f;

		b->CreateFixture(&fixture);

		PhysBody* pbody = new PhysBody();
		pbody->body = b;
		b->SetUserData(pbody);
		pbody->width = pbody->height = 13;
		ballCol.add(pbody);
		
		ballCol.getLast()->data->listener = this;
		spawnBall = false;
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



