#include <iostream>
#include <vector>
#include <string>
#include "pemain.hpp"
using namespace std;

template <class T>
Pemain<T>::Pemain() : inventory(10, 10)
{
    this->gulden = 50;
    this->berat_badan = 0;
    // MatrixArea<T> inv;
    // inv.MatrixArea(10, 10);
    // this->inventory = inv;
}

template <class T>
Pemain<T>::Pemain(int rows, int cols, int guld, int bb) : inventory(rows, cols)
{
    this->gulden = guld;
    this->bb = berat_badan;
    // MatrixArea<T> inv;
    // inv.MatrixArea(rows, cols);
    // this->inventory = inv;
}

template <class T>
Pemain<T>::Pemain(const Pemain<T> &other)
{
    this->gulden = other.gulden;
    this->berat_badan = other.berat_badan;
    this->inventory = other.inventory;
}

template <class T>
Pemain<T>::~Pemain()
{
    this->inventory.~MatrixArea();
}

template <class T>
Pemain<T>::cetakPenyimpanan(){
    this->inventory.displayObject();
    this->inventory.displayRemainderSlot();
}

template <class T>
Pemain<T>::makan(int row, int col){
    cout << "Pilih makanan dari penyimpanan" << endl;
    this->inventory.displayObject();
    cout << endl;
    bool isValid = false;
    char[3] slot;
    while(!isValid){
        cout << "Slot: ";
        cin >> slot;
    }
    
    cout << endl << endl;
    cout << "Dengan lahapnya, kamu memakan hidangan itu" << endl;
    cout << "Alhasil, berat badan kamu naik menjadi ";
}