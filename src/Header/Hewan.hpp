#ifndef HEWAN_HPP
#define HEWAN_HPP

#include "GameObject.hpp"
#include "Product.hpp"
#include "../parsers/ParserHewan.hpp"
#include <vector>

class Hewan: public GameObject{
    private:
        string type;
        int weightHarvest;
        int weight;
    public:
        Hewan();
        Hewan(int);
        void makan(Product);
        vector<Product*> hasilPanen();
        bool isHarvestable();
        string getType();
        int getWeightHarvest();
        int getCurWeight();
};

#endif