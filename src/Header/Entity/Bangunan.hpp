#ifndef BANGUNAN_HPP
#define BANGUNAN_HPP

#include "GameObject.hpp"

class Bangunan : public GameObject
{
private:
    string pemilik;
    static int totalBangunan;

public:
    Bangunan(int, string, float, string, string);
};

#endif