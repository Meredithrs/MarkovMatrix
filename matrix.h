#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <vector>
#include <stdio.h>

class Matrix{
public:
	Matrix(unsigned int, unsigned int);

	std::vector<double> get_row(unsigned int);
	std::vector<double> get_column(unsigned int);
	double get_cell(unsigned int, unsigned int);

	void set_row(unsigned int, std::vector<double>);
	void set_column(unsigned int, std::vector<double>);
	void set_cell(unsigned int, unsigned int, double);

	void populate();
	void print();

protected:
	std::vector< std::vector<double> > matrix;
	unsigned int height;
	unsigned int width;
};

#endif // MATRIX_H_INCLUDED
