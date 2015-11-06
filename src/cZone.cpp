#include "include/cZone.h"

cZone::cZone(void) 
{
	current = 0;
}

cZone::~cZone(void) {}

void cZone::Reset() 
{
	for (int i = 0; i < current; ++i) {
		enemies[i].Reset();
	}
}

void cZone::Draw(float playerx, float playery) 
{
	for (int i = 0; i < current; ++i) {
		enemies[i].Draw((*Data).GetID(IMG_ENEMIES), playerx, playery);
	}
}

void cZone::Logic(int *map) {
	for (int i = 0; i < current; i++) enemies[i].Logic(map);
}

void cZone::addEnemy(float x, float y, int type, bool thrower, int z)
{
	enemies[current] = cEnemy(x,y,type,thrower, z);
	enemies[current].SetOverworld(overworld);
	enemies[current].SetWidthHeight(TILE_SIZE, TILE_SIZE);
	
	int i = rand() % 4;
	switch (i) {
		case 0: enemies[current].SetState(STATE_LOOKDOWN); break;
		case 1: enemies[current].SetState(STATE_LOOKUP); break;
		case 2: enemies[current].SetState(STATE_LOOKLEFT); break;
		case 3: enemies[current].SetState(STATE_LOOKRIGHT); break;
	}

	++current;
}

//void addObject();

cEnemy* cZone::GetEnemies() {
	return enemies;
}

void cZone::SetData(cData *data) {
	Data = data;
}

void cZone::SetOverworld(bool over) {
	overworld = over;
}