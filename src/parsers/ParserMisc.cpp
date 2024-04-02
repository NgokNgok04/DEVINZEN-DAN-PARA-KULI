#include "ParserMisc.hpp"
#include "../exceptions/Exceptions.hpp"
#include <bits/stdc++.h>
void ParserMisc::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); //buka file

    if(!InputFile.is_open()){ //jika gagal dibuka lempar exception
        throw MiscConfigMissingException();
        return;
    }
    cout<<"file misc kebaca\n";
}

void ParserMisc::ClearParserData()
{
    this->winningMoney = 0;
    this->winningWeight = 0;
    this->storageSize = {0,0};
    this->fieldSize = {0,0};
    this->farmSize = {0,0};
}
