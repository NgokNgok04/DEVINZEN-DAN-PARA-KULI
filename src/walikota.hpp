#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "pemain.hpp"

template <class T>
class WaliKota : public Pemain<T>
{
public:
    WaliKota();
    WaliKota(int rows, int cols, int guld, int bb);
    WaliKota(const WaliKota<T> &);
    ~WaliKota();
    pungutPajak();
    bangunBangunan(int); // int tipe 1: small, 2 medium, 3 large, 4 hotel
};

#endif