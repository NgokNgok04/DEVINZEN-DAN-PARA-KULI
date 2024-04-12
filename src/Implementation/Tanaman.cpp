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
    int idProduct = ParserProduk::findOrigin(getName());
    Product* temp = new Product(idProduct);
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