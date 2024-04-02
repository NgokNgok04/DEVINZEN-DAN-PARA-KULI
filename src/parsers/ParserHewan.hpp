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
        ParserHewan(){}
        ~ParserHewan(){}
        void ParseFile(string fileDirectory);

        friend ostream &operator<<(ostream &os, ParserHewan &PH); //untuk debugging, pake aja
};