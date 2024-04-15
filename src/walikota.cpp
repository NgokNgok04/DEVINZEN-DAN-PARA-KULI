#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "walikota.hpp"
using namespace std;

WaliKota::WaliKota() : Pemain()
{
    this->tipe = "walikota";
    this->username = "Walikota";
}

WaliKota::WaliKota(string usn, int guld, int bb, int smol, int med, int big) : Pemain(usn,guld, bb, smol, med, big)
{
    this->tipe = "walikota";
}

WaliKota::WaliKota(const WaliKota &other) : Pemain(other)
{
    this->tipe = "walikota";
}

WaliKota::~WaliKota()
{
    this->inventory.~MatrixArea();
}

void WaliKota::pungutPajak()
{
    // Butuh track semua player
}

void WaliKota::bangunBangunan(int)
{
    // Butuh config bangunan
}

void WaliKota::beli()
{
    //
}

void WaliKota::jual()
{
    //
}

int WaliKota::calculateTax(){//ini bikin dia jadi abstract
    return 0;
}