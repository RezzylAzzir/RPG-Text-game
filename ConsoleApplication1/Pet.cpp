#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "Pet.h"
#include "Character.h"
using namespace std;


Pet::Pet(char *pet_name)
{
	srand(time(0));
	lvl = 1;
	name = (char*)malloc(sizeof(char) * 100);
	Class = (char*)malloc(sizeof(char) * 100);
	strcpy(name, pet_name);
	strcpy(Class, "Pet");
	str = 1;
	intl = 1;
	agi = 1;
	phatk = 1;
	matk = 1;
	def = 1;
	vit = 1;
	hp = vit;
	wis = 1;
	gold = 0;
	exp = 0;
}

void Pet::header()
{
	cout << "Congratulation! Your pet info is below: " << endl;
}

//void Pet::specialbuff(char *pet_name)
//{
//	if (strcmp(pet_name, "Sylpha") == 0)
//	{
//		
//	}
//	else if (strcmp(pet_name, "Ignis") == 0)
//	{
//		Pet Ignis("Ignis");
//		Ignis.showinfo();
//	}
//}

Pet::~Pet()
{
}
