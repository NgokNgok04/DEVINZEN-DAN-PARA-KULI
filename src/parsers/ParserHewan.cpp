#include "ParserHewan.hpp"
#include <bits/stdc++.h>
void ParserHewan::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); //buka file

    if(!InputFile.is_open()){ //jika gagal dibuka lempar exception
        string HewanError;
        HewanError = "File animal.txt hilang di folder config!";
        throw HewanError;
        return;
    }
    cout<<"file kebaca\n";
}