#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "pemain.hpp"
#include "hewan.hpp"
class Peternak : public Pemain
{
protected:
    MatrixArea<Hewan> ternakan;

public:
    Peternak();
    Peternak(int rows, int cols, int guld, int bb, int terrows, int tercols);
    Peternak(const Peternak &);
    ~Peternak();
    void cetakTernak();
    void ternak(int, int, int, int);     // coords hewan yg ingin diternak, coords letak ternakan
    void kasihMakan(int, int, int, int); // coords letak hewan, coords letak makanan yg ingin diberikan
    void panenTernak();
};

#endif
