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