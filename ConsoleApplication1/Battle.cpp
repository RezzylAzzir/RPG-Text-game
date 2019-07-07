#define _CRT_SECURE_NO_WARNINGS
#include "Battle.h"
#include "stdafx.h"
#include <iostream>
#include "Character.h"
#include "Hostile.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Ranger.h"
#include "Enemy.h"
#include "Pet.h"
#include "asciidrw.h"
#include "queue.h"
using namespace std;


//Battle::Battle(const int playerlvl)
//{
//	Character hostile(playerlvl);
//}

void Battle::Fight(Character &player, char *pet_name, Queue names, Queue &Battlestats)
{
	
	Hostile hostile(player.lvl, names);
	player.showbattlerank();
	cout << hostile.name << " spotted" << endl;
	cout << "Enemy level: " << hostile.lvl << endl;
	hostile.showbattlerank();
	hostile.showinfo();
	if (strcmp(player.Class, "Warrior") == 0)
	{
		WarriorBattle(hostile, player, pet_name, Battlestats);
	}
	else if (strcmp(player.Class, "Wizard") == 0)
	{
		WizardBattle(hostile, player, pet_name, Battlestats);
	}
	else if (strcmp(player.Class, "Ranger") == 0)
	{
		RangerBattle(hostile, player, pet_name, Battlestats);
	}


}

void Battle::WarriorBattle(Hostile &hostile, Character &player, char *pet_name, Queue &Battlestats)
{
	
	int enemy_turn = 1;
	char *typech;
	int typen;
	typech = (char*)malloc(100 * sizeof(char));
	cout << "Type <<Skill_list>> to begin fight" << endl;
	while (1)
	{
		
		//asciidrw::draw("Header");
	
		cin >> typech;
		if (strcmp(typech, "Skill_list") == 0)
		{
			system("cls");
			asciidrw::draw("Header");
			if (strcmp(hostile.name, "Succubus") == 0)
			{
				asciidrw::draw("Succubus");
			}
			else if (strcmp(hostile.name, "GrimReaper") == 0)
			{
				asciidrw::draw("GrimReaper");
			}
			else if (strcmp(hostile.name, "Archlord") == 0)
			{
				asciidrw::draw("Archlord");
			}
			else if (strcmp(hostile.name, "CentaurQueen") == 0)
			{
				asciidrw::draw("CentaurQueen");
			}
			else if (strcmp(hostile.name, "Unicorn") == 0)
			{
				asciidrw::draw("Unicorn");
			}
			else
			{
				asciidrw::draw("Angel");
			}
			Warrior::ShowSkillList();
			cout << "Choose skill number:" << endl;
			cin >> typen;
			switch (typen)
			{
			case 1:

				hostile.hp = hostile.hp - Warrior::Autoattack(player.str, player.phatk);
				break;
			case 2:
				if ((50 + 20 * player.lvl) < player.ep)
				{
					player.ep = player.ep - (50 + 20 * player.lvl);
					hostile.hp = hostile.hp - Warrior::RageSlash(player.str, player.phatk);
				}
				else
				{
					cout << "Not enough energy. Try to use another skill" << endl;
					continue;
				}

				break;
			case 3:

				player.ep = player.ep + Warrior::EnergyRegeneration(player.agi, player.lvl);
				if (player.ep > player.agi)
				{
					player.ep = player.agi;
				}
				break;
			default:
				break;
			}

		}
		else
		{
			cout << "Incorrect text! Type Skill_list to choose skill: " << endl;
			continue;
		}
		if (strcmp(pet_name, "Sylpha") == 0)
		{
			cout << "You recieved a healing from Sylpha and regenerated 50hp "<<endl;
			player.hp = player.hp + 50;
			if (player.hp > player.vit)
			{
				player.hp = player.vit;
			}
		}
		else if (strcmp(pet_name, "Ignis") == 0)
		{
			cout << "Ignis throws a fireball and dealt 50 hp "<<endl;
			hostile.hp = hostile.hp - 50;
		}
		if (player.hp < 1)
		{
			cout << "YOU DIED!" << endl;
			system("pause");
			exit(0);
		}
		else if (hostile.hp < 1)
		{
			if (player.lvl == 10)
			{
				system("cls");
				asciidrw::draw("GoodGameOver");
				cout << "You defetead the most powerful enemy, and now Evergarden can finally be at peace! You have done an unbelievable job, and many centuries further your name will be in every single ballad!" << endl;
				getchar();
				getchar();
				exit(0);
			}
			cout << "Congratulations, you won!" << endl;
			player.exp = player + hostile;
			cout << "You got " << hostile.lvl * 5 << " exp points! " << 100 - player.exp << " untill next lvl" << endl;
			player.CheckLvlUp();
			player.hp = player.vit;
			player.ep = player.agi;
			Battlestats.addforstat(hostile.name, hostile.lvl);
			
			break;
		}

		else
		{
			if (enemy_turn == 3)
			{
				player.hp = player.hp - Enemy::Fury(hostile.str, hostile.phatk);
				enemy_turn = 1;
			}
			else
			{
				player.hp = player.hp - Enemy::Bite(hostile.str, hostile.phatk);
				enemy_turn++;
			}
			cout << "You have" << player.hp << " hp." << endl;
			cout << "Enemy has " << hostile.hp << " hp. Type Skill_list to attack againg." << endl;
			if (player.hp < 1)
			{
				cout << "YOU DIED!" << endl;
				system("pause");
				exit(0);
			}
			continue;
		}
	}
}

