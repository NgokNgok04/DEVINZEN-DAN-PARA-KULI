#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include "GameObject.hpp"
#include "ParserResep.hpp"

class Bangunan : public GameObject
{
public:
    Bangunan()
    {
        this->setKode("BGN");
        this->setTipeObject("BANGUNAN");
        this->setName("SMALL_HOUSE");
        this->setPrice(10000000);
    }
    Bangunan(int);
    Bangunan &operator=(const Bangunan &);
    bool operator==(const Bangunan &);
};

#endif