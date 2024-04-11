#include "../Header/GameObject.hpp"

int GameObject::getID(){
    return id;
}

string GameObject::getKode(){
    return kode_huruf;
}

float GameObject::getPrice(){
    return price;
}

string GameObject::getName(){
    return name;
}

string GameObject::getTipeObject(){
    return tipeObject;
}

void GameObject::setID(int id){
    this->id = id;
}
void GameObject::setKode(string kode){
    this->kode_huruf = kode;
}
void GameObject::setPrice(float price){
    this->price = price;
}
void GameObject::setName(string name){
    this->name = name;
}

void GameObject::setTipeObject(string tipe){
    this->tipeObject = tipe;
}