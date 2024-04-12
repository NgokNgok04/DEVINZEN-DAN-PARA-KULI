#ifndef PARSERHEWAN_HPP
#define PARSERHEWAN_HPP
#include <bits/stdc++.h>
#include "BaseParser.hpp"
using namespace std;
// Parser khusus untuk membaca file konfigurasi hewan.
// extern ParserHewan PHGlobal;
class ParserHewan : public BaseParser
{
private:
    vector<int> animalID;
    vector<string> animalCode;
    vector<string> animalName;
    vector<string> animalType;
    vector<int> harvestWeight;
    vector<int> price;
    vector<string> validAnimalTypes;

public:
    ParserHewan()
    {
        this->validAnimalTypes = {"HERBIVORE", "CARNIVORE", "OMNIVORE"};
    }
    ~ParserHewan() {}
    void ParseFile(string fileDirectory);
    void ClearParserData();
    static int getID(int);
    static string getCode(int);
    static string getName(int);
    static string getType(int);
    static int getHarvestWeight(int);
    static int getPrice(int);
    static int getConfigSize();
    int convertCodeToID(string Code);
    int convertNameToID(string Name);
    friend ostream &operator<<(ostream &os, ParserHewan &PH); // untuk debugging, pake aja
};
#endif