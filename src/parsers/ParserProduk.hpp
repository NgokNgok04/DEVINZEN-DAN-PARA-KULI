#include <bits/stdc++.h>
#include "BaseParser.hpp"
using namespace std;
//Parser khusus untuk membaca file konfigurasi produk.
class ParserProduk : public BaseParser{
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
        ParserProduk(){
            validProductTypes = {"PRODUCT_MATERIAL_PLANT", "PRODUCT_FRUIT_PLANT", "PRODUCT_ANIMAL"};
        }
        ~ParserProduk(){}
        void ParseFile(string fileDirectory);
        void ClearParserData();
        friend ostream &operator<<(ostream &os, ParserProduk &PP); //untuk debugging, pake aja
};