#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "pemain.hpp"

class WaliKota : public Pemain
{
private:
    map<string,int> daftarMaterial;
public:
    WaliKota();
    WaliKota(string usn, int guld, int bb, int smol, int med, int big);
    WaliKota(const WaliKota &);
    ~WaliKota();
    void pungutPajak();
    void beli();
    void jual();
    void bangunBangunan();
    float calculateTax();
};

#endif