#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Exception.hpp"
using namespace std;

class GameObject
{
private:
    int id;
    string kode_huruf;
    float price;
    string name;
    string tipeObject;

public:
    int getID();
    string getKode();
    float getPrice();
    string getName();
    string getTipeObject();
    void setID(int);
    void setKode(string);
    void setPrice(float);
    void setName(string);
    void setTipeObject(string);
};

#endif