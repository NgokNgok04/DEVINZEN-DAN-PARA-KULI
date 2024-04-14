#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "walikota.hpp"
using namespace std;

WaliKota::WaliKota() : Pemain()
{
    this->tipe = "walikota";
}

WaliKota::WaliKota(int guld, int bb, int smol, int med, int big) : Pemain(guld, bb, smol, med, big)
{
    this->tipe = "walikota";
}

WaliKota::WaliKota(const WaliKota &other) : Pemain(other)
{
    this->tipe = "walikota";
}

WaliKota::~WaliKota()
{
    this->inventory.~MatrixArea();
}

void WaliKota::pungutPajak()
{
    // Butuh track semua player
}

void WaliKota::bangunBangunan(int)
{
    // Butuh config bangunan
}

void WaliKota::beli()
{
    cout << endl << endl;
    int wantToBuy = Toko::buyProcess();
    int subResponse;
    int counterAvailableItem;
    GameObject* itemToBuy = nullptr;
    if (wantToBuy == 1){
        Toko::displayAvailableHewan();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != Toko::availableHewan.size() + 1){
            if (subResponse >= 1 && subResponse<= Toko::availableHewan.size()){
                itemToBuy = &Toko::availableHewan[subResponse - 1];
            } else {
                //throw exception
                cout << "Input tidak valid" << endl;
            }
        }
    } else if (wantToBuy == 2){
        Toko::displayAvailableTanaman();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != Toko::availableTanaman.size() + 1){
            if (subResponse >= 1 && subResponse<= Toko::availableTanaman.size()){
                itemToBuy = &Toko::availableTanaman[subResponse - 1];
            } else {
                //throw exception
                cout << "Input tidak valid" << endl;
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
                        itemToBuy = &Toko::availableProduct[count].first;
                    }
                }
            } else {
                // throw exception
                cout << "Input tidak valid" << endl; //sementara
            }
        }
    } else {
        //throw exception
        cout << "Input tidak valid!" << endl;
        //beli bangunan juga kena
    }

    if (itemToBuy != nullptr){
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
}
void WaliKota::jual()
{
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    this->inventory.displayObject();
    int quantity;
    cout << "Masukkan kuantitas barang yang ingin dijual :";
    cin >> quantity;
    cout << endl << "Silahkan pilih petak yang ingin anda jual!";
    string slot;
    pair<int,int> position;
    int profit = 0;
    GameObject* itemToSell;
    for(int i = 0; i < quantity; i++){
        cout << "Petak slot " << i + 1 << ": ";
        cin >> slot; //validasi dulu (gabisa jual bangunan)
        position = this->inventory.getPositionFromSlot(slot);
        itemToSell = this->inventory.getElement(position.first, position.second);
        profit += itemToSell->getPrice();
        this->inventory.deleteElement(position.first, position.second);
    }
    this->gulden += profit;
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << profit << " gulden!" << endl;
    Toko::itemDijual(itemToSell,quantity);
}

void WaliKota::bangunBangunan(){
    cout << "Resep Bangunan yang ada sebagai berikut: " << endl;
    for(int i = 0; i < Toko::availableBangunan.size(); i++){
        cout << "    ";
        cout << i + 1 << ". " <<Toko::availableBangunan[i].first.getName();
        cout << " (";
        cout << Toko::availableBangunan[i].first.getPrice() << " gulden, ";
        
    }
}