#include "stdafx.h"
#include "Warrior.h"
#include "Character.h"
#include "Battle.h"
#include <iostream>
#include <ctime>
using namespace std;

Warrior::Warrior()
{
}

int Warrior::Autoattack(const int playerstr, const int playerphatk)
{
	srand(time(0));
	int dealtdamage = 0;
	dealtdamage = ((playerphatk + playerstr / 4) - 10) + rand() % ((playerphatk + playerstr / 4) + 10);
	cout << "You attacked enemy with sword and dealt " << dealtdamage << " damage!" << endl;
	return dealtdamage;
}

int Warrior::RageSlash(const int playerstr, const int playerphatk)
{
	srand(time(0));
	int dealtdamage = 0;
	dealtdamage = ((playerphatk + playerstr * 2) - 10) + rand() % ((playerphatk + playerstr * 2) + 10);
	cout << "You gone berserk, slashing everything you see around you and dealt " << dealtdamage << " damage!" << endl;
	return dealtdamage;
}

int Warrior::EnergyRegeneration(const int playeragi, const int playerlvl)
{
	int regeneratedenergy = 0;
	regeneratedenergy = playeragi / 10 + playerlvl * 7;
	cout << "You calmly observe situation and regenerated " << regeneratedenergy << " energy!" << endl;
	return regeneratedenergy;
}

void Warrior::ShowSkillList()
{
	cout << "1. Autoattack" << endl;
	cout << "2. Rage Slash" << endl;
	cout << "3. Energy Regeneration" << endl;
}


Warrior::~Warrior()
{
}
