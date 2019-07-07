#pragma once
class Warrior
{
public:
	static int Autoattack(const int playerstr, const int playerphatk);
	static int RageSlash(const int playerstr, const int playerphatk);
	static int EnergyRegeneration(const int playeragi, const int playerlvl);
	static void ShowSkillList();
	Warrior();
	~Warrior();
};

