#ifndef PETERNAK_HPP
#define PETERNAK_HPP

#include "pemain.hpp"

template <class T>
class Peternak : public Pemain<T>
{
public:
    Peternak();
    Peternak(int cols, int rows);
    Peternak(const Peternak &);
    ~Peternak();
    cetakTernak();
    ternak(int, int, int, int);     // coords hewan yg ingin diternak, coords letak ternakan
    kasihMakan(int, int, int, int); // coords letak hewan, coords letak makanan yg ingin diberikan
    panenTernak();
};

#endif