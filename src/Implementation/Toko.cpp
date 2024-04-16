#include <iostream>
#include <vector>
#include <string>
#include "../Header/Toko.hpp"
using namespace std;
vector<Hewan> Toko::availableHewan = vector<Hewan>();
vector<Tanaman> Toko::availableTanaman = vector<Tanaman>();
vector<pair<Product, int>> Toko::availableProduct = vector<pair<Product, int>>();
vector<pair<Bangunan, int>> Toko::availableBangunan = vector<pair<Bangunan, int>>();

void Toko::printProduct(){
    for(int i = 0; i < availableProduct.size(); i++){
        cout << i + 1 << ". ";
        cout << availableProduct[i].first.getName() << " " << availableProduct[i].second << endl;
    }
}

void Toko::printBangunan(){
    for(int i = 0; i < availableBangunan.size(); i++){
        cout << i + 1 << ". ";
        cout << availableBangunan[i].first.getName() << " " << availableBangunan[i].second << endl;
    }
}

void Toko::initialize(){
    int idDummyToko;
    for(int i = 0; i < ParserHewan::getConfigSize(); i++){

        idDummyToko = ParserHewan::indexToID(i);
        Hewan hewanDummyToko(idDummyToko);
        availableHewan.push_back(hewanDummyToko);
    }

    for(int i = 0; i < ParserTanaman::getConfigSize(); i++){
        idDummyToko = ParserTanaman::indexToID(i);
        Tanaman tanamanDummyToko(idDummyToko);
        availableTanaman.push_back(tanamanDummyToko);
    }

    for(int i = 0; i < ParserProduk::getConfigSize(); i++){
        idDummyToko = ParserProduk::indexToID(i);
        Product productDummyToko(idDummyToko,ParserProduk::isAnAnimalProduct(idDummyToko));
        availableProduct.push_back(make_pair(productDummyToko,0));
    }

    for(int i = 0; i < ParserResep::getConfigSize(); i++){
        idDummyToko = ParserResep::indexToID(i);
        Bangunan bangunanDummyToko(idDummyToko);
        availableBangunan.push_back(make_pair(bangunanDummyToko,0));
    }
};

int Toko::buyProcess(){
    cout << "Selamat datang di toko!!" << endl;
    string response;
    cout << "Berikut merupakan hal yang dapat anda Beli :" << endl;
    cout << "1. Hewan" << endl;
    cout << "2. Tanaman" << endl;
    int i = 2;
    if (!isProductEmptyStock()){
        i++;
        cout << i << ". Product" << endl;
    }
    if (!isBangunanEmptyStock()){
        i++;
        cout << i << ". Bangunan" << endl;
    }
    i++;
    cout << i << ". Cancel Buy" << endl;
    cout << "Masukkanlah pilihan (1-" << i << ") : ";
    try{
        cin >> response;
        int validResponse;
        if (isAllDigits(response)){
            validResponse = stoi(response);
        } else {
            throw InvalidResponseToko();
        }
        if (validResponse == i){
            return 0;
        } else if (validResponse >= 1 && validResponse < i) {
            return validResponse;
        } else {
            throw InvalidResponseToko();
        }
    } catch (InvalidResponseToko err) {
        cout << err.what();
        cout << endl;
        return -1;
    }
    return 0;
}

void Toko::itemDibeli(GameObject* gameObject, int quantity){
    if(gameObject->getTipeObject()=="PRODUCT"){
        for(int i = 0; i < availableProduct.size(); i++){
            if (*gameObject == availableProduct[i].first){
                availableProduct[i].second -= quantity;
                return;
            }
        }
    }else{
        for (int i = 0; i < availableBangunan.size(); i++){
            if (*gameObject == availableBangunan[i].first){
                availableBangunan[i].second -= quantity;
                return;
            }
        }
    }
}

void Toko::itemDijual(GameObject* gameObject, int quantity){
    if(gameObject->getTipeObject()=="PRODUCT"){
        for(int i = 0; i < availableProduct.size(); i++){
            if (*gameObject == availableProduct[i].first){
                availableProduct[i].second += quantity;
                return;
            }
        }
    }
    else{
        for (int i = 0; i < availableBangunan.size(); i++){
            if (*gameObject == availableBangunan[i].first){
                availableBangunan[i].second += quantity;
                return;
            }
        }
    }
}

