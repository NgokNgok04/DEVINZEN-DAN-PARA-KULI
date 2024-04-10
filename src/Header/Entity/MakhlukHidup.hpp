#ifndef MAKHLUK_HIDUP_HPP
#define MAKHLUK_HIDUP_HPP

#include "GameObject.hpp"
#include "Product.hpp"

class MakhlukHidup : public GameObject
{
protected:
    string type;

public:
    MakhlukHidup(int, string, float, string, string);
    virtual bool isHarvestable() = 0;
};

class Hewan : public MakhlukHidup
{
private:
    int weightHarvest;
    int weight;
    static int totalHewan;

public:
    Hewan(int, string, float, string, string, int);
    void makan(Product);
    bool isHarvestable();
};

class Tanaman : public MakhlukHidup
{
private:
    int durationHarvest;
    int age;
    static int totalTanaman;

public:
    Tanaman(int, string, float, string, string, int);
    bool isHarvestable();
    void incrementAge();
};

#endif