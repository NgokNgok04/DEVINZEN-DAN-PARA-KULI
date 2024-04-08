#ifndef PETANI_HPP
#define PETANI_HPP

#include "pemain.hpp"

template <class T>
class Petani : public Pemain<T>
{
protected:
    MatrixArea<T> ladang;

public:
    Petani();
    Petani(int rows, int cols, int guld, int bb, int ladrows, int ladcols);
    Petani(const Petani<T> &);
    ~Petani();
    cetakLadang();
    tanam(int, int, int, int); // coords tanaman yg ingin ditanam, coords letak menanam dlm ladang
    panenTani();
};

#endif
