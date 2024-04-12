#include "../Header/ParserMisc.hpp"
#include "../Header/Exception.hpp"
#include "../Header/helper.hpp"
#include <bits/stdc++.h>
void ParserMisc::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); //buka file

    if(!InputFile.is_open()){ //jika gagal dibuka lempar exception
        throw MiscConfigMissingException();
        return;
    }

    vector<string> SpaceStrippedLine;
    string LineFile;
    int numValue,curLine;
    pair<int,int> numValuePair;
    curLine = 1;
    while(getline(InputFile,LineFile)){
        SpaceStrippedLine = StringToStringList(LineFile); //parse spasi
        if(curLine == 1){
            numValue = stoi(SpaceStrippedLine[0]);
            if(numValue < 0){
                this->ClearParserData();
                throw InvalidMiscMoneyConfigException();
                return;
            }
            this->winningMoney = numValue;
        } else if(curLine ==2){
            numValue = stoi(SpaceStrippedLine[0]);
            if(numValue < 0){
                this->ClearParserData();
                throw InvalidMiscWeightConfigException();
                return;
            }
            this->winningWeight = numValue;
        }else if(curLine == 3){
            numValuePair = {stoi(SpaceStrippedLine[0]),stoi(SpaceStrippedLine[1])};
            if(numValuePair.first <=0 || numValuePair.second<=0){
                this->ClearParserData();
                throw InvalidStorageDimensionConfigException();
                return;
            }
            this->storageSize = numValuePair;
        }else if(curLine ==4){
            numValuePair = {stoi(SpaceStrippedLine[0]),stoi(SpaceStrippedLine[1])};
            if(numValuePair.first <=0 || numValuePair.second<=0){
                this->ClearParserData();
                throw InvalidFieldDimensionConfigException();
                return;
            }
            this->fieldSize = numValuePair;
        } else if(curLine == 5){
            numValuePair = {stoi(SpaceStrippedLine[0]),stoi(SpaceStrippedLine[1])};
            if(numValuePair.first <=0 || numValuePair.second<=0){
                this->ClearParserData();
                throw InvalidFarmDimensionConfigException();
                return;
            }
            this->farmSize = numValuePair;
        }
        curLine++;
    }

    cout<<"Konfigurasi misc.txt berhasil!\n";
}

void ParserMisc::ClearParserData()
{
    this->winningMoney = 0;
    this->winningWeight = 0;
    this->storageSize = {0,0};
    this->fieldSize = {0,0};
    this->farmSize = {0,0};
}

int ParserMisc::getWinningMoney()
{
    return winningMoney;
}

int ParserMisc::getWinningWeight()
{
    return winningWeight;
}

pair<int, int> ParserMisc::getStorageSize()
{
    return storageSize;
}

pair<int, int> ParserMisc::getFieldSize()
{
    return fieldSize;
}

pair<int, int> ParserMisc::getFarmSize()
{
    return farmSize;
}

ostream &operator<<(ostream &os, ParserMisc &PM)
{
    os<<PM.winningMoney<<"\n";
    os<<PM.winningWeight<<"\n";
    os<<PM.storageSize.first<<" "<<PM.storageSize.second<<"\n";
    os<<PM.fieldSize.first<<" "<<PM.fieldSize.second<<"\n";
    os<<PM.farmSize.first<<" "<<PM.farmSize.second<<"\n";
    return os;
}
