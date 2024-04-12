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
    vector<int> arr = ParserProduk::findOrigin(getName());
    int n=(type=="OMNIVORE")?2:1;
    vector<Product*> prodArr;
    for(int i=0;i<n;i++){
        Product* temp = new Product(arr[i],true);
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

Hewan& Hewan::operator=(const Hewan& other){
    GameObject::operator=(other);
    type = other.type;
    weightHarvest = other.weightHarvest;
    weight = other.weight;
    return *this;
}

bool Hewan::operator==(const Hewan& other){
    return GameObject::operator==(other) && weight==other.weight;
}