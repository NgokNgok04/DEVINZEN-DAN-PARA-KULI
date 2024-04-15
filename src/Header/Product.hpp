#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "GameObject.hpp"
#include "ParserProduk.hpp"

class Product : public GameObject
{
private:
    string type;
    bool isFromHewan;
    int addedWeight;
    string origin;

public:
    Product(){};
    Product(int, bool);
    bool fromHewan();
    int getAddedWeight();
    string getOrigin();
    string getType();
    Product &operator=(const Product &);
    bool operator==(const Product &);
};

#endif