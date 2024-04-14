#ifndef PETANI_HPP
#define PETANI_HPP

#include "pemain.hpp"

#define KTKP_PETANI 13

class Petani : public Pemain
{
protected:
    MatrixArea<Tanaman> ladang;

public:
    Petani();
    Petani(int guld, int bb, int smol, int med, int big, int ladrows, int ladcols);
    Petani(const Petani &);
    ~Petani();
    MatrixArea<Tanaman> getLadang();
    void cetakLadang();
    void tanam(); // coords tanaman yg ingin ditanam, coords letak menanam dlm ladang
    void panenTani();
    void beli();
    void jual();
    int countKekayaanLadang();
    float calculateTax();
};

#endif