#ifndef MAKHLUK_HIDUP_HPP
#define MAKHLUK_HIDUP_HPP

#include "GameObject.hpp"
#include "Product.hpp"
#include "../Header/Parser/ParserTanaman.hpp"

class Tanaman : public GameObject
{
private:
    string type;
    int durationHarvest;
    int age;

public:
    Tanaman(int);
    void tambahUmur();
    Product *hasilPanen();
    bool isHarvestable();
    string getType();
    int getDurationHarvest();
    int getCurAge();
    Tanaman &operator=(const Tanaman &);
    bool operator==(const Tanaman &);
};

#endif