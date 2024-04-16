#ifndef PARSERHEWAN_HPP
#define PARSERHEWAN_HPP
#include <bits/stdc++.h>
#include "BaseParser.hpp"

#include "helper.hpp"
using namespace std;
// Parser khusus untuk membaca file konfigurasi hewan.
class ParserHewan : public BaseParser
{
private:
    static vector<int> animalID;
    static vector<string> animalCode;
    static vector<string> animalName;
    static vector<string> animalType;
    static vector<int> harvestWeight;
    static vector<int> price;
    static vector<string> validAnimalTypes;
    static map<int, int> IndexToIDMap;
    static map<int, int> IDToIndexMap;

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
    static int convertCodeToID(string Code);
    static int convertNameToID(string Name);
    static int indexToID(int);
    static int IDToIndex(int);
    friend ostream &operator<<(ostream &os, ParserHewan &PH); // untuk debugging, pake aja
};
#endif