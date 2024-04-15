#ifndef HEWAN_HPP
#define HEWAN_HPP

#include "GameObject.hpp"
#include "Product.hpp"
#include "ParserHewan.hpp"
#include <vector>
#include <map>
#include <tuple>
using namespace std;

class Hewan : public GameObject
{
private:
    string type;
    int weightHarvest;
    int weight;
    static map<string, pair<string, string>> konversiPanen;

public:
    Hewan()
    {
        this->setKode("MET");
        this->setTipeObject("HEWAN");
        this->setName("DUCK");
        this->type = "CARNIVORE";
        this->weightHarvest = 10;
        this->weight = 100;
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