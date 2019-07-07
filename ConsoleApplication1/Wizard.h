#pragma once
class Wizard
{
public:
	static int ArcaneBolt(const int playerstr, const int playerphatk);
	static int Fireball(const int playerstr, const int playerphatk);
	static int HealthRegeneration(const int playerhp, const int playerlvl);
	static int ManaRegeneration(const int playerwis, const int playerlvl);
	static void ShowSkillList();
	Wizard();
	~Wizard();
};

