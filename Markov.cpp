#include "Markov.h"
#include <iostream>

MarkovMatrix::MarkovMatrix(unsigned int width, unsigned int height):Matrix(width, height){
	this->width  = width;
	this->height = height;
	this->probability = 0;
}

void MarkovMatrix::populate(){
	for(unsigned int i = 0; i < this->height; i++){
		std::vector<double> row;
		for(unsigned int j = 0; j < this->width; j++){
			if(i == j){
				row.push_back(1 - this->probability);
			}else{
				row.push_back(0);
			}
		}
		this->matrix.push_back(row);
	}
}

void MarkovMatrix::set_probability(double probability){
	this->probability	=	probability;
}
