#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GameObject
{
private:
    int id;
    string kode_huruf;
    float price;
    string name;

public:
    GameObject(int);
    int getID();
    string getKode();
    float getPrice();
    string getName();
};

#endif