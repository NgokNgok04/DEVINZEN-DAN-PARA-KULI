#ifndef HEWAN_HPP
#define HEWAN_HPP

#include "GameObject.hpp"
#include "Product.hpp"
#include "ParserHewan.hpp"
#include <vector>

class Hewan : public GameObject
{
private:
    string type;
    int weightHarvest;
    int weight;

public:
    Hewan()
    {
        this->setKode("MET");
    }
    Hewan(int);
    void makan(Product);
    void setWeight(int);
    vector<Product *> hasilPanen();
    bool isHarvestable();
    string getType();
    int getWeightHarvest();
    int getCurWeight();
    Hewan &operator=(const Hewan &);
    bool operator==(const Hewan &);
};

#endif