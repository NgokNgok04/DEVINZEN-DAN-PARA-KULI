#include <iostream>
#include "matrixarea.hpp"
using namespace std;
MatrixArea::MatrixArea(int rows, int cols){
    this->rows = rows;
    this->cols = cols;
    this->matrix.resize(this->rows, vector<string>(this->cols,""));
}

MatrixArea::~MatrixArea(){
    this->matrix.clear();
}

MatrixArea::MatrixArea(const MatrixArea& matrix){
    this->rows = matrix.rows;
    this->cols = matrix.cols;
    this->matrix = matrix.matrix;
}

MatrixArea& MatrixArea::operator=(const MatrixArea& matrix){
    if (this != &matrix){
        this->rows = matrix.rows;
        this->cols = matrix.cols;
        this->matrix = matrix.matrix;
    }
    return *this;
}

void MatrixArea::setElement(int row,int col,string kode_huruf){
    // asumsi row n col selalu benar
    this->matrix[row - 1][col - 1] = kode_huruf;
}

string MatrixArea::getElement(int row,int col){
    // asumsi row n col selalu benar
    return this->matrix[row - 1][col - 1];
}

void MatrixArea::displayMatrix(){
    
    string grid ="+";
    for (int i = 0; i < this->cols;i++){
        grid += "-----+";
    }

    for(int i = 0; i < this->rows; i++){
        cout << grid << endl;
        cout << "|";
        for(int j = 0; j < this->cols; j++){
            if (this->matrix[i][j].length() == 3){
                cout << " " << this->matrix[i][j] << " ";
            } else {
                cout << "     ";
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << grid << endl;
}