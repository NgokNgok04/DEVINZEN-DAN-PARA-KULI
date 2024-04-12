#include <iostream>
#include <vector>
#include <string>
#include "Toko.hpp"
using namespace std;

Toko::Toko(){
    int idDummyToko;
    for(int i = 0; i < ParserHewan::getConfigSize(); i++){
        idDummyToko = ParserHewan::getID(i);
        Hewan hewanDummyToko(i);
        availableHewan.push_back(make_pair(hewanDummyToko,-1));
    }

    for(int i = 0; i < ParserTanaman::getConfigSize(); i++){
        idDummyToko = ParserTanaman::getID(i);
        Tanaman tanamanDummyToko(i);
        availableTanaman.push_back(make_pair(tanamanDummyToko,-1));
    }

    for(int i = 0; i < ParserProduk::getConfigSize(); i++){
        idDummyToko = ParserProduk::getID(i);
        Product productDummyToko(i);
        availableProduct.push_back(make_pair(productDummyToko,0));
    }

    for(int i = 0; i < ParserResep::getConfigSize.; i++){
        idDummyToko = ParserResep::getID(i);
        Bangunan bangunanDummyToko(i);
        availableBangunan.push_back(make_pair(bangunanDummyToko,0));
    }
};

int Toko::buyProcess(){
    cout << "Selamat datang di toko!!" << endl;
    int response;
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
    cout << "Masukklah pilihan (1-4) :";
    cin >> response;
    if (response == i){
        return 0
    } else if (response >= 1 && response < i) {
        return response;
    } else {
        //thhrow exception
        cout << "Input tidak valid" << endl;
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
    for (int i = 0; i < ParserHewan::getConfigSize(); i++){
        cout << idx << ". " << availableHewan[i].getName();
        cout << " - " << availableHewan[i].getPrice() << endl;
        idx++;
    }
    cout << idx << ". Cancel" << endl;
}

void Toko::displayAvailableTanaman(){
    int idx = 1;
    for (int i = 0; i < ParserTanaman::getConfigSize(); i++){
        cout << idx << ". " << availableTanaman[i].getName();
        cout << " - " << availableTanaman[i].getPrice() << endl;
        idx++;
    }
    cout << idx << ". Cancel" << endl;
}

int Toko::displayAvailableProduct(){
    int idx = 1;
    for (int i = 0; i < ParserProduk::getConfigSize(); i++){
        if (availableProduct[i].second != 0){
            cout << idx << ". " << availableProduct[i].first.getName();
            cout << " - " << availableProduct[i].first.getPrice() << endl;
            idx++;
        }
    }
    cout << idx << ". Cancel" << endl;
    return idx - 1;
}

int Toko::displayAvailableBangunan(){
    int idx = 1;
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

        // int subResponse;
        // int counterAvailableItem;
        // cout << "Masukkan pilihan: ";
        // if (response == 1){
        //     displayAvailableHewan();
        //     cin >> subResponse;
        //     if (subResponse != availableHewan.size() + 1){
        //         if (subResponse >= 1 && subResponse <= availableHewan.size()){
        //             return availableHewan[subResponse - 1];
        //         } else {
        //             // throw exception
        //             cout << "Input tidak valid" << endl; //sementara
        //         }
        //     }
        // } else if (response == 2){
        //     displayAvailableTanaman();
        //     cin >> subResponse;
        //     if (subResponse != availableTanaman.size() + 1){
        //         if (subResponse >= 1 && subResponse <= availableTanaman.size()){
        //             return availableTanaman[subResponse - 1];
        //         } else {
        //             // throw exception
        //             cout << "Input tidak valid" << endl; //sementara
        //         }
        //     }
        // } else if (response == 3 && i >= 3 && !isProductEmptyStock()){
        //     counterAvailableItem = displayAvailableProduct();
        //     cin >> subResponse;
        //     if (subResponse != counterAvailableItem + 1){
        //         if (subResponse >= 1 && subResponse <= counterAvailableItem){
        //             int count = 0;
        //             for(int i = 0; i < availableProduct.size(); i++){
        //                 if (availableProduct[i].second != 0){
        //                     count++;
        //                 }
        //                 if (subResponse == count){
        //                     return availableProduct[count].first;
        //                 }
        //             }
        //         } else {
        //             // throw exception
        //             cout << "Input tidak valid" << endl; //sementara
        //         }
        //     }
        // } else if (response == 3 && i >= 3 && !isBangunanEmptyStock() && isProductEmptyStock()){
        //     counterAvailableItem = displayAvailableBangunan();
        //     cin >> subResponse;
        //     if (subResponse != counterAvailableItem + 1){
        //         if (subResponse >= 1 && subResponse <= counterAvailableItem){
        //             int count = 0;
        //             for(int i = 0; i < availableBangunan.size(); i++){
        //                 if (availableBangunan[i].second != 0){
        //                     count++;
        //                 }
        //                 if (subResponse == count){
        //                     return availableBangunan[count].first;
        //                 }
        //             }
        //         } else {
        //             // throw exception
        //             cout << "Input tidak valid" << endl; //sementara
        //         }
        //     }

        // } else if (response == 4 && !isBangunanEmptyStock){
        //     counterAvailableItem = displayAvailableBangunan();
        //     cin >> subResponse;
        //     if (subResponse != counterAvailableItem + 1){
        //         if (subResponse >= 1 && subResponse <= counterAvailableItem){
        //             int count = 0;
        //             for(int i = 0; i < availableBangunan.size(); i++){
        //                 if (availableBangunan[i].second != 0){
        //                     count++;
        //                 }
        //                 if (subResponse == count){
        //                     return availableBangunan[count].first;
        //                 }
        //             }
        //         } else {
        //             // throw exception
        //             cout << "Input tidak valid" << endl; //sementara
        //         }
        //     }