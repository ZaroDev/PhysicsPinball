#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2List.h"
#include "p2Point.h"
#include "ModulePhysics.h"
#include "Animation.h"
struct Box {
	PhysBody* body;
	bool setDestruction = false;
	enum Type {
		NONE = -1,
		COMBO
	};
	Type type = NONE;
};

struct Puller
{
	PhysBody* Rect;
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

struct bounceChain
{
	PhysBody* chainBody;

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
	SDL_Texture* boxImg;
	SDL_Texture* spring;
	int score;

	int dioFX;
	int oraSFX;
	int bumperSFX;
	int sideBumperSFX;
	int boxSFX;
	int comboSFX;
	int deadSFX;

	SDL_Texture* oraL;
	SDL_Texture* oraR;

	SDL_Texture* leftP;
	SDL_Texture* rightP;

	p2List<PhysBody*> circles;

	p2List<PhysBody*> chains;

	//Puller Objects
	p2List<Puller*> pullers;
	PhysBody* cLeft;
	PhysBody* cRight;
	Puller* pLeft;
	Puller* pRight;
	Piston piston;
	p2List<Bumper*> bumpers;
	p2List<Bumper*> sideBump;

	//Senors
	p2List<Sensor*> sensors;
	//Boxes
	p2List<Box*> boxes;

	int frames = 0;
	int combo = 0;
	p2List<PhysBody*> limit;
	bool openDoor;
	PhysBody* l;
	bool oraLeft;
	bool oraRight;

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
