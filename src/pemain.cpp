#include <iostream>
#include <vector>
#include <string>
#include "pemain.hpp"
using namespace std;

Pemain::Pemain()
{
    this->gulden = 50;
    this->berat_badan = 40;
    MatrixArea<GameObject> inv(8, 8);
    this->inventory = inv;
    this->ownedBuild = {0, 0, 0};
}

Pemain::Pemain(int guld, int bb, int smol, int med, int big)
{
    this->gulden = guld;
    this->berat_badan = bb;
    MatrixArea<GameObject> inv(8, 8);
    this->inventory = inv;
    this->ownedBuild = {smol, med, big};
}

Pemain::Pemain(const Pemain &other) // not sure
{
    this->gulden = other.gulden;
    this->berat_badan = other.berat_badan;
    MatrixArea<GameObject> n(other.inventory);
    this->inventory = n;
    this->ownedBuild = other.ownedBuild;
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
    pair<int, int> pos = this->inventory.getPositionFromSlot(slot);
    // this->berat_badan += this->inventory.getElement(pos.first,pos.second).getAddedWeight();
    this->inventory.deleteElement(pos.first, pos.second);
    cout << endl
         << endl;
    cout << "Dengan lahapnya, kamu memakan hidangan itu" << endl;
    cout << "Alhasil, berat badan kamu naik menjadi ";
}

void Pemain::setInv(int rows, int cols, GameObject a){
    this->inventory.setElement(rows, cols, &a);
}