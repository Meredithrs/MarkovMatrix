#include "staker.h"

Staker::Staker(){
	this->setAttack(99);
	this->setStrength(99);
	this->setDefense(99);
	this->setHitpoints(99);
	this->setAttackStyle("accurate");

	this->winCount	=	0;
}

void Staker::setAttack(unsigned int attack){
	if(attack > 125){
		throw "Levels only go up to 125";
	}
	if(attack <= 0){
		throw "Levels cannot be less than 1";
	}
	this->attack	=	attack;
}

void Staker::setStrength(unsigned int strength){
	if(strength > 125){
		throw "Levels only go up to 125";
	}
	if(strength <= 0){
		throw "Levels cannot be less than 1";
	}
	this->strength	=	strength;
}

void Staker::setDefense(unsigned int defense){
	if(defense > 125){
		throw "Levels only go up to 125";
	}
	if(defense <= 0){
		throw "Levels cannot be less than 1";
	}
	this->defense	=	defense;
}

void Staker::setHitpoints(int hitpoints){
	if(hitpoints > 99){
		throw "Hitpoints only goes up to 99";
	}
	this->hitpoints		=	hitpoints;
	this->lifepoints	=	hitpoints*10;
}

void Staker::setAttackStyle(std::string attackStyle){
	if(attackStyle != "accurate" && attackStyle != "aggressive" && attackStyle != "defensive" && attackStyle != "controlled"){
		throw "Please select a valid attack style";
	}
	this->attackStyle	=	attackStyle;
}

double Staker::getMaxAttackRoll(){
	unsigned int attackBonus	=	0;

	if(this->attackStyle == "accurate"){
		attackBonus	=	3;
	}
	if(this->attackStyle == "controlled"){
		attackBonus	=	1;
	}

	return this->attack + attackBonus + 8;
}

double Staker::getMaxStrengthRoll(){
	unsigned strengthBonus	=	0;

	if(this->attackStyle == "aggressive"){
		strengthBonus	=	3;
	}
	if(this->attackStyle == "controlled"){
		strengthBonus	=	1;
	}

	return this->strength + strengthBonus + 13;
}

double Staker::getMaxDefenseRoll(){
	unsigned int defenseBonus	=	0;

	if(this->attackStyle == "defensive"){
		defenseBonus	=	3;
	}
	if(this->attackStyle == "controlled"){
		defenseBonus	=	1;
	}

	return this->defense + defenseBonus + 8;
}

int Staker::getHitpoints(){
	return this->lifepoints;
}

void Staker::damage(unsigned int damage){
	this->lifepoints	-=	damage;
}

bool Staker::isAlive(){
	return this->lifepoints > 0;
}

double Staker::getCombatLevel(){
	return (1.3*(this->attack + this->strength) + this->defense + this->hitpoints)/4;
}

void Staker::reset(){
	this->lifepoints	=	this->hitpoints*10;
}

void Staker::win(){
	this->winCount++;
}

unsigned int Staker::getWinCount(){
	return this->winCount;
}
