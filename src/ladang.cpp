#include <iostream>
#include <vector>
#include <string>
#include "ladang.hpp"
using namespace std;

Ladang::Ladang(int rows, int cols): MatrixArea(rows,cols){}

Ladang::~Ladang(){}

Ladang::Ladang(const Ladang& Ladang): MatrixArea(Ladang){}

Ladang& Ladang::operator=(const Ladang& Ladang){
    if (this != &Ladang){
        this->rows = Ladang.rows;
        this->cols = Ladang.cols;
        this->matrix = Ladang.matrix;
    }

    return *this;
}