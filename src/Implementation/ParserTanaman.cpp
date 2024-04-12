#include "../Header/ParserTanaman.hpp"
#include "../Header/helper.hpp"
#include <bits/stdc++.h>
#include "../Header/Exception.hpp"
void ParserTanaman::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); //buka file

    if(!InputFile.is_open()){ //jika gagal dibuka lempar exception
        throw PlantConfigMissingException();
        return;
    }
    vector<string> SpaceStrippedLine;
    string LineFile;
    int numValue;
    bool flagPlantType;
    while(getline(InputFile,LineFile)){
        flagPlantType = false;
        SpaceStrippedLine = StringToStringList(LineFile); //parse spasi
        //validasi dan input data id tanaman
        numValue = stoi(SpaceStrippedLine[0]);
        if(numValue <=0){ //ID tidak boleh negatif
            this->ClearParserData();
            throw InvalidPlantIDConfigException();
            return;
        }
        this->plantID.push_back(numValue);

        this->plantCode.push_back(SpaceStrippedLine[1]);//input code
        this->plantName.push_back(SpaceStrippedLine[2]);//input nama tanaman
        
        for(int i = 0; i<this->validPlantTypes.size(); i++){ //validasi tipe tanaman
            if(SpaceStrippedLine[3] == this->validPlantTypes[i]){ //hanya tipe data yang valid yang bisa diinput
                flagPlantType = true;
                break;
            }
        }
        if(flagPlantType){
            this->plantType.push_back(SpaceStrippedLine[3]);//input tipe tanaman
        } else {
            this->ClearParserData();
            throw InvalidPlantTypeConfigException();
            return;
        }
        numValue = stoi(SpaceStrippedLine[4]); //VALIDASI DAN INPUT DURASI TANAMAN
        if(numValue <0){ //berat tidak boleh negatif
            this->ClearParserData();
            throw InvalidPlantDurationConfigException();
            return;
        }
        this->harvestDuration.push_back(numValue);
        //VALIDASI DAN INPUT HARGA TANAMAN
        numValue = stoi(SpaceStrippedLine[5]);
        if(numValue <=0){ //harga tidak boleh negatif
            this->ClearParserData();
            throw InvalidPlantPriceConfigException();
            return;
        }
        this->price.push_back(numValue);
    }
    cout<<"Konfigurasi plant.txt berhasil!\n";
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

int ParserTanaman::getID(int i)
{
    return plantID[i];
}

string ParserTanaman::getCode(int i)
{
    return plantCode[i];
}

string ParserTanaman::getName(int i)
{
    return plantName[i];
}

string ParserTanaman::getType(int i)
{
    return plantType[i];
}

int ParserTanaman::getHarvestDuration(int i)
{
    return harvestDuration[i];
}

int ParserTanaman::getPrice(int i)
{
    return price[i];
}

int ParserTanaman::getConfigSize()
{
    return plantID.size();
}

int ParserTanaman::convertCodeToID(string Code)
{
    for(int i = 0; i<getConfigSize(); i++){
        if(plantCode[i] == Code){
            return plantID[i];
        }
    }

    return -1;
}

int ParserTanaman::convertNameToID(string Name)
{
    for(int i = 0; i<getConfigSize(); i++){
        if(plantName[i] == Name){
            return plantID[i];
        }
    }

    return -1;
}

ostream &operator<<(ostream &os, ParserTanaman &PT)
{
    for(int i = 0; i<PT.plantID.size(); i++){
        os<<PT.plantID[i]<<" "<<PT.plantCode[i]<<" "<<PT.plantName[i]<<" "<<PT.plantType[i]<<" "<<PT.harvestDuration[i]<<" "<<PT.price[i]<<"\n";
    }
    
    return os;
}
