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

void Petani::beli(int buyr, int buyc, int saver, int savec)
{
    // Need toko
}

void Petani::jual(int sellr, int ellc)
{
    //
}

void Petani::cetakLadang()
{
    this->ladang.displayObject();
    this->ladang.displayRemainderSlot();
}

void Petani::tanam(int invr, int invc, int ladr, int ladc)
{
}

void Petani::panenTani()
{
}

int Petani::calculateTax()
{
    return 0;
}