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

void Pemain::setInv(int rows, int cols, GameObject *a)
{
    this->inventory.setElement(rows, cols, a);
}

int Pemain::countKekayaanInven(){
    int sum=0;
    for(int i=1;i<=inventory.getRows();i++){
        for(int j=1;j<=inventory.getCols();j++){
            GameObject* ptr = inventory.getElement(i,j);
            if(ptr!=nullptr){
                sum+=ptr->getPrice();
            }
        }
    }
    return sum;
}

float Pemain::getTaxRate(int KKP){
    if(KKP<=6){
        return 0.05;
    }else if(KKP<=25){
        return 0.15;
    }else if(KKP<=50){
        return 0.25;
    }else if(KKP<=500){
        return 0.3;
    }else{
        return 0.35;
    }
}