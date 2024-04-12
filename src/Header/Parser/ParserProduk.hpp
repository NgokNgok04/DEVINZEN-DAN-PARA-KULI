#ifndef PARSERPRODUK_HPP
#define PARSERPRODUK_HPP
#include <bits/stdc++.h>
#include "BaseParser.hpp"
using namespace std;
// Parser khusus untuk membaca file konfigurasi produk.
class ParserProduk : public BaseParser
{
private:
    vector<int> productID;
    vector<string> productCode;
    vector<string> productName;
    vector<string> productType;
    vector<string> productOrigin;
    vector<int> addedWeight;
    vector<int> price;

    vector<string> validProductTypes;

public:
    ParserProduk()
    {
        validProductTypes = {"PRODUCT_MATERIAL_PLANT", "PRODUCT_FRUIT_PLANT", "PRODUCT_ANIMAL"};
    }
    ~ParserProduk() {}
    void ParseFile(string fileDirectory);
    void ClearParserData();
    int getID(int);
    string getCode(int);
    string getName(int);
    string getType(int);
    string getOrigin(int);
    int getAddedWeight(int);
    int getPrice(int);
    int getConfigSize();
    int convertCodeToID(string Code);
    int convertNameToID(string Name);
    int *findOrigin(string);
    friend ostream &operator<<(ostream &os, ParserProduk &PP); // untuk debugging, pake aja
};
#endif