bool Toko::isProductEmptyStock(){
    for(int i = 0; i < ParserProduk::getConfigSize();i++){
        if (availableProduct[i].second != 0){
            return false;
        }
    }
    return true;
}

bool Toko::isBangunanEmptyStock(){
    for(int i = 0; i < ParserResep::getConfigSize();i++){
        if (availableBangunan[i].second != 0){
            return false;
        }
    }
    return true;
}

void Toko::displayAvailableHewan(){
    int idx = 1;
    cout << "Pilihan Hewan yang dapat dibeli :" << endl;
    for (int i = 0; i < ParserHewan::getConfigSize(); i++){
        cout << idx << ". " << availableHewan[i].getName();
        cout << " - " << availableHewan[i].getPrice() << endl;
        idx++;
    }
    cout << idx << ". Cancel" << endl;
}

void Toko::displayAvailableTanaman(){
    int idx = 1;
    cout << "Pilihan Tanaman yang dapat dibeli :" << endl;
    for (int i = 0; i < ParserTanaman::getConfigSize(); i++){
        cout << idx << ". " << availableTanaman[i].getName();
        cout << " - " << availableTanaman[i].getPrice() << endl;
        idx++;
    }
    cout << idx << ". Cancel" << endl;
}

int Toko::displayAvailableProduct(){
    int idx = 1;
    cout << "Pilihan Produk yang dapat dibeli :" << endl;
    for (int i = 0; i < ParserProduk::getConfigSize(); i++){
        if (availableProduct[i].second != 0){
            cout << idx << ". " << availableProduct[i].first.getName();
            cout << " - " << availableProduct[i].first.getPrice() <<
                " ("<<availableProduct[i].second<<")"<<endl;
            idx++;
        }
    }
    cout << idx << ". Cancel" << endl;
    return idx - 1;
}

int Toko::displayAvailableBangunan(){
    int idx = 1;
    cout << "Pilihan Bangunan yang dapat dibeli :" << endl;
    for (int i = 0; i < ParserResep::getConfigSize(); i++){
        if (availableBangunan[i].second != 0){
            cout << idx << ". " << availableBangunan[i].first.getName();
            cout << " - " << availableBangunan[i].first.getPrice();
            cout << " (" << availableBangunan[i].second << ")" << endl;
            idx++;
        }
    }
    cout << idx << ". Cancel" << endl;
    return idx - 1;
}
void Toko::displayResepBangunan(){
    int idx = 1;
    for (int i = 0; i < ParserResep::getConfigSize(); i++){
        cout << idx << ". " << availableBangunan[i].first.getName();
        cout << " - " << availableBangunan[i].first.getPrice();
        cout << " (" << availableBangunan[i].second << ")" << endl;
        idx++;
    }
}

int Toko::getStock(string name){
    for(int i = 0; i < availableHewan.size(); i++){
        if (name == availableHewan[i].getName()){
            return -1;
        }
    }
    for(int i = 0; i < availableTanaman.size(); i++){
        if (name == availableTanaman[i].getName()){
            return -1;
        }
    }
    for(int i = 0; i < availableProduct.size(); i++){
        if (name == availableProduct[i].first.getName()){
            return availableProduct[i].second;
        }
    }
    for(int i = 0; i < availableBangunan.size(); i++){
        if (name == availableBangunan[i].first.getName()){
            return availableBangunan[i].second;
        }
    }
    return 0;
}

int Toko::getAvailableProductSize(){
    return availableProduct.size();
}

int Toko::getAvailableBangunanSize(){
    return availableBangunan.size();
}

int Toko::getAvailableHewanSize(){
    return availableHewan.size();
}

int Toko::getAvailableTanamanSize(){
    return availableTanaman.size();
}

pair<Product,int>* Toko::getPairProductInt(int idx){
    return &availableProduct[idx];
}
pair<Bangunan,int>* Toko::getPairBangunanInt(int idx){
    return &availableBangunan[idx];
}

Hewan* Toko::getHewan(int idx){
    return &availableHewan[idx];
}

Tanaman* Toko::getTanaman(int idx){
    return &availableTanaman[idx];
}

int Toko::getTotalReady(){
    int sum = 0;
    for(int i=0;i<getAvailableProductSize();i++){
        if(getPairProductInt(i)->second!=0){
            sum++;
        }
    }
    for(int i=0;i<getAvailableBangunanSize();i++){
        if(getPairBangunanInt(i)->second!=0){
            sum++;
        }
    }
    return sum;
}