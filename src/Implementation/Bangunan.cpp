#include "../Header/Bangunan.hpp"

Bangunan::Bangunan(int idKonfig){
    setID(idKonfig);
    setKode(ParserResep::getCode(idKonfig));
    setName(ParserResep::getName(idKonfig));
    setPrice(ParserResep::getPrice(idKonfig));
    setTipeObject("BANGUNAN");
}