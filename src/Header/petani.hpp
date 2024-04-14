#ifndef PETANI_HPP
#define PETANI_HPP

#include "pemain.hpp"

class Petani : public Pemain
{
protected:
    MatrixArea<Tanaman> ladang;

public:
    Petani();
    Petani(int guld, int bb, int smol, int med, int big, int ladrows, int ladcols);
    Petani(const Petani &);
    ~Petani();
    void cetakLadang();
    void tanam(); // coords tanaman yg ingin ditanam, coords letak menanam dlm ladang
    void panenTani();
    void beli();
    void jual();
    int calculateKKP();
    int calculateTax();
};

#endif