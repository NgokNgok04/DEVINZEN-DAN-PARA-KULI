#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include <iostream>
#include <vector>
#include "matrixarea.cpp"
// #include "./Header/GameObject.hpp"
#include "./Implementation/GameObject.cpp"
#include "Toko.hpp"
using namespace std;

class Pemain
{
protected:
    MatrixArea<GameObject> inventory;
    int gulden;
    int berat_badan;
    string tipe; // walikota, peternak, petani, pemain
    vector<int> ownedBuild;

public:
    Pemain();
    Pemain(int guld, int bb, int smol, int med, int big); // : MatrixArea(rows, cols)
    Pemain(const Pemain &);
    ~Pemain();

    string getTipe();

    // specifics
    void cetakPenyimpanan();
    // void beli(); // loc item yang dibeli, loc item akan disimpan
    // void jual();           // loc item yg akan dijual
    void makan();            // loc item yg dimakan
    virtual void beli() = 0; // letak and quant item, loc item akan disimpan
    virtual void jual() = 0; // loc item yg akan dijual
    virtual int calculateTax() = 0;
};

#endif