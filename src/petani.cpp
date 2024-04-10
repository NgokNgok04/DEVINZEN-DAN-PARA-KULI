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
}

Petani::Petani(const Petani &other) : Pemain(), ladang(other.ladang)
{
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
    // if invr, invcol is hewan
    // if terr, terc kosong
    // put in
    // else
    // cancel
    // else
    // cancel
}

void Petani::panenTani()
{
}