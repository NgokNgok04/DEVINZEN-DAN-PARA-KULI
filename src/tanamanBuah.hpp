#ifndef TANAMANBUAH_HPP
#define TANAMANBUAH_HPP

#include "tanaman.hpp"

class TanamanBuah : public Tanaman {
    public:
        void panen();
        bool isHarvestable();
}

#endif