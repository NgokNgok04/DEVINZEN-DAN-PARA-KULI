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
    cout<<"file animal kebaca\n";

    
    vector<string> SpaceStrippedLine;
    string LineFile;
    int numValue;
    while(getline(InputFile,LineFile)){
        SpaceStrippedLine = StringToStringList(LineFile);
        //validasi dan input data id hewan
        numValue = stoi(SpaceStrippedLine[0]);
        if(numValue <0){ //ID tidak boleh negatif
            throw InvalidAnimalIDConfigException();
            return;
        }
        this->animalID.push_back(numValue);

        this->animalCode.push_back(SpaceStrippedLine[1]);//input code
        this->animalName.push_back(SpaceStrippedLine[2]);//input nama hewan
        this->animalType.push_back(SpaceStrippedLine[3]);//input tipe hewan
        numValue = stoi(SpaceStrippedLine[4]); //VALIDASI DAN INPUT BERAT HEWAN
        if(numValue <0){ //berat tidak boleh negatif
            throw InvalidAnimalWeightConfigException();
            return;
        }
        this->harvestWeight.push_back(numValue);
        //VALIDASI DAN INPUT HARGA HEWAN
        numValue = stoi(SpaceStrippedLine[5]);
        if(numValue <0){ //harga tidak boleh negatif
            throw InvalidAnimalPriceConfigException();
            return;
        }
        this->price.push_back(numValue);
    }
}

ostream &operator<<(ostream &os, ParserHewan &PH)
{
    for(int i = 0; i<PH.animalID.size(); i++){
        os<<PH.animalID[i]<<" "<<PH.animalCode[i]<<" "<<PH.animalName[i]<<" "<<PH.animalType[i]<<" "<<PH.harvestWeight[i]<<" "<<PH.price[i]<<"\n";
    }
    
    return os;
}
