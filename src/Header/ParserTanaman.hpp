#ifndef PARSERTANAMAN_HPP
#define PARSERTANAMAN_HPP
#include <bits/stdc++.h>
#include "BaseParser.hpp"
using namespace std;
//Parser khusus untuk membaca file konfigurasi tanaman.
class ParserTanaman : public BaseParser {
    private:
        static vector<int> plantID;
        static vector<string> plantCode;
        static vector<string> plantName;
        static vector<string> plantType;
        static vector<int> harvestDuration;
        static vector<int> price;
        static vector<string> validPlantTypes;
        static map<int,int> IndexToIDMap;
        static map<int,int> IDToIndexMap;
    public:
        ParserTanaman(){
            this->validPlantTypes = {"MATERIAL_PLANT","FRUIT_PLANT"};
        }
        ~ParserTanaman(){}
        void ParseFile(string fileDirectory);
        void ClearParserData();
        static int getID(int);
        static string getCode(int);
        static string getName(int);
        static string getType(int);
        static int getHarvestDuration(int);
        static int getPrice(int);
        static int getConfigSize();
        static int convertCodeToID(string Code);
        static int convertNameToID(string Name);
        static int indexToID(int);
        static int IDToIndex(int);
        friend ostream &operator<<(ostream &os, ParserTanaman &PT); //untuk debugging, pake aja
};
#endif