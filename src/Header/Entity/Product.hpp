#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "GameObject.hpp"

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

#endif