#include "matrix.h"
#include <iostream>

Matrix::Matrix(unsigned int width, unsigned int height){
	this->width  = width;
	this->height = height;
}

std::vector<double> Matrix::get_row(unsigned int row){
	return this->matrix[row];
}

std::vector<double> Matrix::get_column(unsigned int column){
	std::vector<double> temp;
	for(unsigned int i = 0; i < this->matrix.size(); i++){
			temp.push_back(this->matrix[i][column]);
	}
	return temp;
}

double Matrix::get_cell(unsigned int row, unsigned int column){
	return this->matrix[row][column];
}

void Matrix::set_row(unsigned int row, std::vector<double> new_row){
	this->matrix[row] = new_row;
}

void Matrix::set_column(unsigned int column, std::vector<double> new_column){
	for(unsigned int i = 0; i < this->matrix.size(); i++){
		this->matrix[i][column]	=	new_column[i];
	}
}

void Matrix::set_cell(unsigned int row, unsigned int column, double value){
	this->matrix[row][column] = value;
}

void Matrix::populate(){
	for(unsigned int i = 0; i < this->height; i++){
		std::vector<double> row;
		for(unsigned int j = 0; j < this->width; j++){
			row.push_back(0);
		}
		this->matrix.push_back(row);
	}
}

void Matrix::print(){
	for(unsigned int i = 0; i < this->height; i++){
		printf("[");
		for(unsigned int j = 0; j < this->width; j++){
			double temp = this->get_cell(i, j);
			printf("%f", temp);
			if(j < this->width - 1){
				printf(", ");
			}
		}
		printf("]\n");
	}
}
