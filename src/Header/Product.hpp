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
    Product()
    {
        this->setKode("SNM");
        this->setTipeObject("PRODUCT");
        this->setName("SNAKE_MEAT");
        this->isFromHewan = true;
        this->addedWeight = 1000000;
    };
    Product(int, bool);
    bool fromHewan();
    int getAddedWeight();
    string getOrigin();
    string getType();
    Product &operator=(const Product &);
    bool operator==(const Product &);
};

#endif