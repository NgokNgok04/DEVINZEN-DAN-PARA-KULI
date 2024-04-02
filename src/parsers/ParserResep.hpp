#include <bits/stdc++.h>
#include "BaseParser.hpp"
using namespace std;
//Parser khusus untuk membaca file konfigurasi resep.
class ParserResep : public BaseParser{
    private:
        vector<int> recipeID;
        vector<string> recipeCode;
        vector<string> recipeName;
        vector<int> recipePrice;
        map<string,int> recipeMaterials;
    public:
        ParserResep(){}
        ~ParserResep(){}
        void ParseFile(string fileDirectory);
        void ClearParserData();
};