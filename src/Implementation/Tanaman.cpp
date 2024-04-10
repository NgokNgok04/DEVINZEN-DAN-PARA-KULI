#include "../Header/Tanaman.hpp"

Tanaman::Tanaman(int idKonfig){
    setID(idKonfig);
    setKode(konfig.getCode(idKonfig));
    setName(konfig.getName(idKonfig));
    setPrice(konfig.getPrice(idKonfig));
    setTipeObject("TANAMAN");
    type = konfig.getType(idKonfig);
    durationHarvest = konfig.getHarvestDuration(idKonfig);
    age = 0;
}

void Tanaman::tambahUmur(){
    age++;
}

Product Tanaman::hasilPanen(){

}
bool Tanaman::isHarvestable(){
    return age>=durationHarvest;
}