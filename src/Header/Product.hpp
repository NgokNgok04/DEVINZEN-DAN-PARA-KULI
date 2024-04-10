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
        static ParserProduk konfig;
    public:
        Product();
        Product(int);
        bool fromHewan();
        int getAddedWeight();
        ParserProduk getKonfig();
};

#endif