#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "peternak.hpp"
using namespace std;

Peternak::Peternak() : Pemain(), ternakan(10, 10)
{
    this->tipe = "peternak";
    // MatrixArea<GameObject> *inv = new MatrixArea<GameObject>(10, 10);
    // this->ternakan = *inv;
}

Peternak::Peternak(int rows, int cols, int guld, int bb, int terrows, int tercols) : Pemain(rows, cols, guld, bb), ternakan(terrows, tercols)
{
    this->tipe = "peternak";
}

Peternak::Peternak(const Peternak &other) : Pemain(), ternakan(other.ternakan)
{
    this->tipe = "peternak";
}

Peternak::~Peternak()
{
    this->inventory.~MatrixArea();
    this->ternakan.~MatrixArea();
}

void Peternak::beli()
{
    // Need toko
}

void Peternak::jual()
{
    //
}

void Peternak::cetakTernak()
{
    this->ternakan.displayObject();
    this->ternakan.displayRemainderSlot();
}

void Peternak::ternak()
{
}

void Peternak::kasihMakan()
{
    // if
}

void Peternak::panenTernak()
{
}

int Peternak::calculateKKP()
{
}