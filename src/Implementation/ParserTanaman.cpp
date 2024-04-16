#include "../Header/ParserTanaman.hpp"
#include "../Header/helper.hpp"
#include <bits/stdc++.h>
vector<int> ParserTanaman::plantID = vector<int>();
vector<string> ParserTanaman::plantCode = vector<string>();
vector<string> ParserTanaman::plantName= vector<string>();
vector<string> ParserTanaman::plantType= vector<string>();
vector<int> ParserTanaman::harvestDuration = vector<int>();
vector<int> ParserTanaman::price = vector<int>();
vector<string> ParserTanaman::validPlantTypes= vector<string>();
map<int,int> ParserTanaman::IndexToIDMap = map<int,int>();
map<int,int> ParserTanaman::IDToIndexMap = map<int,int>();
void ParserTanaman::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); // buka file

    if (!InputFile.is_open())
    { // jika gagal dibuka lempar exception
        throw PlantConfigMissingException();
        return;
    }
    vector<string> SpaceStrippedLine;
    string LineFile;
    int numValue;
    bool flagPlantType;
    while (getline(InputFile, LineFile))
    {
        flagPlantType = false;
        SpaceStrippedLine = StringToStringList(LineFile); // parse spasi
        // validasi dan input data id tanaman
        numValue = stoi(SpaceStrippedLine[0]);
        if (numValue <= 0)
        { // ID tidak boleh negatif
            this->ClearParserData();
            throw InvalidPlantIDConfigException();
            return;
        }
        this->plantID.push_back(numValue);

        this->plantCode.push_back(SpaceStrippedLine[1]); // input code
        this->plantName.push_back(SpaceStrippedLine[2]); // input nama tanaman

        for (int i = 0; i < this->validPlantTypes.size(); i++)
        { // validasi tipe tanaman
            if (SpaceStrippedLine[3] == this->validPlantTypes[i])
            { // hanya tipe data yang valid yang bisa diinput
                flagPlantType = true;
                break;
            }
        }
        if (flagPlantType)
        {
            this->plantType.push_back(SpaceStrippedLine[3]); // input tipe tanaman
        }
        else
        {
            this->ClearParserData();
            throw InvalidPlantTypeConfigException();
            return;
        }
        numValue = stoi(SpaceStrippedLine[4]); // VALIDASI DAN INPUT DURASI TANAMAN
        if (numValue < 0)
        { // berat tidak boleh negatif
            this->ClearParserData();
            throw InvalidPlantDurationConfigException();
            return;
        }
        this->harvestDuration.push_back(numValue);
        // VALIDASI DAN INPUT HARGA TANAMAN
        numValue = stoi(SpaceStrippedLine[5]);
        if (numValue <= 0)
        { // harga tidak boleh negatif
            this->ClearParserData();
            throw InvalidPlantPriceConfigException();
            return;
        }
        this->price.push_back(numValue);
    }
    for (int i = 0; i < plantID.size(); i++)
    {
        IndexToIDMap.insert({i, plantID[i]});
        IDToIndexMap.insert({plantID[i], i});
    }
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

int ParserTanaman::getID(int index)
{
    return plantID[index];
}

string ParserTanaman::getCode(int ID)
{
    int index = IDToIndex(ID);
    return plantCode[index];
}

string ParserTanaman::getName(int ID)
{
    int index = IDToIndex(ID);
    return plantName[index];
}

string ParserTanaman::getType(int ID)
{
    int index = IDToIndex(ID);
    return plantType[index];
}

int ParserTanaman::getHarvestDuration(int ID)
{
    int index = IDToIndex(ID);
    return harvestDuration[index];
}

int ParserTanaman::getPrice(int ID)
{
    int index = IDToIndex(ID);
    return price[index];
}

int ParserTanaman::getConfigSize()
{
    return plantID.size();
}

int ParserTanaman::convertCodeToID(string Code)
{
    for (int i = 0; i < getConfigSize(); i++)
    {
        if (plantCode[i] == Code)
        {
            return plantID[i];
        }
    }

    return -1;
}

int ParserTanaman::convertNameToID(string Name)
{
    for (int i = 0; i < getConfigSize(); i++)
    {
        if (plantName[i] == Name)
        {
            return plantID[i];
        }
    }

    return -1;
}
int ParserTanaman::indexToID(int index)
{
    return IndexToIDMap[index];
}
int ParserTanaman::IDToIndex(int ID)
{
    return IDToIndexMap[ID];
}
ostream &operator<<(ostream &os, ParserTanaman &PT)
{
    for (int i = 0; i < PT.plantID.size(); i++)
    {
        os << PT.plantID[i] << " " << PT.plantCode[i] << " " << PT.plantName[i] << " " << PT.plantType[i] << " " << PT.harvestDuration[i] << " " << PT.price[i] << "\n";
    }

    return os;
}
