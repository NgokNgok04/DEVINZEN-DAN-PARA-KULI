#ifndef PARSERPRODUK_HPP
#define PARSERPRODUK_HPP
#include <bits/stdc++.h>
#include "BaseParser.hpp"
using namespace std;
//Parser khusus untuk membaca file konfigurasi produk.
class ParserProduk : public BaseParser{
    private:
        static vector<int> productID;
        static vector<string> productCode;
        static vector<string> productName;
        static vector<string> productType;
        static vector<string> productOrigin;
        static vector<int> addedWeight;
        static vector<int> price;
        static vector<string> validProductTypes;
    public:
        ParserProduk(){
            validProductTypes = {"PRODUCT_MATERIAL_PLANT", "PRODUCT_FRUIT_PLANT", "PRODUCT_ANIMAL"};
        }
        ~ParserProduk(){}
        void ParseFile(string fileDirectory);
        void ClearParserData();
        static int getID(int);
        static string getCode(int);
        static string getName(int);
        static string getType(int);
        static string getOrigin(int);
        static int getAddedWeight(int);
        static int getPrice(int);
        static int getConfigSize();
        int convertCodeToID(string Code);
        int convertNameToID(string Name);
        bool isAnAnimalProduct(int);
        friend ostream &operator<<(ostream &os, ParserProduk &PP); //untuk debugging, pake aja
};
#endif