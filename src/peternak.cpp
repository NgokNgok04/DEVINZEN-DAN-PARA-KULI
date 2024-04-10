#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "peternak.hpp"
using namespace std;

Peternak::Peternak() : Pemain(), ternakan(10,10)
{
    // this->ternakan->MatrixArea(10, 10);
}

Peternak::Peternak(int rows, int cols, int guld, int bb, int terrows, int colrows) : Pemain(rows, cols, guld, bb), ternakan(10,10)
{
    // this->ternakan->MatrixArea(terrows, colrows);
}

Peternak::Peternak(const Peternak &other) : Pemain()
{
    this->ternakan = other.ternakan;
}

Peternak::~Peternak()
{
    this->inventory.~MatrixArea();
    this->ternakan.~MatrixArea();
}