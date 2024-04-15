#ifndef PEMAIN_HPP
#define PEMAIN_HPP

#include <iostream>
#include <vector>
#include "../Implementation/matrixarea.cpp"
// #include "./Header/GameObject.hpp"
#include "GameObject.hpp"
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
    string username; //nama pemain

public:
    // MatrixArea<GameObject> inventory;

    Pemain();
    Pemain(string usn, int guld, int bb, int smol, int med, int big); // : MatrixArea(rows, cols)
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
    string getUsername();
    virtual int calculateTax() = 0;
    bool operator<(Pemain &other);
    bool operator==(Pemain &other);
};

#endif