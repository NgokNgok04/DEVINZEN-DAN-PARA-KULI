#include "../Header/Tanaman.hpp"


map<string, string> Tanaman::konversiPanen = {
    {"TEAK_TREE", "TEAK_WOOD"},
    {"SANDALWOOD_TREE", "SANDALWOOD_WOOD"},
    {"ALOE_TREE", "ALOE_WOOD"},
    {"IRONWOOD_TREE", "IRONWOOD_WOOD"},
    {"APPLE_TREE", "APPLE"},
    {"ORANGE_TREE", "ORANGE"},
    {"BANANA_TREE", "BANANA"},
    {"GUAVA_TREE", "GUAVA"},
};

Tanaman::Tanaman(int idKonfig)
{
    setID(idKonfig);
    setKode(ParserTanaman::getCode(idKonfig));
    setName(ParserTanaman::getName(idKonfig));
    setPrice(ParserTanaman::getPrice(idKonfig));
    setKode(ParserTanaman::getCode(idKonfig));
    setName(ParserTanaman::getName(idKonfig));
    setPrice(ParserTanaman::getPrice(idKonfig));
    setTipeObject("TANAMAN");
    type = ParserTanaman::getType(idKonfig);
    durationHarvest = ParserTanaman::getHarvestDuration(idKonfig);
    type = ParserTanaman::getType(idKonfig);
    durationHarvest = ParserTanaman::getHarvestDuration(idKonfig);
    age = 0;
}

void Tanaman::tambahUmur()
{
    age++;
}

Product *Tanaman::hasilPanen()
{
    int a = ParserProduk::convertNameToID(konversiPanen[getName()]);
    Product *b = new Product(a, false);

    return b;
}
bool Tanaman::isHarvestable()
{
    return age >= durationHarvest;
}

string Tanaman::getType()
{
    return type;
}

int Tanaman::getDurationHarvest()
{
    return durationHarvest;
}

int Tanaman::getCurAge()
{
    return age;
}

Tanaman& Tanaman::operator=(const Tanaman& other){
    GameObject::operator=(other);
    type = other.type;
    durationHarvest = other.durationHarvest;
    age = other.age;
    return *this;
}
bool Tanaman::operator==(const Tanaman &other)
{
    return GameObject::operator==(other) && age == other.age;
}

void Tanaman::setAge(int age){
    this->age = age;
}