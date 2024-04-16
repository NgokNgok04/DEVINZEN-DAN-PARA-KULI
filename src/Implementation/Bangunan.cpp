#include "../Header/Bangunan.hpp"

Bangunan::Bangunan(int idKonfig){
    setID(idKonfig);
    setKode(ParserResep::getCode(idKonfig));
    setName(ParserResep::getName(idKonfig));
    setPrice(ParserResep::getPrice(idKonfig));
    setTipeObject("BANGUNAN");
}

Bangunan& Bangunan::operator=(const Bangunan& other){
    GameObject::operator=(other);
    return *this;
}

bool Bangunan::operator==(const Bangunan& other){
    return GameObject::operator==(other);
}