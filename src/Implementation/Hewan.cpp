#include "../Header/Hewan.hpp"



map<string, pair<string, string>> Hewan::konversiPanen = {
    {"COW", {"COW_MEAT", ""}},
    {"SHEEP", {"SHEEP_MEAT", ""}},
    {"HORSE", {"HORSE_MEAT", ""}},
    {"RABBIT", {"RABBIT_MEAT", ""}},
    {"SNAKE", {"SNAKE_MEAT", ""}},
    {"DUCK", {"DUCK_MEAT", "DUCK_EGG"}},
    {"CHICKEN", {"CHICKEN_MEAT", "CHICKEN_EGG"}}};

Hewan::Hewan(int idKonfig)
{
    setID(idKonfig);
    setKode(ParserHewan::getCode(idKonfig));
    setName(ParserHewan::getName(idKonfig));
    setPrice(ParserHewan::getPrice(idKonfig));
    setTipeObject("HEWAN");
    type = ParserHewan::getType(idKonfig);
    weightHarvest = ParserHewan::getHarvestWeight(idKonfig);
    weight = 0;
}

void Hewan::makan(Product makanan)
{
    if ((type == "HERBIVORE" && makanan.fromHewan()) || (type == "CARNIVORE" && !makanan.fromHewan()))
    {
        // throw exception
    }
    weight += makanan.getAddedWeight();
}

vector<Product *> Hewan::hasilPanen()
{
    pair<string, string> productPanen = konversiPanen[getName()];
    vector<Product *> prodArr;
    prodArr.push_back(new Product(ParserProduk::convertNameToID(productPanen.first), true));
    if (productPanen.second != "")
    {
        prodArr.push_back(new Product(ParserProduk::convertNameToID(productPanen.second), true));
    }
    return prodArr;
}

bool Hewan::isHarvestable()
{
    return weight >= weightHarvest;
}

string Hewan::getType()
{
    return type;
}
int Hewan::getWeightHarvest()
{
    return weightHarvest;
}

int Hewan::getCurWeight()
{
    return weight;
}

Hewan& Hewan::operator=(const Hewan& other){
    GameObject::operator=(other);
    type = other.type;
    weightHarvest = other.weightHarvest;
    weight = other.weight;
    return *this;
}

bool Hewan::operator==(const Hewan &other)
{
    return GameObject::operator==(other) && weight == other.weight;
}

void Hewan::setWeight(int weight){
    this->weight = weight;
}