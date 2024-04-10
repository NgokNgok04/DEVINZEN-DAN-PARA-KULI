#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "walikota.hpp"
using namespace std;

WaliKota::WaliKota() : Pemain()
{
}

WaliKota::WaliKota(int cols, int rows, int guld, int bb) : Pemain(cols, rows, guld, bb)
{
}

WaliKota::WaliKota(const WaliKota &other) : Pemain()
{
    this->gulden = other.gulden;
    this->berat_badan = other.berat_badan;
    this->inventory = other.inventory;
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

void WaliKota::beli(int buyr, int buyc, int saver, int savec)
{
}

void WaliKota::jual(int sellr, int ellc)
{
}