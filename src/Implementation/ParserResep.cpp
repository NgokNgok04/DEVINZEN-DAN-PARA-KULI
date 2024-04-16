#include "../Header/ParserResep.hpp"
#include "../Header/helper.hpp"
#include <bits/stdc++.h>
vector<int> ParserResep::recipeID = vector<int>() ;
vector<string> ParserResep::recipeCode= vector<string>();
vector<string> ParserResep::recipeName= vector<string>();
vector<int> ParserResep::recipePrice = vector<int>();
vector<vector<pair<string,int> > > ParserResep::recipeMaterialQuantity = vector<vector<pair<string,int> > > ();
map<int,int> ParserResep::IndexToIDMap = map<int,int>();
map<int,int> ParserResep::IDToIndexMap= map<int,int>();
void ParserResep::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); // buka file

    if (!InputFile.is_open())
    { // jika gagal dibuka lempar exception
        throw RecipeConfigMissingException();
        return;
    }

    vector<string> SpaceStrippedLine;
    pair<string, int> pairTemp;
    string LineFile;
    int numValue;
    while (getline(InputFile, LineFile))
    {
        SpaceStrippedLine = StringToStringList(LineFile); // parse spasi
        numValue = stoi(SpaceStrippedLine[0]);
        if (numValue <= 0)
        { // ID tidak boleh negatif
            this->ClearParserData();
            throw InvalidRecipeIDConfigException();
            return;
        }
        this->recipeID.push_back(numValue);

        this->recipeCode.push_back(SpaceStrippedLine[1]);
        this->recipeName.push_back(SpaceStrippedLine[2]);
        numValue = stoi(SpaceStrippedLine[3]);
        if (numValue <= 0)
        { // harga tidak boleh negatif atau sama dengan 0
            this->ClearParserData();
            throw InvalidRecipePriceConfigException();
            return;
        }
        this->recipePrice.push_back(numValue);

        vector<pair<string, int>> MaterialQuantityPairList;
        for (int i = 4; i < SpaceStrippedLine.size(); i += 2)
        {
            pairTemp.first = SpaceStrippedLine[i];
            numValue = stoi(SpaceStrippedLine[i + 1]);
            if (numValue <= 0)
            { // kuantitas material tidak boleh lebih kecil atau sama dengan 0
                this->ClearParserData();
                throw InvalidRecipeQuantityConfigException();
                return;
            }
            pairTemp.second = numValue;
            MaterialQuantityPairList.push_back(pairTemp);
        }

        this->recipeMaterialQuantity.push_back(MaterialQuantityPairList);
    }
    for (int i = 0; i < recipeID.size(); i++)
    {
        IndexToIDMap.insert({i, recipeID[i]});
        IDToIndexMap.insert({recipeID[i], i});
    }
}

void ParserResep::ClearParserData()
{
    this->recipeID.clear();
    this->recipeCode.clear();
    this->recipeName.clear();
    this->recipePrice.clear();
    this->recipeMaterialQuantity.clear();
}

int ParserResep::getID(int index)
{
    return recipeID[index];
}

string ParserResep::getCode(int ID)
{
    int index = IDToIndex(ID);
    return recipeCode[index];
}

string ParserResep::getName(int ID)
{
    int index = IDToIndex(ID);
    return recipeName[index];
}

int ParserResep::getPrice(int ID)
{
    int index = IDToIndex(ID);
    return recipePrice[index];
}

vector<pair<string, int>> ParserResep::getRecipeMaterialQuantity(int ID)
{
    int index = IDToIndex(ID);
    return recipeMaterialQuantity[index];
}

int ParserResep::getConfigSize()
{
    return recipeID.size();
}

int ParserResep::convertCodeToID(string Code)
{
    for (int i = 0; i < getConfigSize(); i++)
    {
        if (recipeCode[i] == Code)
        {
            return recipeID[i];
        }
    }

    return -1;
}

int ParserResep::convertNameToID(string Name)
{
    for (int i = 0; i < getConfigSize(); i++)
    {
        if (recipeName[i] == Name)
        {
            return recipeID[i];
        }
    }

    return -1;
}
int ParserResep::indexToID(int index)
{
    return IndexToIDMap[index];
}
int ParserResep::IDToIndex(int ID)
{
    return IDToIndexMap[ID];
}

ostream &operator<<(ostream &os, ParserResep &PR)
{
    for(int i = 0; i<PR.recipeID.size(); i++){
        os<<PR.recipeID[i]<<" "<<PR.recipeCode[i]<<" "<<PR.recipeName[i]<<" "<<PR.recipePrice[i]<<" ";
        for(int j = 0; j<PR.recipeMaterialQuantity[i].size(); j++){
            os<<PR.recipeMaterialQuantity[i][j].first<<" "<<PR.recipeMaterialQuantity[i][j].second<<" ";
        }
        os<<"\n";
    }
    return os;
}
