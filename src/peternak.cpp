#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "peternak.hpp"
using namespace std;

template <class T>
Peternak<T>::Peternak() : Pemain<T>()
{
    this->ternakan->MatrixArea(10, 10);
}

template <class T>
Peternak<T>::Peternak(int rows, int cols, int guld, int bb, int terrows, int colrows) : Pemain<T>(rows, cols, guld, bb)
{
    this->ternakan->MatrixArea(terrows, colrows);
}

template <class T>
Peternak<T>::Peternak(const Peternak<T> &other) : Pemain<T>()
{
    this->ternakan = other.ternakan;
}

template <class T>
Peternak<T>::~Peternak()
{
    this->inventory.~MatrixArea();
    this->ternakan.~MatrixArea();
}