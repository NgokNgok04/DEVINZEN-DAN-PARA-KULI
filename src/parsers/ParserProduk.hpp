#include <bits/stdc++.h>
#include "BaseParser.hpp"
using namespace std;
//Parser khusus untuk membaca file konfigurasi produk.
class ParserProduk public BaseParser{
    private:
        vector<int> productID;
        vector<string> productCode;
        vector<string> productName;
        vector<string> productTypes;
        vector<string> productOrigin;
        vector<int> addedWeight;
        vector<int> productPrice;
        vector<string> validProductCodes;
        vector<string> validProductNames;
        vector<string> validProductTypes;
        vector<string> validProductOrigins;
    public:
        ParserProduk();
        ~ParserProduk();
        virtual void ParseFile();
        
};