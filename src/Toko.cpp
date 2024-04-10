#include <iostream>
#include <vector>
#include <string>
#include "Toko.hpp"
using namespace std;

Toko::Toko(){};

void Toko::displayAvailableItemToBuy(){
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat anda Beli :" << endl;
    for (int i = 0; i < this->availableItem.size(); i++){
        cout << i + 1 << ". " << KodeHurufToNama(this->availableItem[i].first);
        cout << " - " << KodeHurufToPrice(this->availableItem[i].first);
        cout << " (" << this->availableItem[i].second << ")" << endl; 
    }
}