#include "../Header/ParserProduk.hpp"
#include "../Header/Exception.hpp"
#include <bits/stdc++.h>
#include "../Header/helper.hpp"
void ParserProduk::ParseFile(string fileDirectory)
{
    ifstream InputFile;
    InputFile.open(fileDirectory); //buka file

    if(!InputFile.is_open()){ //jika gagal dibuka lempar exception
        throw ProductConfigMissingException();
        return;
    }

    vector<string> SpaceStrippedLine;
    string LineFile;
    int numValue;
    bool flagProductType;
    while(getline(InputFile,LineFile)){
        flagProductType = false;
        SpaceStrippedLine = StringToStringList(LineFile); //parse spasi
        //validasi dan input data id produk
        numValue = stoi(SpaceStrippedLine[0]);
        if(numValue <=0){ //ID tidak boleh negatif
            this->ClearParserData();
            throw InvalidProductIDConfigException();
            return;
        }
        this->productID.push_back(numValue);

        this->productCode.push_back(SpaceStrippedLine[1]);//input code
        this->productName.push_back(SpaceStrippedLine[2]);//input nama produk
        
        for(int i = 0; i<this->validProductTypes.size(); i++){ //validasi tipe produk
            if(SpaceStrippedLine[3] == this->validProductTypes[i]){ //hanya tipe data yang valid yang bisa diinput
                flagProductType = true;
                break;
            }
        }
        if(flagProductType){
            this->productType.push_back(SpaceStrippedLine[3]);//input tipe produk
        } else {
            this->ClearParserData();
            throw InvalidProductTypeConfigException();
            return;
        }
        this->productOrigin.push_back(SpaceStrippedLine[4]); //input origin

        numValue = stoi(SpaceStrippedLine[5]); //VALIDASI DAN INPUT BERAT produk
        if(numValue <0){ //berat tidak boleh negatif
            this->ClearParserData();
            throw InvalidProductWeightConfigException();
            return;
        }
        this->addedWeight.push_back(numValue);
        //VALIDASI DAN INPUT HARGA produk
        numValue = stoi(SpaceStrippedLine[6]);
        if(numValue <=0){ //harga tidak boleh negatif
            this->ClearParserData();
            throw InvalidProductPriceConfigException();
            return;
        }
        this->price.push_back(numValue);
    }

    for(int i = 0; i<productID.size(); i++){
        IndexToIDMap.insert({i,productID[i]});
    }
    cout<<"Konfigurasi product.txt berhasil!\n";
}

void ParserProduk::ClearParserData()
{
    this->productID.clear();
    this->productCode.clear();
    this->productName.clear();
    this->productType.clear();
    this->productOrigin.clear();
    this->addedWeight.clear();
    this->price.clear();
}
int ParserProduk::getID(int index)
{
    return productID[index];
}
string ParserProduk::getCode(int index)
{
    return productCode[index];
}
string ParserProduk::getName(int index)
{
    return productName[index];
}
string ParserProduk::getType(int index)
{
    return productType[index];
}
string ParserProduk::getOrigin(int index)
{
    return productOrigin[index];
}
int ParserProduk::getAddedWeight(int index)
{
    return addedWeight[index];
}
int ParserProduk::getPrice(int index)
{
    return price[index];
}
int ParserProduk::getConfigSize()
{
    return productID.size();
}
int ParserProduk::convertCodeToID(string Code)
{
    for(int i = 0; i<getConfigSize(); i++){
        if(productCode[i] == Code){
            return productID[i];
        }
    }

    return -1;
}
int ParserProduk::convertNameToID(string Name)
{
    for(int i = 0; i<getConfigSize(); i++){
        if(productName[i] == Name){
            return productID[i];
        }
    }

    return -1;
}
int ParserProduk::indexToID(int index)
{
    return IndexToIDMap[index];
}
bool ParserProduk::isAnAnimalProduct(int i)
{
    if (productType[i].find("ANIMAL") != string::npos){
        return true;
    } else {
        return false;
    }
}
ostream &operator<<(ostream &os, ParserProduk &PP)
{
    for(int i = 0; i<PP.productID.size(); i++){
        os<<PP.productID[i]<<" "<<PP.productCode[i]<<" "<<PP.productName[i]<<" "<<PP.productType[i]<<" "<<PP.productOrigin[i]<<" "<<PP.addedWeight[i]<<" "<<PP.price[i]<<"\n";
    }
    
    return os;
}