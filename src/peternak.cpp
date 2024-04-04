#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "peternak.hpp"
using namespace std;

template <class T>
Peternak<T>::Peternak() : Pemain<T>()
{
}

template <class T>
Peternak<T>::Peternak(int rows, int cols, int guld, int bb) : Pemain<T>(rows, cols, guld, bb)
{
}

template <class T>
Peternak<T>::Peternak(const Peternak<T> &other) : Pemain<T>()
{
}

template <class T>
Peternak<T>::~Peternak()
{
    this->inventory.~MatrixArea();
}