#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "petani.hpp"
using namespace std;

Petani::Petani() : Pemain(), ladang(10,10)
{
    // this->ladang->MatrixArea(10, 10);
}

Petani::Petani(int rows, int cols, int guld, int bb, int ladrows, int ladcols) : Pemain(rows, cols, guld, bb), ladang(10,10)
{
    // this->ladang->MatrixArea(ladrows, ladcols);
}

Petani::Petani(const Petani &other) : Pemain()
{
    this->ladang = other.ladang;
}

Petani::~Petani()
{
    this->inventory.~MatrixArea();
    this->ladang.~MatrixArea();
}