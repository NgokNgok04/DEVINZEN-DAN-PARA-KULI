#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include <iostream>
#include <vector>
#include "matrixarea.cpp"
// #include "./Header/GameObject.hpp"
#include "./Implementation/GameObject.cpp"
// #include "Toko.hpp"
using namespace std;

class Pemain
{
protected:
    int gulden;
    int berat_badan;
    string tipe; // walikota, peternak, petani, pemain
    vector<int> ownedBuild;
    MatrixArea<GameObject> inventory;

public:
    // MatrixArea<GameObject> inventory;

    Pemain();
    Pemain(int guld, int bb, int smol, int med, int big); // : MatrixArea(rows, cols)
    Pemain(const Pemain &);
    ~Pemain();

    string getTipe();
    MatrixArea<GameObject> getInventory();

    // specifics
    void setInv(int, int, GameObject *);
    void cetakPenyimpanan();
    void makan(); // loc item yg dimakan
    // virtual void beli() = 0; // letak and quant item, loc item akan disimpan
    // virtual void jual() = 0; // loc item yg akan dijual
    int countKekayaanInven();
    float getTaxRate(int);
    virtual float calculateTax() = 0;
};

#endif