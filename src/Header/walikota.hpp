#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "pemain.hpp"

class WaliKota : public Pemain
{
public:
    WaliKota();
    WaliKota(string usn, int guld, int bb, int smol, int med, int big);
    WaliKota(const WaliKota &);
    ~WaliKota();
    void pungutPajak();
    void bangunBangunan(int); // int tipe 1: small, 2 medium, 3 large, 4 hotel
    void beli();
    void jual();
    int calculateKKP();
    int calculateTax();
};

#endif