#include "../Header/ParserHewan.hpp"
#include "../Header/Exception.hpp"
#include "../Header/helper.hpp"
#include <bits/stdc++.h>

void ParserHewan::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); //buka file

    if(!InputFile.is_open()){ //jika gagal dibuka lempar exception
        throw AnimalConfigMissingException();
        return;
    }
    vector<string> SpaceStrippedLine;
    string LineFile;
    int numValue;
    bool flagAnimalType;
    while(getline(InputFile,LineFile)){
        flagAnimalType = false;
        SpaceStrippedLine = StringToStringList(LineFile); //parse spasi
        //validasi dan input data id hewan
        numValue = stoi(SpaceStrippedLine[0]);
        if(numValue <=0){ //ID tidak boleh negatif
            this->ClearParserData();
            throw InvalidAnimalIDConfigException();
            return;
        }
        this->animalID.push_back(numValue);

        this->animalCode.push_back(SpaceStrippedLine[1]);//input code
        this->animalName.push_back(SpaceStrippedLine[2]);//input nama hewan
        
        for(int i = 0; i<this->validAnimalTypes.size(); i++){ //validasi tipe hewan
            if(SpaceStrippedLine[3] == this->validAnimalTypes[i]){ //hanya tipe data yang valid yang bisa diinput
                flagAnimalType = true;
                break;
            }
        }
        if(flagAnimalType){
            this->animalType.push_back(SpaceStrippedLine[3]);//input tipe hewan
        } else {
            this->ClearParserData();
            throw InvalidAnimalTypeConfigException();
            return;
        }
        numValue = stoi(SpaceStrippedLine[4]); //VALIDASI DAN INPUT BERAT HEWAN
        if(numValue <0){ //berat tidak boleh negatif
            this->ClearParserData();
            throw InvalidAnimalWeightConfigException();
            return;
        }
        this->harvestWeight.push_back(numValue);
        //VALIDASI DAN INPUT HARGA HEWAN
        numValue = stoi(SpaceStrippedLine[5]);
        if(numValue <=0){ //harga tidak boleh negatif
            this->ClearParserData();
            throw InvalidAnimalPriceConfigException();
            return;
        }
        this->price.push_back(numValue);
    }
    cout<<"Konfigurasi animal.txt berhasil!\n";
}

void ParserHewan::ClearParserData()
{
    this->animalID.clear();
    this->animalName.clear();
    this->animalCode.clear();
    this->animalType.clear();
    this->harvestWeight.clear();
    this->price.clear();
}

int ParserHewan::getID(int i)
{
    return animalID[i];
}

string ParserHewan::getCode(int i)
{
    return animalCode[i];
}

string ParserHewan::getName(int i)
{
    return animalName[i];
}

string ParserHewan::getType(int i)
{
    return animalType[i];
}

int ParserHewan::getHarvestWeight(int i)
{
    return harvestWeight[i];
}

int ParserHewan::getPrice(int i)
{
    return price[i];
}

int ParserHewan::getConfigSize()
{
    return animalID.size();
}

int ParserHewan::convertCodeToID(string Code)
{
    for(int i = 0; i<getConfigSize(); i++){
        if(animalCode[i] == Code){
            return animalID[i];
        }
    }

    return -1;
}

int ParserHewan::convertNameToID(string Name)
{
    for(int i = 0; i<getConfigSize(); i++){
        if(animalName[i] == Name){
            return animalID[i];
        }
    }

    return -1;
}

ostream &operator<<(ostream &os, ParserHewan &PH)
{
    for(int i = 0; i<PH.animalID.size(); i++){
        os<<PH.animalID[i]<<" "<<PH.animalCode[i]<<" "<<PH.animalName[i]<<" "<<PH.animalType[i]<<" "<<PH.harvestWeight[i]<<" "<<PH.price[i]<<"\n";
    }
    
    return os;
}
