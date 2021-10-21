#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2List.h"
#include "p2Point.h"
#include "ModulePhysics.h"
#include "Animation.h"


struct Puller
{
	PhysBody* Rect;
	PhysBody* Circle;
	bool rightSide;
};
struct Piston
{
	PhysBody* pivot;
	PhysBody* mobile;
};
struct Bumper {
	PhysBody* bumper;
	Animation animation;
};

struct Sensor {
	enum sensorValue
	{
		NONE = -1,
		DEATH,
		DIO,
		PLUS10,
		BUTTON,
		START,
		CLOSE,
		MAX
	};
	PhysBody* sensor;
	sensorValue value;
	bool isActive;
	int sensorTimer = 0;
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

	//Puller Objects
	p2List<Puller*> pullers;
	Puller* pLeft;
	Puller* pRight;
	Piston piston;
	p2List<Bumper*> bumpers;
	//Senors
	p2List<Sensor*> sensors;

	p2List<PhysBody*> limit;
	bool openDoor;

public:
	ModuleSceneGame(Application* app, bool start_enabled = true);
	~ModuleSceneGame();

	bool Start();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);
	void CreateSensor(PhysBody* sensor, Sensor::sensorValue sensorType, bool isActive);
	


};
