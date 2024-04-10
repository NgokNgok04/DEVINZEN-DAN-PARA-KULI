#ifndef PETANI_HPP
#define PETANI_HPP

#include "pemain.hpp"

class Petani : public Pemain
{
protected:
    MatrixArea<GameObject> ladang;

public:
    Petani();
    Petani(int rows, int cols, int guld, int bb, int ladrows, int ladcols);
    Petani(const Petani &);
    ~Petani();
    void cetakLadang();
    void tanam(); // coords tanaman yg ingin ditanam, coords letak menanam dlm ladang
    void panenTani();
    void beli();
    void jual();
    int calculateKKP();
};

#endif
