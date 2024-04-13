#ifndef MAKHLUK_HIDUP_HPP
#define MAKHLUK_HIDUP_HPP

#include "GameObject.hpp"
#include "Product.hpp"
#include "ParserTanaman.hpp"

class Tanaman : public GameObject
{
private:
    string type;
    int durationHarvest;
    int age;

public:
    Tanaman()
    {
        this->setKode("KIL");
        this->setTipeObject("TANAMAN");
        this->setName("METIU");
        this->durationHarvest = 10;
        this->age = 100;
    }
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