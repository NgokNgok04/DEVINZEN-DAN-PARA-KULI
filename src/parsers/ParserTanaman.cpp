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

void ParserTanaman::ClearParserData()
{
        this->plantID.clear();
        this->plantCode.clear();
        this->plantName.clear();
        this->plantType.clear();
        this->harvestDuration.clear();
        this->price.clear();
}
