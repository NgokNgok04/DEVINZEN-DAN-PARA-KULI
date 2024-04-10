#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "petani.hpp"
using namespace std;

Petani::Petani() : Pemain(), ladang(10, 10)
{
    this->tipe = "petani";
}

Petani::Petani(int rows, int cols, int guld, int bb, int ladrows, int ladcols) : Pemain(rows, cols, guld, bb), ladang(ladrows, ladcols)
{
    this->tipe = "petani";
}

Petani::Petani(const Petani &other) : Pemain(), ladang(other.ladang)
{
    this->tipe = "petani";
}

Petani::~Petani()
{
    this->inventory.~MatrixArea();
    this->ladang.~MatrixArea();
}

void Petani::beli()
{
    // Need toko
}

void Petani::jual()
{
    //
}

void Petani::cetakLadang()
{
    this->ladang.displayObject();
    this->ladang.displayRemainderSlot();
}

void Petani::tanam()
{
}

void Petani::panenTani()
{
}

int Petani::calculateKKP()
{
}