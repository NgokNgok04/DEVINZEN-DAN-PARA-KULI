#include "../Header/Hewan.hpp"

Hewan::Hewan(int idKonfig){
    setID(idKonfig);
    setKode(ParserHewan::getCode(idKonfig));
    setName(ParserHewan::getName(idKonfig));
    setPrice(ParserHewan::getPrice(idKonfig));
    setTipeObject("HEWAN");
    type = ParserHewan::getType(idKonfig);
    weightHarvest = ParserHewan::getHarvestWeight(idKonfig);
    weight = 0;
}

void Hewan::makan(Product makanan){
    if((type=="HERBIVORE" && makanan.fromHewan()) || (type=="CARNIVORE" && !makanan.fromHewan())){
        // throw exception
    }
    weight += makanan.getAddedWeight();
}

vector<Product*> Hewan::hasilPanen(){
    int *arr = ParserProduk::findOrigin(getName()),n=(type=="OMNIVORE")?2:1;
    vector<Product*> prodArr;
    for(int i=0;i<n;i++){
        Product* temp = new Product(arr[i]);
        prodArr.push_back(temp);
    }
    return prodArr;
}

bool Hewan::isHarvestable(){
    return weight>=weightHarvest;
}

string Hewan::getType(){
    return type;
}
int Hewan::getWeightHarvest(){
    return weightHarvest;
}

int Hewan::getCurWeight(){
    return weight;
}