void Battle::WizardBattle(Hostile &hostile, Character &player, char *pet_name, Queue &Battlestats)
{
	int enemy_turn = 1;
	char *typech;
	int typen;
	typech = (char*)malloc(100 * sizeof(char));
	cout << "Type <<Skill_list>> to begin fight" << endl;
	while (1)
	{
		
		//asciidrw::draw("Header");
		cin >> typech;
		if (strcmp(typech, "Skill_list") == 0)
		{
			system("cls");
			asciidrw::draw("Header");
			if (strcmp(hostile.name, "Succubus") == 0)
			{
				asciidrw::draw("Succubus");
			}
			else if (strcmp(hostile.name, "GrimReaper") == 0)
			{
				asciidrw::draw("GrimReaper");
			}
			else if (strcmp(hostile.name, "Archlord") == 0)
			{
				asciidrw::draw("Archlord");
			}
			else if (strcmp(hostile.name, "CentaurQueen") == 0)
			{
				asciidrw::draw("CentaurQueen");
			}
			else if (strcmp(hostile.name, "Unicorn") == 0)
			{
				asciidrw::draw("Unicorn");
			}
			else
			{
				asciidrw::draw("Angel");
			}
			Wizard::ShowSkillList();
			cout << "Choose skill number:" << endl;
			cin >> typen;
			switch (typen)
			{
			case 1:

				hostile.hp = hostile.hp - Wizard::ArcaneBolt(player.intl, player.matk);
				break;
			case 2:
				if ((80 + 20 * player.lvl) < player.mp)
				{
					hostile.hp = hostile.hp - Wizard::Fireball(player.intl, player.matk);
					player.mp = player.mp - (80 + 20 * player.lvl);
				}
				else
				{
					cout << "Not enough energy. Try to use another skill" << endl;
					continue;
				}

				break;
			case 3:

				player.hp = player.hp + Wizard::HealthRegeneration(player.vit, player.lvl);
				if (player.hp > player.vit)
				{
					player.hp = player.vit;
				}
				break;
			case 4:

				player.mp = player.mp + Wizard::ManaRegeneration(player.wis, player.lvl);
				if (player.mp > player.wis)
				{
					player.mp = player.wis;
				}
				break;
			default:
				break;
			}

		}
		else
		{
			cout << "Incorrect text! Type Skill_list to choose skill: " << endl;
			continue;
		}
		if (strcmp(pet_name, "Sylpha") == 0)
		{
			cout << "You recieved a healing from Sylpha and regenerated 50hp " << endl;
			player.hp = player.hp + 50;
			if (player.hp > player.vit)
			{
				player.hp = player.vit;
			}
		}
		else if (strcmp(pet_name, "Ignis") == 0)
		{
			cout << "Ignis throws a fireball and dealt 50 hp " << endl;
			hostile.hp = hostile.hp - 50;
		}
		if (player.hp < 1)
		{
			cout << "YOU DIED!" << endl;
			system("pause");
			exit(0);
		}
		else if (hostile.hp < 1)
		{
			cout << "Congratulations, you won!" << endl;
			player.exp = player + hostile;
			cout << "You got " << hostile.lvl * 5 << " exp points! " << 100 - player.exp << " untill next lvl" << endl;
			player.CheckLvlUp();
			player.hp = player.vit;
			player.mp = player.wis;
			Battlestats.addforstat(hostile.name, hostile.lvl);
			break;
		}

		else
		{
			if (enemy_turn == 3)
			{
				player.hp = player.hp - Enemy::Fury(hostile.str, hostile.phatk);
				enemy_turn = 1;
			}
			else
			{
				player.hp = player.hp - Enemy::Bite(hostile.str, hostile.phatk);
				enemy_turn++;
			}
			cout << "You have" << player.hp << " hp." << endl;
			cout << "Enemy has " << hostile.hp << " hp. Type Skill_list to attack againg." << endl;
			if (player.hp < 1)
			{
				cout << "YOU DIED!" << endl;
				system("pause");
				exit(0);
			}
			continue;
		}
	}
}

