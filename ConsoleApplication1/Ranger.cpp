#include "Ranger.h"
#include "stdafx.h"
#include "Character.h"
#include "Battle.h"
#include <iostream>
#include <ctime>
using namespace std;


Ranger::Ranger()
{
}

int Ranger::Autoshoot(const int playerstr, const int playerphatk)
{
	srand(time(0));
	int dealtdamage = 0;
	dealtdamage = ((playerphatk + playerstr / 4) - 10) + rand() % ((playerphatk + playerstr / 4) + 10);
	cout << "You shooted enemy with arrow and dealt " << dealtdamage << " damage!" << endl;
	return dealtdamage;
}

int Ranger::PowerArrow(const int playerstr, const int playerphatk)
{
	srand(time(0));
	int dealtdamage = 0;
	dealtdamage = ((playerphatk + playerstr * 2) - 10) + rand() % ((playerphatk + playerstr * 2) + 10);
	cout << "You shooted with arrow, enchanced with magic and dealt " << dealtdamage << " damage!" << endl;
	return dealtdamage;
}

int Ranger::HealthRegeneration(const int playervit, const int playerlvl)
{
	int regeneratedhealth = 0;
	regeneratedhealth = playervit / 10 + playerlvl * 7;
	cout << "You call a nature for help and regenerated " << regeneratedhealth << " hp!" << endl;
	return regeneratedhealth;
}

void Ranger::ShowSkillList()
{
	cout << "1. Auto Shooting" << endl;
	cout << "2. Power Arrow" << endl;
	cout << "3. Health Regeneration" << endl;
}

Ranger::~Ranger()
{
}
