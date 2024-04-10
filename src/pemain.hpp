#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include <iostream>
#include <vector>
#include "matrixarea.hpp"
#include "GameObject.hpp"
#include "Toko.hpp"
using namespace std;

class Pemain
{
protected:
    MatrixArea<GameObject> inventory;
    int gulden;
    int berat_badan;

public:
    Pemain();
    Pemain(int rows, int cols, int guld, int bb); // : MatrixArea(rows, cols)
    Pemain(const Pemain&);
    ~Pemain();

    // specifics
    void cetakPenyimpanan();
    void makan(int row, int col);          // loc item yg dimakan
    void beli(); // loc item yang dibeli, loc item akan disimpan
    void jual(int, int);           // loc item yg akan dijual
};

#endif