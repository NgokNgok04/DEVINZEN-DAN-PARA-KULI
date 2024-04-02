#include "ParserTanaman.hpp"
#include <bits/stdc++.h>
#include "../exceptions/Exceptions.hpp"
void ParserTanaman::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); //buka file

    if(!InputFile.is_open()){ //jika gagal dibuka lempar exception
        throw PlantConfigMissingException();
        return;
    }
    cout<<"file plant kebaca\n";
}