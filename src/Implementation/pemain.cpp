#include <iostream>
#include <vector>
#include <string>
#include "../Header/pemain.hpp"
using namespace std;

Pemain::Pemain()
{
    this->gulden = 50;
    this->berat_badan = 40;
    MatrixArea<GameObject> inv(8, 8);
    this->inventory = inv;
    this->ownedBuild = {0, 0, 0};
}

Pemain::Pemain(string usn, int guld, int bb, int smol, int med, int big)
{
    this->gulden = guld;
    this->berat_badan = bb;
    MatrixArea<GameObject> inv(8, 8);
    this->inventory = inv;
    this->ownedBuild = {smol, med, big};
    this->username = usn;
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

MatrixArea<GameObject> Pemain::getInventory()
{
    return this->inventory;
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

string Pemain::getUsername()
{
    return this->username;
}

bool Pemain::operator<(Pemain const &other)const
{
    string actualUsername1 = this->username;
    string actualUsername2 = other.username;
    string lowerUsername1 = actualUsername1;
    string lowerUsername2 = actualUsername2;
    for (auto& x : lowerUsername1) { 
        x = tolower(x); 
    } 
    for (auto& x : lowerUsername2) { 
        x = tolower(x); 
    }
    if(lowerUsername1 == lowerUsername2){
        return actualUsername1<actualUsername2;
    } else {
        return lowerUsername1<lowerUsername2;
    }
}

bool Pemain::operator==(Pemain const &other)const
{
    return this->username == other.username;
}

void Pemain::setInv(int rows, int cols, GameObject *a)
{
    this->inventory.setElement(rows, cols, a);
}