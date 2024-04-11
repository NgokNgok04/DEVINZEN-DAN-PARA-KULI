#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "GameObject.hpp"
#include "./Parser/ParserProduk.hpp"

class Product:public GameObject{
    private:
        string type;
        bool isFromHewan;
        int addedWeight;
        string origin;
    public:
        Product(int,bool);
        bool fromHewan();
        int getAddedWeight();
        string getOrigin();
        string getType();
};

#endif