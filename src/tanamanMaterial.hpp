#ifndef TANAMANMATERIAL_HPP
#define TANAMANMATERIAL_HPP

#include "tanaman.hpp"

class TanamanMaterial : public Tanaman {
    public:
        void panen();
        bool isHarvestable();
}

#endif