#include <iostream>
#include <vector>
#include <string>
#include "pemain.cpp"
#include "petani.cpp"
#include "peternak.cpp"
#include "walikota.cpp"
#include "./Implementation/Hewan.cpp"
using namespace std;
int main()
{
    // MatrixArea<Hewan> testaja;
    // MatrixArea<GameObject> matrix(4, 2);
    // MatrixArea<Hewan> matrixcctor(matrix);
    // testaja = matrix;
    // cout << "test" << endl;
    Hewan anjing(1);
    // Hewan kucing(2);
    // Hewan monyet(3);
    // matrix.setElement(1, 1, &anjing);
    // matrix.setElement(1, 2, &kucing);
    // matrix.setElement(2, 1, &monyet);
    // matrix.displayMatrix();
    // matrix.deleteElement(2, 1);
    // matrix.displayMatrix();

    Petani P1;
    P1.cetakLadang();
    // P1.cetakPenyimpanan();

    P1.ladang.setElement(5, 5, &anjing);

    P1.cetakLadang();
    // Petani P2(P1);
    // P2.cetakLadang();

    cout << P1.getTipe() << endl;
    // p1cetakLadang();
    return 0;
}