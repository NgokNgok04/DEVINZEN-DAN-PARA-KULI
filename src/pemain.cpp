#include <iostream>
#include <vector>
#include <string>
#include "pemain.hpp"
using namespace std;

Pemain::Pemain() : inventory(10, 10) // not sure
{
    this->gulden = 50;
    this->berat_badan = 40;
}

Pemain::Pemain(int rows, int cols, int guld, int bb) : inventory(rows, cols) // not sure
{
    this->gulden = guld;
    this->berat_badan = bb;
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

void Pemain::makan(int row, int col)
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