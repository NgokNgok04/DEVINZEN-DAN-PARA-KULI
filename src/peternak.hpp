#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "pemain.hpp"

template <class T>
class Peternak : public Pemain<T>
{
protected:
    MatrixArea<T> ternakan;
public:
    Peternak();
    Peternak(int rows, int cols, int guld, int bb);
    Peternak(const Peternak<T> &);
    ~Peternak();
    cetakTernak();
    ternak(int, int, int, int);     // coords hewan yg ingin diternak, coords letak ternakan
    kasihMakan(int, int, int, int); // coords letak hewan, coords letak makanan yg ingin diberikan
    panenTernak();
};

#endif
