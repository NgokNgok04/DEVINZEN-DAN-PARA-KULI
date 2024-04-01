#include <bits/stdc++.h>
#include "BaseParser.hpp"
using namespace std;
//Parser khusus untuk membaca file konfigurasi tanaman.
class ParserTanaman : public BaseParser {
    private:
        vector<int> plantID;
        vector<string> plantCode;
        vector<string> plantName;
        vector<string> plantType;
        vector<int> harvestDuration;
        vector<int> price;
        vector<string> validPlantNames;
        vector<string> validPlantCodes;
        vector<string> validPlantTypes;
    public:
        ParserTanaman(){}
        ~ParserTanaman(){}
        void ParseFile(string fileDirectory);
    
};