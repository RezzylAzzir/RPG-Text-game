#include "Enemy.h"
#include "stdafx.h"
#include "Character.h"
#include "Battle.h"
#include <iostream>
#include <ctime>
using namespace std;


Enemy::Enemy()
{
}

int Enemy::Bite(const int enemystr, const int enemyphatk)
{
	srand(time(0));
	int dealtdamage = 0;
	dealtdamage = ((enemyphatk + enemystr / 4) - 10) + rand() % ((enemyphatk + enemystr / 4) + 10);
	cout << "Enemy attacked you with bite and dealt " << dealtdamage << " damage!" << endl;
	return dealtdamage;
}

int Enemy::Fury(const int enemystr, const int enemyphatk)
{
	srand(time(0));
	int dealtdamage = 0;
	dealtdamage = ((enemyphatk + enemystr / 2) - 10) + rand() % ((enemyphatk + enemystr / 2) + 10);
	cout << "Enemy attacked you with fury and dealt " << dealtdamage << " damage!" << endl;
	return dealtdamage;
}

Enemy::~Enemy()
{
}
