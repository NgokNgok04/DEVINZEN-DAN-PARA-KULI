#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GameObject{
    private:
        int id;
        string kode_huruf;
        float price;
        string name;
    public:
        GameObject(int,string,float,string);
        int getID();
        string getKode();
        float getPrice();
        string getName();
};

class Product:public GameObject{
    private:
        string type;
        bool isFromHewan;
        int addedWeight;
        string origin;
        static int totalProduct;
    public:
        Product(int, string, string, string, string, int, float);
        bool fromHewan();
        int getAddedWeight();
};

class MakhlukHidup: public GameObject{
    protected:
        string type;
    public:
        MakhlukHidup(int, string, float, string, string);
        virtual bool isHarvestable() = 0;
};

class Hewan: public MakhlukHidup{
    private:
        int weightHarvest;
        int weight;
        static int totalHewan;
    public:
        Hewan(int,string,float,string,string,int);
        void makan(Product);
        bool isHarvestable();
};

class Tanaman: public MakhlukHidup{
    private:
        int durationHarvest;
        int age;
        static int totalTanaman;
    public:
        Tanaman(int,string,float,string,string,int);
        bool isHarvestable();
};

class Bangunan:public GameObject{
    private:
        string pemilik;
        static int totalBangunan;
    public:
        Bangunan(int,string,float,string,string);
};

#endif