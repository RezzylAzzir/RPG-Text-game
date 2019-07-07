#pragma once
#include "Character.h"
#include <iostream>
using namespace std;
class Pet :
	public Character
{
private:
	virtual void header();

public:
	//static void specialbuff(char *pet_name);
	Pet(char *pet_name);
	~Pet();
};
