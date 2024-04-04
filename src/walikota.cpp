#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "walikota.hpp"
using namespace std;

template <class T>
WaliKota<T>::WaliKota() : Pemain<T>()
{
}

template <class T>
WaliKota<T>::WaliKota(int cols, int rows, int guld, int bb) : Pemain<T>(cols, rows, guld, bb)
{
}

template <class T>
WaliKota<T>::WaliKota(const WaliKota<T> &other) : Pemain<T>()
{
    this->gulden = other.gulden;
    this->berat_badan = other.berat_badan;
    this->inventory = other.inventory;
}

template <class T>
WaliKota<T>::~WaliKota()
{
    this->inventory.~MatrixArea();
}