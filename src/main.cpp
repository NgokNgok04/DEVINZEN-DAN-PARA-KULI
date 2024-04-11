#include <iostream>
#include <vector>
#include <string>
#include "matrixarea.hpp"
#include "matrixarea.cpp"
// #include "./Implementation/Hewan.cpp"
using namespace std;
int main()
{
    for(int i = 0; i < 5; i++){
        MatrixArea<Hewan>* testaja;
        cout << "Call" << i + 1;
    }
    // MatrixArea<Hewan> matrix(4, 2);
    // MatrixArea<Hewan> matrixcctor(matrix);
    // testaja = matrix;
    // cout << "test" << endl;
    // Hewan anjing(1);
    // Hewan kucing(2);
    // Hewan monyet(3);
    // matrix.setElement(1, 1, &anjing);
    // matrix.setElement(1, 2, &kucing);
    // matrix.setElement(2, 1, &monyet);
    // matrix.displayMatrix();
    // matrix.deleteElement(1,1);
    // Hewan coba = matrix.getElement(1,1);
    // matrix.setElement(1, 2, monyet);
    // matrix.setElement(3, 1, kucing);
    // matrix.setElement(3, 2, anjing);
    // matrix.displayMatrix();
    // matrix.displayDetail();
    return 0;
}