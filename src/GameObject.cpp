#include "GameObject.hpp"
#include "Exception.hpp"
using namespace std;

int Hewan::totalHewan = 0;
int Tanaman::totalTanaman = 0;
int Product::totalProduct = 0;
int Bangunan::totalBangunan = 0;

// gameobject
GameObject::GameObject(int id, string kode_huruf, float price, string name)
{
    this->id = id;
    this->kode_huruf = kode_huruf;
    this->price = price;
    this->name = name;
}

int GameObject::getID()
{
    return id;
}

string GameObject::getKode()
{
    return kode_huruf;
}

float GameObject::getPrice()
{
    return price;
}

string GameObject::getName()
{
    return name;
}

// product
Product::Product(int id, string kodeHuruf, string name, string type, string origin, int addedWeight, float price) : GameObject(id, kodeHuruf, price, name)
{
    this->type = type;
    this->isFromHewan = (type == "PRODUCT_ANIMAL");
    this->addedWeight = addedWeight;
    this->origin = origin;
    totalProduct++;
}

bool Product::fromHewan()
{
    return isFromHewan;
}

int Product::getAddedWeight()
{
    return addedWeight;
}

// makhluk hidup
MakhlukHidup::MakhlukHidup(int id, string kodeHuruf, float price, string name, string type) : GameObject(id, kodeHuruf, price, name)
{
    this->type = type;
}

// hewan
Hewan::Hewan(int id, string kode_huruf, float price, string name, string type, int weightHarvest) : MakhlukHidup(id, kode_huruf, price, name, type)
{
    this->weightHarvest = weightHarvest;
    this->type = type;
    weight = 0;
    totalHewan++;
}

void Hewan::makan(Product makanan)
{
    bool status = (type == "HERBIVORE" && !makanan.fromHewan()) || (type == "CARNIVORE" && makanan.fromHewan());
    if (!status)
    {
        throw MakananTidakSesuai();
    }
    weight += makanan.getAddedWeight();
}

bool Hewan::isHarvestable()
{
    return weight >= weightHarvest;
}

// tanaman
Tanaman::Tanaman(int id, string kode_huruf, float price, string name, string type, int durationHarvest) : MakhlukHidup(id, kode_huruf, price, name, type)
{
    this->durationHarvest = durationHarvest;
    this->type = type;
    this->age = 0;
    totalTanaman++;
}

bool Tanaman::isHarvestable()
{
    return age >= durationHarvest;
}

void Tanaman::incrementAge()
{
    age++;
}

// bangunan
Bangunan::Bangunan(int id, string kodeHuruf, float price, string name, string pemilik) : GameObject(id, kodeHuruf, price, name)
{
    this->pemilik = pemilik;
}