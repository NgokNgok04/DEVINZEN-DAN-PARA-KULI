#ifndef HEWAN_HPP
#define HEWAN_HPP

#include "GameObject.hpp"
#include "Product.hpp"
#include "../Header/Parser/ParserHewan.hpp"

class Hewan: public GameObject{
    private:
        string type;
        int weightHarvest;
        int weight;
        static ParserHewan konfig;
    public:
        Hewan();
        Hewan(int);
        void makan(Product);
        Product* hasilPanen();
        bool isHarvestable();
};

#endif