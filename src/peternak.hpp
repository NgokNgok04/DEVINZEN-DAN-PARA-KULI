#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "pemain.hpp"

class Peternak : public Pemain
{
protected:
    MatrixArea<GameObject> ternakan;

public:
    Peternak();
    Peternak(int rows, int cols, int guld, int bb, int terrows, int tercols);
    Peternak(const Peternak &);
    ~Peternak();
    void cetakTernak();
    void ternak(int, int, int, int);     // coords hewan yg ingin diternak, coords letak ternakan
    void kasihMakan(int, int, int, int); // coords letak hewan, coords letak makanan yg ingin diberikan
    void panenTernak();
    void beli(int, int, int, int);
    void jual(int, int);
};

#endif
