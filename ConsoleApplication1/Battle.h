#pragma once
#include "Character.h"
#include "Hostile.h"
#include "queue.h"
class Battle
{
	/*friend */
private:
	int targethp;
public:
	void Fight(Character &player, char *pet_name, Queue names, Queue &Battlestats);
	void WarriorBattle(Hostile &hostile, Character &player, char *pet_name, Queue &Battlestats);
	void WizardBattle(Hostile &hostile, Character &player, char *pet_name, Queue &Battlestats);
	void RangerBattle(Hostile &hostile, Character &player, char *pet_name, Queue &Battlestats);
	/*Battle(const int playerlvl);*/
	Battle();
	~Battle();
};

