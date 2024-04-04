#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "pemain.hpp"

template <class T>
class WaliKota : public Pemain<T>
{
public:
    Walikota();
    Walikota(int cols, int rows, int guld, int bb);
    Walikota(const WaliKota &);
    ~Walikota();
    pungutPajak();
    bangunBangunan(int); // int tipe 1: small, 2 medium, 3 large, 4 hotel
};

#endif