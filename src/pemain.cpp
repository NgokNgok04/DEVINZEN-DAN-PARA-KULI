#include <iostream>
#include <vector>
#include <string>
#include "pemain.hpp"
using namespace std;

Pemain::Pemain() : inventory(8, 8)
{
    this->gulden = 50;
    this->berat_badan = 40;
    // MatrixArea<GameObject> *inv = new MatrixArea<GameObject>(8, 8);
    // this->inventory = *inv;
}

Pemain::Pemain(int rows, int cols, int guld, int bb) : inventory(8, 8)
{
    this->gulden = guld;
    this->berat_badan = bb;
    // MatrixArea<GameObject> *inv = new MatrixArea<GameObject>(rows, cols);
    // this->inventory = *inv;
}

Pemain::Pemain(const Pemain &other) : inventory(other.inventory) // not sure
{
    this->gulden = other.gulden;
    this->berat_badan = other.berat_badan;
}

Pemain::~Pemain()
{
    this->inventory.~MatrixArea();
}

string Pemain::getTipe()
{
    return this->tipe;
}

void Pemain::cetakPenyimpanan()
{
    this->inventory.displayObject();
    this->inventory.displayRemainderSlot();
}

void Pemain::makan()
{
    cout << "Pilih makanan dari penyimpanan" << endl;
    this->inventory.displayObject();
    cout << endl;
    bool isValid = false;
    string slot;
    while (!isValid)
    {
        cout << "Slot: ";
        cin >> slot;
        cout << endl;
    }

    cout << endl
         << endl;
    cout << "Dengan lahapnya, kamu memakan hidangan itu" << endl;
    cout << "Alhasil, berat badan kamu naik menjadi ";
}