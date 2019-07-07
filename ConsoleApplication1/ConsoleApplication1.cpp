// Evergarden_Saga.cpp: определяет точку входа для консольного приложения.
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include "Character.h"
#include "asciidrw.h"
#include "windows.h"
#include "Battle.h"
#include "Pet.h"
#include <Queue>
#include <cstdio>
#include <string>

using namespace std;


int main()
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX font;//CONSOLE_FONT_INFOEX is defined in some windows header
	GetCurrentConsoleFontEx(out_handle, false, &font);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
	font.cbSize = sizeof(font);
	font.dwFontSize.X = 8;
	font.dwFontSize.Y = 16;
	font.FontFamily = FF_DONTCARE;
	font.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(out_handle, false, &font);
	COORD maxWindow = GetLargestConsoleWindowSize(out_handle); // размер самого большого возможного консольного окна
	SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1 , maxWindow.Y - 1 };
	SMALL_RECT minWindow = { 0, 0, 0, 0 };
	SetConsoleWindowInfo(out_handle, true, &minWindow);
	SetConsoleScreenBufferSize(out_handle, maxWindow);
	SetConsoleWindowInfo(out_handle, true, &srctWindow);
	//SetConsoleTextAttribute(out_handle, 0x0C);
	//cout << "maxX = " << maxWindow.X << "; " << "maxY = " << maxWindow.Y << endl;

	Queue queuenames;
	Queue Battlestats;
	char *pet_name;
	pet_name = (char*)malloc(100 * sizeof(char));
	char *typer;
	setlocale(LC_ALL, "rus");
	typer = (char*)malloc(100 * sizeof(char));
	asciidrw::draw("intro");
	getchar();
	system("cls");
	asciidrw::draw("newcharacter");
	cout << "Set your character name: ";
	cin >> typer;
	Character player(typer);
	memset(typer, 0, sizeof(char));


	while (1)
	{
		system("cls");
		asciidrw::draw("Classes");
		cout << "Choose your character class: ";
		cin >> typer;
		if (strcmp(typer, "Warrior") == 0)
		{
			strcpy(player.Class, typer);
			system("cls");
			asciidrw::draw("Warriorpic");
			memset(typer, 0, sizeof(char));

			while (1)
			{
				cout << "Are you satisfied with this class? (Y/N) : ";
				cin >> typer;
				if (strcmp(typer, "Y") == 0 || strcmp(typer, "y") == 0)
				{
					break;
				}
				else if (strcmp(typer, "N") == 0 || strcmp(typer, "n") == 0)
				{
					break;
				}
				else
				{
					cout << "Wrong character. Try again" << endl;
					continue;
				}
			}
			if (strcmp(typer, "Y") == 0|| strcmp(typer, "y") == 0)
			{
				player.str = 15;
				player.agi = 80;
				player.vit = 200;
				player.phatk = 25;
				player.def = 12;
				player.wis = 50;
				player.hp = player.vit;
				player.mp = player.wis;
				player.ep = player.agi;
				break;
			}
			else if (strcmp(typer, "N") == 0 || strcmp(typer, "n") == 0)
			{
				continue;
			}
			getchar();
		}
		else if (strcmp(typer, "Wizard") == 0)
		{

			strcpy(player.Class, typer);
			system("cls");
			asciidrw::draw("Wizardpic");
			memset(typer, 0, sizeof(char));
			while (1)
			{
				cout << "Are you satisfied with this class? (Y/N) : ";
				cin >> typer;
				if (strcmp(typer, "Y") == 0 || strcmp(typer, "y") == 0)
				{
					break;
				}
				else if (strcmp(typer, "N") == 0 || strcmp(typer, "n") == 0)
				{
					break;
				}
				else
				{
					cout << "Wrong character. Try again" << endl;
					continue;
				}
			}
			if (strcmp(typer, "Y") == 0 || strcmp(typer, "y") == 0)
			{
				player.intl = 17;
				player.agi = 30;
				player.vit = 100;
				player.matk = 35;
				player.def = 4;
				player.wis = 200;
				player.hp = player.vit;
				player.mp = player.wis;
				player.ep = player.agi;
				break;
			}
			else if (strcmp(typer, "N") == 0 || strcmp(typer, "n") == 0)
			{
				continue;
			}
			getchar();
		}
		else if (strcmp(typer, "Ranger") == 0)
		{
			strcpy(player.Class, typer);
			system("cls");
			asciidrw::draw("Rangerpic");
			memset(typer, 0, sizeof(char));
			while (1)
			{
				cout << "Are you satisfied with this class? (Y/N) : ";
				cin >> typer;
				if (strcmp(typer, "Y") == 0 || strcmp(typer, "y") == 0)
				{
					break;
				}
				else if (strcmp(typer, "N") == 0 || strcmp(typer, "n") == 0)
				{

					break;
				}
				else
				{
					cout << "Wrong character. Try again" << endl;
					continue;
				}
			}

			if (strcmp(typer, "Y") == 0 || strcmp(typer, "y") == 0)
			{
				player.str = 8;
				player.agi = 140;
				player.vit = 140;
				player.phatk = 30;
				player.def = 9;
				player.wis = 80;
				player.hp = player.vit;
				player.mp = player.wis;
				player.ep = player.agi;
				break;
			}
			else if (strcmp(typer, "N") == 0 || strcmp(typer, "n") == 0)
			{
				continue;
			}
			getchar();
		}
		else if (strcmp(typer, "GodMode") == 0)
		{
			strcpy(player.Class, "Warrior");
			memset(typer, 0, sizeof(char));

			
				cout << "Type correct password : ";
				cin >> typer;
				if (strcmp(typer, "Murloc") == 1)
				{
					cout << "Incorrect password" << endl;
					continue;
				}
				//player.lvl = 10;
				player.str = 1500;
				player.agi = 8000;
				player.vit = 200000;
				player.phatk = 25000;
				player.def = 120000;
				player.wis = 50000;
				player.hp = player.vit;
				player.mp = player.wis;
				player.ep = player.agi;
				break;

			getchar();
		}
		else
		{
			cout << "There is no class with that name! Try type it again" << endl;
			memset(typer, 0, sizeof(char));
		}
	}
	memset(typer, 0, sizeof(char));
	system("cls");
	cout << "Set your base characteristics" << endl;
	player.setstat(30);
	getchar();
	system("cls");
	memset(typer, 0, sizeof(char));
	asciidrw::draw("Pets");
	cout << "Select your pet: Sylpha(heal 50 hp per turn) or Ignis(deal 50 damage per turn) : ";
	cin >> typer;

	
	if (strcmp(typer, "Sylpha") == 0)
	{
		Pet pet("Sylpha");
		pet.showinfo();
		getchar();
		strcpy(pet_name, pet.name);
		
	}
	else if (strcmp(typer, "Ignis") == 0)
	{
		Pet pet("Ignis");
		pet.showinfo();
		getchar();
		strcpy(pet_name, pet.name);
	}
	getchar();
	system("cls");
	asciidrw::draw("Header");
	cout << "Choose Your Reality: Hellheim or Alvheim: " << endl;
	cin >> typer;
	if (strcmp(typer, "Hellheim") == 0)
	{
			queuenames.add("GrimReaper");
			queuenames.add("Succubus");
			queuenames.add("Archlord");


	}
	else if (strcmp(typer, "Alvheim") == 0)
	{
			queuenames.add("Angel");
			queuenames.add("Unicorn");
			queuenames.add("CentaurQueen");
	}
	
	cout << "Enjoy your endless journey!"<<endl;
	while (1)
	{
		cout << "Choose option to display: Character(character info), Battlestats(list of killed enemies), Fight(start battle): ";
		cin >> typer;
		if (strcmp(typer, "Character") == 0)
		{
			player.showinfo();
		}
		else if (strcmp(typer, "Fight") == 0)
		{
			
			Battle enemy;
			system("cls");
			asciidrw::draw("Header");
			enemy.Fight(player, pet_name, queuenames, Battlestats);
		}
		else if (strcmp(typer, "Battlestats") == 0)
		{

			Battlestats.show();
		}
		else
		{
			cout << "Incorrect input, please try again" << endl;
		}
	}
	cout << "\n";
	system("pause");
	return 0;
}