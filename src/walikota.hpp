#ifndef WALIKOTA_HPP
#define WALIKOTA_HPP

#include "pemain.hpp"

class WaliKota : public Pemain
{
public:
    WaliKota();
    WaliKota(int rows, int cols, int guld, int bb);
    WaliKota(const WaliKota &);
    ~WaliKota();
    void pungutPajak();
    void bangunBangunan(int); // int tipe 1: small, 2 medium, 3 large, 4 hotel
};

#endif