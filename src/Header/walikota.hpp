#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

// #include "pemain.hpp"
#include "petani.hpp"
#include "peternak.hpp"
class WaliKota : public Pemain
{
private:
    map<string,int> daftarMaterial;
public:
    WaliKota();
    WaliKota(string usn, float guld, int bb);
    WaliKota(const WaliKota &);
    ~WaliKota();
    void pungutPajak(vector<Pemain *>);
    void beli();
    void jual();
    void bangunBangunan();
    float calculateTax();
    void tambahPemain(vector<Pemain *> &,int&,int&,Pemain* currentPlayer);

};

#endif