#ifndef PETANI_HPP
#define PETANI_HPP

#include "pemain.hpp"
#include "../Header/Tanaman.hpp"
class Petani : public Pemain
{
protected:
    MatrixArea<Tanaman> ladang;

public:
    Petani();
    Petani(int rows, int cols, int guld, int bb, int ladrows, int ladcols);
    Petani(const Petani &);
    ~Petani();
    void cetakLadang();
    void tanam(int, int, int, int); // coords tanaman yg ingin ditanam, coords letak menanam dlm ladang
    void panenTani();
};

#endif
