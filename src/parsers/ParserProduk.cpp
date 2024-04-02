#include "ParserProduk.hpp"
#include "../exceptions/Exceptions.hpp"
#include <bits/stdc++.h>
void ParserProduk::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); //buka file

    if(!InputFile.is_open()){ //jika gagal dibuka lempar exception
        throw ProductConfigMissingException();
        return;
    }
    cout<<"file product kebaca\n";
}

void ParserProduk::ClearParserData()
{
    this->productID.clear();
    this->productCode.clear();
    this->productName.clear();
    this->productTypes.clear();
    this->productOrigin.clear();
    this->addedWeight.clear();
    this->productPrice.clear();
}