void Battle::RangerBattle(Hostile &hostile, Character &player, char *pet_name, Queue &Battlestats)
{
	
	int enemy_turn = 1;
	char *typech;
	int typen;
	typech = (char*)malloc(100 * sizeof(char));
	cout << "Type <<Skill_list>> to begin fight" << endl;
	while (1)
	{
		
		//asciidrw::draw("Header");
		cin >> typech;
		if (strcmp(typech, "Skill_list") == 0)
		{

			system("cls");
			asciidrw::draw("Header");
			if (strcmp(hostile.name, "Succubus") == 0)
			{
				asciidrw::draw("Succubus");
			}
			else if (strcmp(hostile.name, "GrimReaper") == 0)
			{
				asciidrw::draw("GrimReaper");
			}
			else if (strcmp(hostile.name, "Archlord") == 0)
			{
				asciidrw::draw("Archlord");
			}
			else if (strcmp(hostile.name, "CentaurQueen") == 0)
			{
				asciidrw::draw("CentaurQueen");
			}
			else if (strcmp(hostile.name, "Unicorn") == 0)
			{
				asciidrw::draw("Unicorn");
			}
			else
			{
				asciidrw::draw("Angel");
			}
			Ranger::ShowSkillList();
			cout << "Choose skill number:" << endl;
			cin >> typen;
			switch (typen)
			{
			case 1:

				hostile.hp = hostile.hp - Ranger::Autoshoot(player.str, player.phatk);
				break;
			case 2:
				if ((70 + 20 * player.lvl) < player.ep)
				{
					player.ep = player.ep - (70 + 20 * player.lvl);
					hostile.hp = hostile.hp - Ranger::PowerArrow(player.str, player.phatk);
				}
				else
				{
					cout << "Not enough energy. Try to use another skill" << endl;
					continue;
				}

				break;
			case 3:

				player.ep = player.ep + Ranger::HealthRegeneration(player.agi, player.lvl);
				if (player.ep > player.agi)
				{
					player.ep = player.agi;
				}
				break;
			default:
				break;
			}


		}
		else
		{
			cout << "Incorrect text! Type Skill_list to choose skill: " << endl;
			continue;
		}

		if (strcmp(pet_name, "Sylpha") == 0)
		{
			cout << "You recieved a healing from Sylpha and regenerated 50hp " << endl;
			player.hp = player.hp + 50;
			if (player.hp > player.vit)
			{
				player.hp = player.vit;
			}
		}
		else if (strcmp(pet_name, "Ignis") == 0)
		{
			cout << "Ignis throws a fireball and dealt 50 hp " << endl;
			hostile.hp = hostile.hp - 50;
		}
		if (player.hp < 1)
		{
			cout << "YOU DIED!" << endl;
			system("pause");
			exit(0);
		}
		else if (hostile.hp < 1)
		{
			cout << "Congratulations, you won!" << endl;
			player.exp = player + hostile;
			cout << "You got " << hostile.lvl * 5 << " exp points! " << 100 - player.exp << " untill next lvl" << endl;
			player.CheckLvlUp();
			player.hp = player.vit;
			player.ep = player.agi;
			Battlestats.addforstat(hostile.name, hostile.lvl);
			break;
		}

		else
		{
			if (enemy_turn == 3)
			{
				player.hp = player.hp - Enemy::Fury(hostile.str, hostile.phatk);
				enemy_turn = 1;
			}
			else
			{
				player.hp = player.hp - Enemy::Bite(hostile.str, hostile.phatk);
				enemy_turn++;
			}
			cout << "You have" << player.hp << " hp." << endl;
			cout << "Enemy has " << hostile.hp << " hp. Type Skill_list to attack againg." << endl;
			if (player.hp < 1)
			{
				cout << "YOU DIED!" << endl;
				system("pause");
				exit(0);
			}
			continue;
		}
	}
}

Battle::Battle()
{

}

Battle::~Battle()
{
}
