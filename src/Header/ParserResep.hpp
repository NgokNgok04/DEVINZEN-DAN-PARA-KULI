#ifndef PARSERRESEP_HPP
#define PARSERRESEP_HPP
#include <bits/stdc++.h>
#include "BaseParser.hpp"
using namespace std;
//Parser khusus untuk membaca file konfigurasi resep.
class ParserResep : public BaseParser{
    private:
        static vector<int> recipeID;
        static vector<string> recipeCode;
        static vector<string> recipeName;
        static vector<int> recipePrice;
        static vector<vector<pair<string,int> > > recipeMaterialQuantity;
        static map<int,int> IndexToIDMap;
        static map<int,int> IDToIndexMap;
    public:
        ParserResep(){}
        ~ParserResep(){}
        void ParseFile(string fileDirectory);
        void ClearParserData();
        static int getID(int);
        static string getCode(int);
        static string getName(int);
        static int getPrice(int);
        static vector<pair<string,int> > getRecipeMaterialQuantity(int);
        static int getConfigSize();
        static int convertCodeToID(string Code);
        static int convertNameToID(string Name);
        static int indexToID(int);
        static int IDToIndex(int);
        friend ostream &operator<<(ostream &os, ParserResep &PR); //untuk debugging, pake aja
};
#endif