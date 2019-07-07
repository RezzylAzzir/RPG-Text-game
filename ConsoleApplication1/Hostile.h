#pragma once
#include "Character.h"
#include <iostream>
#include "Queue.h"
using namespace std;
class Hostile :
	public Character
{
private:
	virtual void header();
	
public:
	void showbattlerank();

	//using Character::Character;
	Hostile(const int enemy_lvl, Queue names);
	~Hostile();
};