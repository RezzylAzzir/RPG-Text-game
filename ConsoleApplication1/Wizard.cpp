#include "Wizard.h"
#include "stdafx.h"
#include "Character.h"
#include "Battle.h"
#include <iostream>
#include <ctime>
using namespace std;


Wizard::Wizard()
{
}

int Wizard::ArcaneBolt(const int playerintl, const int playermatk)
{
	srand(time(0));
	int dealtdamage = 0;
	dealtdamage = ((playermatk + playerintl / 4) - 10) + rand() % ((playermatk + playerintl / 4) + 10);
	cout << "You cast little energy bolt which dealt " << dealtdamage << " damage to enemy!" << endl;
	return dealtdamage;
}

int Wizard::Fireball(const int playerintl, const int playermatk)
{
	srand(time(0));
	int dealtdamage = 0;
	dealtdamage = ((playermatk + playerintl * 2) - 10) + rand() % ((playermatk + playerintl * 2) + 10);
	cout << "You cast a fireball and it dealt " << dealtdamage << " damage to enemy!" << endl;
	return dealtdamage;
}

int Wizard::HealthRegeneration(const int playervit, const int playerlvl)
{
	int regeneratedhealth = 0;
	regeneratedhealth = playervit / 10 + playerlvl * 7;
	cout << "You prayed gods for blessing and regenerated " << regeneratedhealth << " hp!" << endl;
	return regeneratedhealth;
}

int Wizard::ManaRegeneration(const int playerwis, const int playerlvl)
{
	int regeneratedmana = 0;
	regeneratedmana = playerwis / 10 + playerlvl * 7;
	cout << "You call the ancient powers for help and regenerated " << regeneratedmana << " mana!" << endl;
	return regeneratedmana;
}

void Wizard::ShowSkillList()
{
	cout << "1. Arcane Bolt" << endl;
	cout << "2. Fireball" << endl;
	cout << "3. Health Regeneration" << endl;
	cout << "4. Mana Regeneration" << endl;
}

Wizard::~Wizard()
{
}
