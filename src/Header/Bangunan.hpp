#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include "GameObject.hpp"
#include "./Parser/ParserResep.hpp"

class Bangunan:public GameObject{
    public:
        Bangunan(int);
        Bangunan& operator=(const Bangunan&);
        bool operator==(const Bangunan&);
};

#endif