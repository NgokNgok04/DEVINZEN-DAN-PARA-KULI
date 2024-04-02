#include "ParserHewan.hpp"
#include "../exceptions/Exceptions.hpp"
#include "../misc/helper.hpp"
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

ostream &operator<<(ostream &os, ParserHewan &PH)
{
    for(int i = 0; i<PH.animalID.size(); i++){
        os<<PH.animalID[i]<<" "<<PH.animalCode[i]<<" "<<PH.animalName[i]<<" "<<PH.animalType[i]<<" "<<PH.harvestWeight[i]<<" "<<PH.price[i]<<"\n";
    }
    
    return os;
}
