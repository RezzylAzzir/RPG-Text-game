#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include "Character.h"
#include "Hostile.h"
#include <ctime>
#include <stdio.h>
#include "asciidrw.h"
#include "Queue.h"
using namespace std;

Character::Character()
{

}

Character::Character(char *nm)
{
	name = (char*)malloc(sizeof(char) * 100);
	Class = (char*)malloc(sizeof(char) * 100);
	lvl = 1;
	strcpy(name, nm);
	str = 1;
	intl = 1;
	agi = 30;
	phatk = 1;
	matk = 1;
	def = 1;
	vit = 100;
	wis = 50;
	hp = vit;
	gold = 0;
	exp = 0;
}

//Character::Character(const int enemy_lvl)
//{
//	srand(time(0));
//	lvl = enemy_lvl;
//	if (lvl > 5)
//	{
//		lvl = lvl + (1 + rand() % 2);
//	}
//	if (lvl == 10)
//	{
//		lvl = lvl + (2 + rand() % 5);
//	}
//	name = (char*)malloc(sizeof(char) * 100);
//	strcpy(name, "Enemy ");
//	str = 15 + (4 * lvl);
//	intl = 17 + (4 * lvl);
//	agi = 140 + (70 * lvl);
//	phatk = 30 + (8 * lvl);
//	matk = 35 + (8 * lvl);
//	def = 12 + (4 * lvl);
//	vit = 100 + (80 * lvl);
//	hp = vit;
//	wis = 200 + (70 * lvl);
//	gold = 1 + rand() % 20;
//}

void Character::showinfo()
{
	header();
	cout << "Name: " << name << endl;
	cout << "Class: " << Class << endl;
	cout << "Strength: " << str << endl;
	cout << "Intelligence: " << intl << endl;
	cout << "Agility: " << agi << endl;
	cout << "Phisical Attack: " << phatk << endl;
	cout << "Magic Attack: " << matk << endl;
	cout << "Defence: " << def << endl;
	cout << "Vitality: " << vit << endl;
	cout << "Wisdom: " << wis << endl;
	cout << "Exp: " << exp << "/100" << endl;
	cout << "Gold coins: " << gold << endl;
}

void Character::setstat(int count)
{
	int checknumber = 0;
	int typen;
	char *typech;
	typech = (char*)malloc(100 * sizeof(char));
	while (1)
	{

		system("cls");
		asciidrw::draw("SetStat");
		if (count < 1)
		{
			cout << "You have 0 characteristics points" << endl;
			getchar();
			
			break;
		}
		printf("You have %d characteristics points\n", count);
		WriteInfo("Type stat to increase (Strength, Intelligence, Agility, Wisdom, Vitality. Each 1 point spent on Agi/Wis/Vit increasing stat by 5) :");
		cin >> typech;
		if (strcmp(typech, "Strength") == 0)
		{
			cout << "Type requiered amount: ";
			cin >> typech;
			if (asciidrw::checknumber(typech)==1)
			{
				cout << "Wrong input, try again"<<endl;
				continue;
			}
			else
			{
				typen = asciidrw::checknumber(typech);
			}
			if (typen > count)
			{
				cout << "Not enough points. Try again" << endl;
				continue;
			}
			str = str + typen;
			count = count - typen;
			continue;
		}
		else if (strcmp(typech, "Intelligence") == 0)
		{
			cout << "Type requiered amount: ";
			cin >> typen;
			if (asciidrw::checknumber(typech) == 1)
			{
				cout << "Wrong input, try again" << endl;
				continue;
			}
			else
			{
				typen = asciidrw::checknumber(typech);
			}
			if (typen > count)
			{
				cout << "Not enough points. Try again" << endl;
				continue;
			}
			intl = intl + typen;
			count = count - typen;
			continue;
		}
		else if (strcmp(typech, "Agility") == 0)
		{
			cout << "Type requiered amount: ";
			cin >> typen;
			if (asciidrw::checknumber(typech) == 1)
			{
				cout << "Wrong input, try again" << endl;
				continue;
			}
			else
			{
				typen = asciidrw::checknumber(typech);
			}
			if (typen > count)
			{
				cout << "Not enough points. Try again" << endl;
				continue;
			}
			agi = agi + typen * 5;
			ep = agi;
			count = count - typen;
			continue;
		}
		else if (strcmp(typech, "Wisdom") == 0)
		{
			cout << "Type requiered amount: ";
			cin >> typen;
			if (asciidrw::checknumber(typech) == 1)
			{
				cout << "Wrong input, try again" << endl;
				continue;
			}
			else
			{
				typen = asciidrw::checknumber(typech);
			}
			if (typen > count)
			{
				cout << "Not enough points. Try again" << endl;
				continue;
			}
			wis = wis + typen * 5;
			mp = wis;
			count = count - typen;
			continue;
		}
		else if (strcmp(typech, "Vitality") == 0)
		{
			cout << "Type requiered amount: ";
			cin >> typen;
			if (asciidrw::checknumber(typech) == 1)
			{
				cout << "Wrong input, try again" << endl;
				continue;
			}
			else
			{
				typen = asciidrw::checknumber(typech);
			}
			if (typen > count)
			{
				cout << "Not enough points. Try again" << endl;
				continue;
			}
			vit = vit + typen * 5;
			hp = vit;
			count = count - typen;
			continue;
		}
		else
		{
			cout << "Incorrect characteristic. Try again" << endl;
		}

	}
}

Character::~Character()
{
	free(name);
	free(Class);
	str = 0;
	intl = 0;
	agi = 0;
	phatk = 0;
	matk = 0;
	def = 0;
	vit = 0;
	wis = 0;
}

int Character::operator+(Hostile &hostile)
{
	Character temp;
	temp.exp = this->exp + hostile.lvl * 5;
	return temp.exp;
}

void Character::CheckLvlUp()
{
	if (exp > 99)
	{
		lvl++;
		setstat(10);
		exp = exp - 100;
	}
	else
	{
		return;
	}
}

void Character::WriteInfo(const char a[1000])
{
	puts(a);
}


void Character::showbattlerank()
{
	int battlerank = 0;
	battlerank = hp / str;
	cout << "Battlerank: " << battlerank << endl;
}