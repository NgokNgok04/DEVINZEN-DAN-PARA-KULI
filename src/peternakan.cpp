#include <iostream>
#include <vector>
#include <string>
#include "peternakan.hpp"
using namespace std;

Peternakan::Peternakan(int rows, int cols): MatrixArea(rows,cols){}

Peternakan::~Peternakan(){}

Peternakan::Peternakan(const Peternakan& Peternakan): MatrixArea(Peternakan){}

Peternakan& Peternakan::operator=(const Peternakan& Peternakan){
    if (this != &Peternakan){
        this->rows = Peternakan.rows;
        this->cols = Peternakan.cols;
        this->matrix = Peternakan.matrix;
    }

    return *this;
}