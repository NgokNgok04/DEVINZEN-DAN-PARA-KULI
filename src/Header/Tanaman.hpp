#ifndef MAKHLUK_HIDUP_HPP
#define MAKHLUK_HIDUP_HPP

#include "GameObject.hpp"
#include "Product.hpp"
#include "ParserTanaman.hpp"
#include <map>
class Tanaman : public GameObject
{
private:
    string type;
    int durationHarvest;
    int age;
    static map<string, string> konversiPanen;

    public:
        Tanaman(int);
        void tambahUmur();
        Product* hasilPanen();
        bool isHarvestable();
        string getType();
        int getDurationHarvest();
        int getCurAge();
        void setAge(int);
        Tanaman& operator=(const Tanaman&);
        bool operator==(const Tanaman&);
};

#endif