#pragma once
class Hostile;
class Character
{
private:
	virtual void header() {};
public:
	void setstat(int count);
	int str;
	int lvl;
	int intl;
	int agi;
	int ep;
	int vit;
	int hp;
	int matk;
	int phatk;
	int def;
	int wis;
	int mp;
	int gold;
	int exp;
	char *name;
	void showinfo();
	void showbattlerank();
	void CheckLvlUp();
	void WriteInfo(const char a[1000]);
	char *Class;
	//explicit Character(const int enemy_lvl);
	int operator+(Hostile &hostile);
	Character(char *nm);
	Character();
	~Character();
};

