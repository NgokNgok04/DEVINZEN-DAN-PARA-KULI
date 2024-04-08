#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "petani.hpp"
using namespace std;

template <class T>
Petani<T>::Petani() : Pemain<T>()
{
    this->ladang->MatrixArea(10, 10);
}

template <class T>
Petani<T>::Petani(int rows, int cols, int guld, int bb, int ladrows, int ladcols) : Pemain<T>(rows, cols, guld, bb)
{
    this->ladang->MatrixArea(ladrows, ladcols);
}

template <class T>
Petani<T>::Petani(const Petani<T> &other) : Pemain<T>()
{
    this->ladang = other.ladang;
}

template <class T>
Petani<T>::~Petani()
{
    this->inventory.~MatrixArea();
    this->ladang.~MatrixArea();
}