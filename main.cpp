#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"
#include "Markov.h"
#include "staker.h"

using namespace std;

int main(){
	/*
	MarkovMatrix m(32.0, 32.0);
	m.set_probability(.6);
	m.populate();
	m.print();
	*/
	try{
		Staker staker1;
		staker1.setAttack(99);
		staker1.setDefense(99);
		staker1.setStrength(99);
		staker1.setHitpoints(99);
		staker1.setAttackStyle("aggressive");

		Staker staker2;
		staker2.setAttack(99);
		staker2.setDefense(99);
		staker2.setStrength(99);
		staker2.setHitpoints(99);
		staker2.setAttackStyle("aggressive");

		for(unsigned int i = 0; i < 1000000; i++){
			printf("Calculating: %i\n", i);
			while(staker1.isAlive() && staker2.isAlive()){
				if(rand() % (int) staker1.getMaxAttackRoll() > rand() % (int) staker2.getMaxDefenseRoll()){
					staker2.damage(rand() % (int) staker1.getMaxStrengthRoll());
				}

				if(staker2.isAlive() && rand() % (int) staker2.getMaxAttackRoll() > rand() % (int) staker1.getMaxDefenseRoll()){
					staker1.damage(rand() % (int) staker2.getMaxStrengthRoll());
				}
			}
			if(staker1.isAlive()){
				staker1.win();
			}
			if(staker2.isAlive()){
				staker2.win();
			}

			staker1.reset();
			staker2.reset();
		}

		printf("Staker1: %i\n", staker1.getWinCount());
		printf("Staker2: %i\n", staker2.getWinCount());
	}catch(const char* e){
		std::cout << e << std::endl;
	}
    return 0;
}
