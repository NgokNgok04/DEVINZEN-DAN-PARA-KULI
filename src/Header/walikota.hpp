#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "pemain.hpp"

class WaliKota : public Pemain
{
private:
    map<string,int> daftarMaterial;
public:
    WaliKota();
    WaliKota(string usn, float guld, int bb, int smol, int med, int big);
    WaliKota(const WaliKota &);
    ~WaliKota();
    void pungutPajak(vector<Pemain *>);
    void beli();
    void jual();
    void bangunBangunan();
    float calculateTax();
};

#endif