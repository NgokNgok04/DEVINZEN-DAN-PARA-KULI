#ifndef HEWAN_HPP
#define HEWAN_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Hewan{
    private:
        string kode_huruf;
        string name;
    public:
        Hewan(){this->kode_huruf=""; this->name="";};
        Hewan(string kode_huruf, string name){
            this->kode_huruf = kode_huruf; 
            this->name = name;
        };
        ~Hewan(){};
        string getKodeHuruf(){return this->kode_huruf;};
        string getName(){return this->name;};

};

#endif