#ifndef HEWAN_HPP
#define HEWAN_HPP

#include "GameObject.hpp"
#include "Product.hpp"
#include "../Header/Parser/ParserHewan.hpp"
#include <vector>

class Hewan: public GameObject{
    private:
        string type;
        int weightHarvest;
        int weight;
    public:
        Hewan(int);
        void makan(Product);
        vector<Product*> hasilPanen();
        bool isHarvestable();
        string getType();
        int getWeightHarvest();
        int getCurWeight();
};

#endif