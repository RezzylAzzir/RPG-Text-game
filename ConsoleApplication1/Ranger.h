#pragma once
class Ranger
{
public:
	static int Autoshoot(const int playerstr, const int playerphatk);
	static int PowerArrow(const int playerstr, const int playerphatk);
	static int HealthRegeneration(const int playerhp, const int playerlvl);
	static void ShowSkillList();
	Ranger();
	~Ranger();
};


