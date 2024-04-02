#include "ParserHewan.hpp"
#include "../exceptions/Exceptions.hpp"
#include <bits/stdc++.h>
void ParserHewan::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); //buka file

    if(!InputFile.is_open()){ //jika gagal dibuka lempar exception
        throw AnimalConfigMissingException();
        return;
    }
    cout<<"file animal kebaca\n";
}