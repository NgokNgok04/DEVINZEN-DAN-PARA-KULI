#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "petani.hpp"
using namespace std;

template <class T>
Petani<T>::Petani() : Pemain<T>()
{
}

template <class T>
Petani<T>::Petani(int rows, int cols, int guld, int bb) : Pemain<T>(rows, cols, guld, bb)
{
}

template <class T>
Petani<T>::Petani(const Petani<T> &other) : Pemain<T>()
{
}

template <class T>
Petani<T>::~Petani()
{
    this->inventory.~MatrixArea();
}