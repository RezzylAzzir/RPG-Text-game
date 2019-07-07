#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "Hostile.h"
#include "Character.h"
#include "Queue.h"
using namespace std;


Hostile::Hostile(const int enemy_lvl, Queue names)
{
	srand(time(0));
	lvl = enemy_lvl;
	if (enemy_lvl > 4)
	{
		if (strcmp(names.front->data, "GrimReaper") == 0)
		{
			names.remove();
		}
		if (strcmp(names.front->data, "Angel") == 0)
		{
			names.remove();
		}
		lvl = lvl + (1 + rand() % 2);
	}
	if (enemy_lvl == 10)
	{
		if (strcmp(names.front->data, "GrimReaper") == 0)
		{
			names.remove();
			names.remove();
		}
		else if (strcmp(names.front->data, "Angel") == 0)
		{
			names.remove();
			names.remove();
		}
		else if (strcmp(names.front->data, "Succubus") == 0)
		{
			names.remove();
		}
		else if (strcmp(names.front->data, "Unicorn") == 0)
		{
			names.remove();
		}
		lvl = lvl + (2 + rand() % 5);
	}
	name = (char*)malloc(sizeof(char) * 100);
	Class = (char*)malloc(sizeof(char) * 100);
	strcpy(name, names.front->data);
	strcpy(Class, "Monster");
	str = 15 + (4 * lvl);
	intl = 17 + (4 * lvl);
	agi = 140 + (70 * lvl);
	phatk = 30 + (8 * lvl);
	matk = 35 + (8 * lvl);
	def = 12 + (4 * lvl);
	vit = 100 + (80 * lvl);
	hp = vit;
	wis = 200 + (70 * lvl);
	gold = 1 + rand() % 20;
	exp = 0;
}

void Hostile::header()
{
	cout << "Defeat this monster and you will get " << lvl * 5 << "exp points." << endl;
}

void Hostile::showbattlerank()
{
	Character::showbattlerank();
	int brank=0;
	brank = ((hp / str) / 3)*lvl;
	cout << "Actual Monster`s Battlerank in comprahansion with player: " << brank << endl;
}

Hostile::~Hostile()
{
}
