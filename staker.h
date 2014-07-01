#ifndef STAKER_H_INCLUDED
#define STAKER_H_INCLUDED

#include <iostream>
#include <stdio.h>

class Staker{
public:
	Staker();

	void setAttack(unsigned int);
	void setStrength(unsigned int);
	void setDefense(unsigned int);
	void setHitpoints(int);

	void setAttackStyle(std::string);

	double getMaxAttackRoll();
	double getMaxStrengthRoll();
	double getMaxDefenseRoll();

	int getHitpoints();

	void damage(unsigned int);
	bool isAlive();
	double getCombatLevel();
	void reset();

	void win();
	unsigned int getWinCount();

private:
	unsigned int attack;
	unsigned int strength;
	unsigned int defense;
	int hitpoints;
	int lifepoints;

	unsigned int winCount;

	std::string attackStyle;
};

#endif // STAKER_H_INCLUDED
