#include "ParserResep.hpp"
#include "../exceptions/Exceptions.hpp"
#include "../misc/helper.hpp"
#include <bits/stdc++.h>
void ParserResep::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); //buka file

    if(!InputFile.is_open()){ //jika gagal dibuka lempar exception
        throw RecipeConfigMissingException();
        return;
    }

    vector<string> SpaceStrippedLine;
    vector<pair<string,int> > MaterialQuantityPairList;
    pair<string,int> pairTemp;
    string LineFile;
    int numValue;
    while(getline(InputFile,LineFile)){
        SpaceStrippedLine = StringToStringList(LineFile); //parse spasi
        numValue = stoi(SpaceStrippedLine[0]);
        if(numValue <=0){ //ID tidak boleh negatif
            this->ClearParserData();
            throw InvalidRecipeIDConfigException();
            return;
        }
        this->recipeID.push_back(numValue);

        this->recipeCode.push_back(SpaceStrippedLine[1]);
        this->recipeName.push_back(SpaceStrippedLine[2]);
        numValue = stoi(SpaceStrippedLine[3]);
        if(numValue <=0){ //harga tidak boleh negatif atau sama dengan 0
            this->ClearParserData();
            throw InvalidRecipePriceConfigException();
            return;
        }
        this->recipePrice.push_back(numValue);

        for(int i = 4; i<SpaceStrippedLine.size(); i+=2){
            pairTemp.first = SpaceStrippedLine[i];
            numValue = stoi(SpaceStrippedLine[i+1]);
            if(numValue <=0){ //kuantitas material tidak boleh lebih kecil atau sama dengan 0
                this->ClearParserData();
                throw InvalidRecipeQuantityConfigException();
                return;
            }
            pairTemp.second = numValue;
            MaterialQuantityPairList.push_back(pairTemp);
        }

        this->recipeMaterialQuantity.push_back(MaterialQuantityPairList);
    }
    cout<<"Konfigurasi recipe.txt berhasil!\n";
}

void ParserResep::ClearParserData()
{
        this->recipeID.clear();
        this->recipeCode.clear();
        this->recipeName.clear();
        this->recipePrice.clear();
        this->recipeMaterialQuantity.clear();
}

int ParserResep::getID(int i)
{
    return this->recipeID[i];
}

string ParserResep::getCode(int i)
{
    return this->recipeCode[i];
}

string ParserResep::getName(int i)
{
    return this->recipeName[i];
}

int ParserResep::getPrice(int i)
{
    return this->recipePrice[i];
}

vector<pair<string, int>> ParserResep::getRecipeMaterialQuantity(int i)
{
    return this->recipeMaterialQuantity[i];
}

int ParserResep::getConfigSize()
{
    return this->recipeID.size();
}

int ParserResep::convertCodeToID(string Code)
{
    for(int i = 0; i<this->getConfigSize(); i++){
        if(this->recipeCode[i] == Code){
            return this->recipeID[i];
        }
    }

    return -1;
}

int ParserResep::convertNameToID(string Name)
{
    for(int i = 0; i<this->getConfigSize(); i++){
        if(this->recipeName[i] == Name){
            return this->recipeID[i];
        }
    }

    return -1;
}

ostream &operator<<(ostream &os, ParserResep &PR)
{
    for(int i = 0; i<PR.recipeID.size(); i++){
        cout<<PR.recipeID[i]<<" "<<PR.recipeCode[i]<<" "<<PR.recipeName[i]<<" "<<PR.recipePrice[i]<<" ";
        for(int j = 0; j<PR.recipeMaterialQuantity[i].size(); j++){
            cout<<PR.recipeMaterialQuantity[i][j].first<<" "<<PR.recipeMaterialQuantity[i][j].second<<" ";
        }
        cout<<"\n";
    }
}
