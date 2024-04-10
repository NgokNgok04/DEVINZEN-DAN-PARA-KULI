#ifndef TUMBUHAN_HPP
#define TUMBUHAN_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Tumbuhan
{
private:
    string kode_huruf;
    string name;

public:
    Tumbuhan()
    {
        this->kode_huruf = "";
        this->name = "";
    };
    Tumbuhan(string kode_huruf, string name)
    {
        this->kode_huruf = kode_huruf;
        this->name = name;
    };
    ~Tumbuhan(){};
    string getKodeHuruf() { return this->kode_huruf; };
    string getName() { return this->name; };
};

#endif