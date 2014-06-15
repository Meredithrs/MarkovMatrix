#include <iostream>
#include "matrix.h"
#include "Markov.h"

using namespace std;

int main(){
	MarkovMatrix m(32.0, 32.0);
	m.set_probability(.6);
	m.populate();
	m.print();
    return 0;
}
