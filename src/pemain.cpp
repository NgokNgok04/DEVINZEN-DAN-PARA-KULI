#include <iostream>
#include <vector>
#include <string>
#include "pemain.hpp"
using namespace std;

Pemain::Pemain()
{
    this->gulden = 50;
    this->berat_badan = 40;
    MatrixArea<GameObject> inv(8, 8);
    this->inventory = inv;
    this->ownedBuild = {0, 0, 0};
}

Pemain::Pemain(int guld, int bb, int smol, int med, int big)
{
    this->gulden = guld;
    this->berat_badan = bb;
    MatrixArea<GameObject> inv(8, 8);
    this->inventory = inv;
    this->ownedBuild = {smol, med, big};
}

Pemain::Pemain(const Pemain &other) // not sure
{
    this->gulden = other.gulden;
    this->berat_badan = other.berat_badan;
    MatrixArea<GameObject> n(other.inventory);
    this->inventory = n;
    this->ownedBuild = other.ownedBuild;
}

Pemain::~Pemain()
{
    this->inventory.~MatrixArea();
}

string Pemain::getTipe()
{
    return this->tipe;
}

void Pemain::cetakPenyimpanan()
{
    this->inventory.displayObject();
    this->inventory.displayRemainderSlot();
}

void Pemain::makan()
{
    cout << "Pilih makanan dari penyimpanan" << endl;
    this->inventory.displayObject();
    cout << endl;
    bool isValid = false;
    string slot;
    while (!isValid)
    {
        cout << "Slot: ";
        cin >> slot;
        cout << endl;
    }
    pair<int, int> pos = this->inventory.getPositionFromSlot(slot);
    // this->berat_badan += this->inventory.getElement(pos.first,pos.second).getAddedWeight();
    this->inventory.deleteElement(pos.first, pos.second);
    cout << endl
         << endl;
    cout << "Dengan lahapnya, kamu memakan hidangan itu" << endl;
    cout << "Alhasil, berat badan kamu naik menjadi ";
}

void Pemain::beli(){
    cout << endl << endl;
    int wantToBuy = Toko::buyProcess();
    int subResponse;
    int counterAvailableItem;
    GameObject* itemToBuy;
    if (wantToBuy == 1){
        Toko::displayAvailableHewan();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != Toko::availableHewan.size() + 1){
            if (subResponse >= 1 && subResponse <= Toko::availableHewan.size()){
                Hewan itemToBuy = Toko::availableHewan[subResponse - 1];
            } else {
                // throw exception
                cout << "Input tidak valid" << endl; //sementara
            }
        }
    } else if (wantToBuy == 2){
        Toko::displayAvailableTanaman();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != Toko::availableTanaman.size() + 1){
            if (subResponse >= 1 && subResponse <= Toko::availableTanaman.size()){
                Tanaman itemToBuy = Toko::availableTanaman[subResponse - 1];
            } else {
                // throw exception
                cout << "Input tidak valid" << endl; //sementara
            }
        }
    } else if (wantToBuy == 3 && !Toko::isProductEmptyStock()){
        counterAvailableItem = Toko::displayAvailableProduct();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != counterAvailableItem + 1){
            if (subResponse >= 1 && subResponse <= counterAvailableItem){
                int count = 0;
                for(int i = 0; i < Toko::availableProduct.size(); i++){
                    if (Toko::availableProduct[i].second != 0){
                        count++;
                    }
                    if (subResponse == count){
                        Product itemToBuy = Toko::availableProduct[count].first;
                    }
                }
            } else {
                // throw exception
                cout << "Input tidak valid" << endl; //sementara
            }
        }
    } else if (wantToBuy == 3 && !Toko::isBangunanEmptyStock() && Toko::isProductEmptyStock()){
        counterAvailableItem = Toko::displayAvailableBangunan();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != counterAvailableItem + 1){
            if (subResponse >= 1 && subResponse <= counterAvailableItem){
                int count = 0;
                for(int i = 0; i < Toko::availableBangunan.size(); i++){
                    if (Toko::availableBangunan[i].second != 0){
                        count++;
                    }
                    if (subResponse == count){
                        Bangunan itemToBuy = Toko::availableBangunan[count].first;
                    }
                }
            } else {
                // throw exception
                cout << "Input tidak valid" << endl; //sementara
            }
        }
    } else if (wantToBuy == 4 && !Toko::isBangunanEmptyStock){
        counterAvailableItem = Toko::displayAvailableBangunan();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != counterAvailableItem + 1){
            if (subResponse >= 1 && subResponse <= counterAvailableItem){
                int count = 0;
                for(int i = 0; i < Toko::availableBangunan.size(); i++){
                    if (Toko::availableBangunan[i].second != 0){
                        count++;
                    }
                    if (subResponse == count){
                        Bangunan itemToBuy = Toko::availableBangunan[count].first;
                    }
                }
            } else {
                // throw exception
                cout << "Input tidak valid" << endl; //sementara
            }
        }
    }
    cout << endl;
    cout << "Uang Anda : " << this->gulden << endl;
    this->inventory.displayRemainderSlot();
    cout << endl;

    int quantity;
    cout << "Kuantitas : "; //asumsi valid (nanti exception)
    cin >> quantity;
    
    this->gulden -= itemToBuy->getPrice()*quantity; 
    //pembelian tidak valid
        //stock toko ga cukup
        //inventory pemain ga cukup
        //duit pemain ga cukup
    //pembelian valid
    cout << endl;
    cout << "Selamat Anda berhasil membeli " << quantity <<" " << itemToBuy->getName();
    cout << ". Uang yang tersisa " << this->gulden << "." << endl << endl;
    
    cout << "Pilih slot untuk menyimpan barang yang anda beli!" << endl;
    this->inventory.displayObject();
    string slot;
    vector<string> availSlot;
    for(int i = 0; i < quantity; i++){
        cout << "Petak slot " << i + 1 <<": ";
        cin >> slot; //validasi dulu
        availSlot.push_back(slot);
    }
    pair<int,int> position;
    for (int i = 0; i < availSlot.size(); i++){
        position = this->inventory.getPositionFromSlot(availSlot[i]);
        this->inventory.setElement(position.first, position.second, itemToBuy);
    }
    cout << itemToBuy->getName() << "berhasil disimpan dalam penyimpanan!" << endl;
    
    Toko::itemDibeli(itemToBuy,quantity);
}

void Pemain::jual(){
    cout << "Berikut merupakan penyimpanan anda" << endl;
    this->inventory.displayObject();
    int quantity;
    cout << "Masukkan kuantitas barang yang ingin dijual :";
    cin >> quantity;
    cout << endl <<"Silahkan pilih petak yang ingin anda jual!";
    string slot;
    pair<int,int> position;
    int profit = 0;
    GameObject* itemToSell;
    for(int i = 0; i < quantity; i++){
        cout << "Petak slot " << i + 1 <<": ";
        cin >> slot; //validasi dulu
        position = this->inventory.getPositionFromSlot(slot);
        itemToSell = this->inventory.getElement(position.first,position.second);
        profit += itemToSell->getPrice();
        this->inventory.deleteElement(position.first,position.second);
    }
    this->gulden += profit;
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << profit << " gulden!" << endl;
    Toko::itemDijual(itemToSell,quantity);
void Pemain::setInv(int rows, int cols, GameObject a)
{
    this->inventory.setElement(rows, cols, &a);
}