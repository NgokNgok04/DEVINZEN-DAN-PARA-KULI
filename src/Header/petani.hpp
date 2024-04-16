#ifndef PETANI_HPP
#define PETANI_HPP

#include "pemain.hpp"
#define KTKP_PETANI 13

class Petani : public Pemain
{
protected:
    MatrixArea<Tanaman> ladang;
    vector<Tanaman*> daftarTanaman;
public:
    Petani();
    Petani(string usn, float guld, int bb);
    Petani(const Petani &);
    ~Petani();
    MatrixArea<Tanaman> &getLadang();
    vector<Tanaman*> &getDaftarTanaman();
    void cetakLadang();
    void tanam(); // coords tanaman yg ingin ditanam, coords letak menanam dlm ladang
    void panenTani();
    void beli();
    void jual();
    float calculateTax();
    int countKekayaanLadang();
    void tambahUmurTanaman();
};

#endif