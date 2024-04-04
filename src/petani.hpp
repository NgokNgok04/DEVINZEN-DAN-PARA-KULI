#ifndef PETANI_HPP
#define PETANI_HPP

#include "pemain.hpp"

template <class T>
class Petani : public Pemain<T>
{
public:
    Petani();
    Petani(int cols, int rows, int guld, int bb);
    Petani(const Petani<T> &);
    ~Petani();
    cetakLadang();
    tanam(int, int, int, int); // coords tanaman yg ingin ditanam, coords letak menanam dlm ladang
    panenTani();
};

#endif