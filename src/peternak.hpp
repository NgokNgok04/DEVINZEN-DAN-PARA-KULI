#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "pemain.hpp"

class Peternak : public Pemain
{
protected:
    MatrixArea<GameObject> ternakan;

public:
    Peternak();
    Peternak(int guld, int bb, int smol, int med, int big, int terrows, int tercols);
    Peternak(const Peternak &);
    ~Peternak();
    void cetakTernak();
    void ternak();     // coords hewan yg ingin diternak, coords letak ternakan
    void kasihMakan(); // coords letak hewan, coords letak makanan yg ingin diberikan
    void panenTernak();
    void beli();
    void jual();
    int calculateKKP();
    int calculateTax();
};

#endif
