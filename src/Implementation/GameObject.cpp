#include "../Header/GameObject.hpp"

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

string GameObject::getTipeObject()
{
    return tipeObject;
}

void GameObject::setID(int id)
{
    this->id = id;
}
void GameObject::setKode(string kode)
{
    this->kode_huruf = kode;
}
void GameObject::setPrice(float price)
{
    this->price = price;
}
void GameObject::setName(string name)
{
    this->name = name;
}

void GameObject::setTipeObject(string tipe)
{
    this->tipeObject = tipe;
}

GameObject &GameObject::operator=(const GameObject &other)
{
    this->id = other.id;
    this->kode_huruf = other.kode_huruf;
    this->price = other.price;
    this->name = other.name;
    this->tipeObject = other.tipeObject;
    return *this;
}
bool GameObject::operator==(const GameObject &other)
{
    return this->id == other.id && this->tipeObject == other.tipeObject;
}