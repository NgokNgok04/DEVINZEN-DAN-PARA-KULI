#include <iostream>
#include <vector>
#include <string>
#include "inventory.hpp"

using namespace std;

Inventory::Inventory(int rows, int cols): MatrixArea(rows,cols){}

Inventory::~Inventory(){}

Inventory::Inventory(const Inventory& inventory): MatrixArea(inventory){}

Inventory& Inventory::operator=(const Inventory& inventory){
    if (this != &inventory){
        this->rows = inventory.rows;
        this->cols = inventory.cols;
        this->matrix = inventory.matrix;
    }

    return *this;
}

void Inventory::displayMatrix(){
    // 49 + 3= cols x 6 + 1 + 3
    // 15 [ Penyimpanan ]
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
    for (int i = 0; i < this->cols; i++){

    }
    MatrixArea::displayMatrix();
}