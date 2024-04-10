#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include <iostream>
#include <vector>
#include <string>
#include "matrixarea.hpp"
#include "GameObject.hpp"
using namespace std;

class Pemain
{
protected:
    MatrixArea<GameObject> inventory;
    int gulden;
    int berat_badan;
    string tipe; // walikota, peternak, petani, pemain

public:
    Pemain();
    Pemain(int rows, int cols, int guld, int bb); // : MatrixArea(rows, cols)
    Pemain(const Pemain &);
    ~Pemain();

    string getTipe();

    // specifics
    void cetakPenyimpanan();
    void makan(int row, int col);              // loc item yg dimakan
    virtual void beli(int, int, int, int) = 0; // letak and quant item, loc item akan disimpan
    virtual void jual(int, int) = 0;           // loc item yg akan dijual
    virtual void calculateTax() = 0;
};

#endif