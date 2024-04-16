#include "../Header/ParserMisc.hpp"
#include "../Header/helper.hpp"
#include <bits/stdc++.h>
int ParserMisc::winningMoney = 0;
int ParserMisc::winningWeight = 0;
pair<int,int> ParserMisc::storageSize = pair<int,int>();
pair<int,int> ParserMisc::fieldSize= pair<int,int>();
pair<int,int> ParserMisc::farmSize= pair<int,int>();
void ParserMisc::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); // buka file

    if (!InputFile.is_open())
    { // jika gagal dibuka lempar exception
        throw MiscConfigMissingException();
        return;
    }

    vector<string> SpaceStrippedLine;
    string LineFile;
    int numValue, curLine;
    pair<int, int> numValuePair;
    curLine = 1;
    while (getline(InputFile, LineFile))
    {
        SpaceStrippedLine = StringToStringList(LineFile); // parse spasi
        if (curLine == 1)
        {
            numValue = stoi(SpaceStrippedLine[0]);
            if(numValue < 0){
                ParserMisc::ClearParserData();
                throw InvalidMiscMoneyConfigException();
                return;
            }
            ParserMisc::winningMoney = numValue;
        } else if(curLine ==2){
            numValue = stoi(SpaceStrippedLine[0]);
            if(numValue < 0){
                ParserMisc::ClearParserData();
                throw InvalidMiscWeightConfigException();
                return;
            }
            ParserMisc::winningWeight = numValue;
        }else if(curLine == 3){
            numValuePair = {stoi(SpaceStrippedLine[0]),stoi(SpaceStrippedLine[1])};
            if(numValuePair.first <=0 || numValuePair.second<=0){
                ParserMisc::ClearParserData();
                throw InvalidStorageDimensionConfigException();
                return;
            }
            ParserMisc::storageSize = numValuePair;
        }else if(curLine ==4){
            numValuePair = {stoi(SpaceStrippedLine[0]),stoi(SpaceStrippedLine[1])};
            if(numValuePair.first <=0 || numValuePair.second<=0){
                ParserMisc::ClearParserData();
                throw InvalidFieldDimensionConfigException();
                return;
            }
            ParserMisc::fieldSize = numValuePair;
        } else if(curLine == 5){
            numValuePair = {stoi(SpaceStrippedLine[0]),stoi(SpaceStrippedLine[1])};
            if(numValuePair.first <=0 || numValuePair.second<=0){
                ParserMisc::ClearParserData();
                throw InvalidFarmDimensionConfigException();
                return;
            }
            ParserMisc::farmSize = numValuePair;
        }
        curLine++;
    }

}

void ParserMisc::ClearParserData()
{
    ParserMisc::winningMoney = 0;
    ParserMisc::winningWeight = 0;
    ParserMisc::storageSize = {0,0};
    ParserMisc::fieldSize = {0,0};
    ParserMisc::farmSize = {0,0};
}

int ParserMisc::getWinningMoney()
{
    return ParserMisc::winningMoney;
}

int ParserMisc::getWinningWeight()
{
    return ParserMisc::winningWeight;
}

pair<int, int> ParserMisc::getStorageSize()
{
    return ParserMisc::storageSize;
}

pair<int, int> ParserMisc::getFieldSize()
{
    return ParserMisc::fieldSize;
}

pair<int, int> ParserMisc::getFarmSize()
{
    return ParserMisc::farmSize;
}

ostream &operator<<(ostream &os, ParserMisc &PM)
{
    os << PM.winningMoney << "\n";
    os << PM.winningWeight << "\n";
    os << PM.storageSize.first << " " << PM.storageSize.second << "\n";
    os << PM.fieldSize.first << " " << PM.fieldSize.second << "\n";
    os << PM.farmSize.first << " " << PM.farmSize.second << "\n";
    return os;
}
