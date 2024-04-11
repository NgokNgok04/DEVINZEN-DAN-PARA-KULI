#include "../Header/Hewan.hpp"

Hewan::Hewan(){}
Hewan::Hewan(int idKonfig){
    setID(idKonfig);
    setKode(konfig.getCode(idKonfig));
    setName(konfig.getName(idKonfig));
    setPrice(konfig.getPrice(idKonfig));
    setTipeObject("HEWAN");
    type = konfig.getType(idKonfig);
    weightHarvest = konfig.getHarvestWeight(idKonfig);
    weight = 0;
}

// void Hewan::makan(Product makanan){
//     if((type=="HERBIVORE" && makanan.fromHewan()) || (type=="CARNIVORE" && !makanan.fromHewan())){
//         // throw exception
//     }
//     weight += makanan.getAddedWeight();
// }

// Product* Hewan::hasilPanen(){
//     Product temp;
//     int *arr = temp.getKonfig().findOrigin(getName());
    
// }

bool Hewan::isHarvestable(){
    return weight>=weightHarvest;
}