#ifndef MARKOV_H_INCLUDED
#define MARKOV_H_INCLUDED

#include "matrix.h"
#include <vector>
#include <stdio.h>

class MarkovMatrix: public Matrix{
public:
	MarkovMatrix(unsigned int, unsigned int);
	void populate();
	void set_probability(double);
private:
	double probability;
};

#endif // MARKOV_H_INCLUDED
