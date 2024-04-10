#ifndef MAKHLUK_HIDUP_HPP
#define MAKHLUK_HIDUP_HPP

#include "GameObject.hpp"
#include "Product.hpp"
#include "../Header/Parser/ParserTanaman.hpp"

class Tanaman: public GameObject{
    private:
        string type;
        int durationHarvest;
        int age;
        static ParserTanaman konfig;
    public:
        Tanaman(int);
        void tambahUmur();
        Product hasilPanen();
        bool isHarvestable();
};

#endif