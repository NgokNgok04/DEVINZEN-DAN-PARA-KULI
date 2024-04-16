#include "../Header/Tanaman.hpp"


Tanaman::Tanaman(int idKonfig){
    setID(idKonfig);
    setKode(ParserTanaman::getCode(idKonfig));
    setName(ParserTanaman::getName(idKonfig));
    setPrice(ParserTanaman::getPrice(idKonfig));
    setTipeObject("TANAMAN");
    type = ParserTanaman::getType(idKonfig);
    durationHarvest = ParserTanaman::getHarvestDuration(idKonfig);
    age = 0;
}

void Tanaman::tambahUmur(){
    age++;
}

Product* Tanaman::hasilPanen(){
    vector<int> idProduct = ParserProduk::findOrigin(getName());
    Product* temp = new Product(idProduct.front(),false);
    return temp;
}
bool Tanaman::isHarvestable(){
    return age>=durationHarvest;
}

string Tanaman::getType(){
    return type;
}

int Tanaman::getDurationHarvest(){
    return durationHarvest;
}

int Tanaman::getCurAge(){
    return age;
}

void Tanaman::setAge(int age)
{
    this->age = age;
}
Tanaman& Tanaman::operator=(const Tanaman& other){
    GameObject::operator=(other);
    type = other.type;
    durationHarvest = other.durationHarvest;
    age = other.age;
    return *this;
}
bool Tanaman::operator==(const Tanaman& other){
    return GameObject::operator==(other) && age==other.age;
}