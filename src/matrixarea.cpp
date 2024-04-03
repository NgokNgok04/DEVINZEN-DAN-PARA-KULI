#include <iostream>
#include <string>
#include <vector>
#include "matrixarea.hpp"
using namespace std;
template<class T>
MatrixArea<T>::MatrixArea(int rows, int cols){
    this->rows = rows;
    this->cols = cols;
    this->matrix.resize(this->rows, vector<T>(this->cols,T()));
}
template<class T>
MatrixArea<T>::~MatrixArea(){
    this->matrix.clear();
}
template<class T>
MatrixArea<T>::MatrixArea(const MatrixArea<T>& matrix){
    this->rows = matrix.rows;
    this->cols = matrix.cols;
    this->matrix = matrix.matrix;
}

template<class T>
MatrixArea<T>& MatrixArea<T>::operator=(const MatrixArea<T>& matrix){
    if (this != &matrix){
        this->rows = matrix.rows;
        this->cols = matrix.cols;
        this->matrix = matrix.matrix;
    }
    return *this;
}

template<class T>
void MatrixArea<T>::setElement(int row,int col,T object){
    // asumsi row n col selalu benar
    this->matrix[row - 1][col - 1] = object;
}

template<class T>
T MatrixArea<T>::getElement(int row,int col){
    // asumsi row n col selalu benar
    return this->matrix[row - 1][col - 1];
}

template<class T>
void MatrixArea<T>::displayMatrix(){
    cout << "    ";
    for (int i = 0; i < this->cols; i++){
        cout << "  "<<static_cast<char>(static_cast<int>('A') + i) << "   ";
    }
    cout << endl;
    string grid ="   +";
    for (int i = 0; i < this->cols; i++){
        grid += "-----+";
    }

    for(int i = 0; i < this->rows; i++){
        cout << grid << endl;
        cout << "0" << i + 1 << " ";
        cout << "|";
        for(int j = 0; j < this->cols; j++){
            string kode_huruf = this->matrix[i][j].getKodeHuruf();
            if (kode_huruf.length() == 3){
                cout << " " << kode_huruf << " ";
            } else {
                cout << "     ";
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << grid << endl;
}

template <class T>
void MatrixArea<T>::displayObject(){
    int title = (this->cols*6) + 4;
    cout << "   ";
    if ( title > 15){
        if ((title - 15) % 2  == 0){
            for (int i = 0; i < (title-15)/2; i++){cout << "=";};
            cout << "[ Penyimpanan ]";
            for (int i = 0; i < (title-15)/2; i++){cout << "=";};
        } else {
            for (int i = 0; i < (title-15)/2 - 1; i++){cout << "=";};
            cout << "[ Penyimpanan ]";
            for (int i = 0; i < (title-15)/2 - 1; i++){cout << "=";};
        }
        cout << endl;
    } else {
        cout << "[ Penyimpanan ]" << endl;
    }
    MatrixArea<Hewan>::displayMatrix();
}

template <>
void MatrixArea<Hewan>::displayObject(){
    int title = (this->cols*6) + 4;
    cout << "   ";
    if ( title > 14){
        if ((title - 14) % 2  == 0){
            for (int i = 0; i < (title-14)/2; i++){cout << "=";};
            cout << "[ Peternakan ]";
            for (int i = 0; i < (title-14)/2; i++){cout << "=";};
        } else {
            for (int i = 0; i < (title-14)/2 - 1; i++){cout << "=";};
            cout << "[ Peternakan ]";
            for (int i = 0; i < (title-14)/2 - 1; i++){cout << "=";};
        }
        cout << endl;
    } else {
        cout << "[ Peternakan ]" << endl;
    }
    MatrixArea<Hewan>::displayMatrix();
}

template <>
void MatrixArea<Tumbuhan>::displayObject(){
    int title = (this->cols*6) + 4;
    cout << "   ";
    if ( title > 10){
        if ((title - 10) % 2  == 0){
            for (int i = 0; i < (title-10)/2; i++){cout << "=";};
            cout << "[ Ladang ]";
            for (int i = 0; i < (title-10)/2; i++){cout << "=";};
        } else {
            for (int i = 0; i < (title-10)/2 - 1; i++){cout << "=";};
            cout << "[ Ladang ]";
            for (int i = 0; i < (title-10)/2 - 1; i++){cout << "=";};
        }
        cout << endl;
    } else {
        cout << "[ Ladang ]" << endl;
    }
    MatrixArea<Tumbuhan>::displayMatrix();
}