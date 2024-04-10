#ifndef PARSERHEWAN_HPP
#define PARSERHEWAN_HPP
#include <bits/stdc++.h>
#include "BaseParser.hpp"
using namespace std;
//Parser khusus untuk membaca file konfigurasi hewan.
class ParserHewan : public BaseParser{
    private:
        vector<int> animalID;
        vector<string> animalCode;
        vector<string> animalName;
        vector<string> animalType;
        vector<int> harvestWeight;
        vector<int> price;
        vector<string> validAnimalTypes;
    public:
        ParserHewan(){
            this->validAnimalTypes = {"HERBIVORE","CARNIVORE","OMNIVORE"};
        }
        ~ParserHewan(){}
        void ParseFile(string fileDirectory);
        void ClearParserData();
        int getID(int);
        string getCode(int);
        string getName(int);
        string getType(int);
        int getHarvestWeight(int);
        int getPrice(int);
        int getConfigSize();
        int convertCodeToID(string Code);
        int convertNameToID(string Name);
        friend ostream &operator<<(ostream &os, ParserHewan &PH); //untuk debugging, pake aja
};
#endif