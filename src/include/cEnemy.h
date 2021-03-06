#pragma once

#include "cPepe.h"
#include "cOverworld.h"
#include "cDungeon.h"
#include "cData.h"
#include <vector>

#define MAX_STATE_DELAY			4.0f
#define MAX_STATE_DELAY_BOSS	2.0f

#define OCTOROCT		0
#define STALFOS			1
#define KEESE			2
#define ZOLA			3
#define	BOSS			4
#define STEP_OCTOROCT	0.05f
#define STEP_STALFOS	0.05f
#define STEP_KEESE		0.05f
#define STEP_ZOLA		0.05f
#define STEP_BOSS		0.005f

class cEnemy : public cPepe {
public:
	cEnemy();
	cEnemy(float x, float y, float step, bool thrower, bool dropper, int zone, bool * overworld);
	~cEnemy();

	void Reset();
	void Draw(int tex_id, float playerx, float playery);
	void Attack();
	bool Logic(int *map, float x, float y, int state);
	bool inZone(float x, float y);
	void StopState();
	bool notInScreen(float playerx, float playery);

	void SetOriginalPosition(float x, float y);
	void SetThrower(bool thrower);

	bool hitWithWeapon(float playerx, float playery, int state, float x, float y);
	void die();
	void rebirth();
	bool isDead();
	bool isDropper();
	bool isThrower();
	void SetDropper(bool dropper);
	int GetHealth();
	void SetHealth(int lifes);
	
	void SetStateDelay(float delay);
	float GetStateDelay();

private:
	float original_x;
	float original_y;
	bool thrower;
	int throw_count;
	float state_delay;
	bool dead;
	bool dropper;
	int health;
};