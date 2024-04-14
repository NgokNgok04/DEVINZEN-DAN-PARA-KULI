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
    if (this->inventory.isEmpty()){
        throw EmptyInventory();
    }

    bool foundEatable = false;
    Product * itemInSearch;
    for(int i = 0; i < this->inventory.getRows(); i++){
        for(int j = 0; j < this->inventory.getCols(); j++){
            if (this->inventory.getElement(i+1,j+1) != nullptr && this->inventory.getElement(i+1,j+1)->getTipeObject() == "PRODUCT"){
                itemInSearch = dynamic_cast<Product*>(this->inventory.getElement(i+1,j+1));
                if (itemInSearch->getAddedWeight() != 0){
                    foundEatable = true;
                    break;
                }
            }

        }
        if (foundEatable){
            break;
        }
    }
    if (!foundEatable){
        throw NoFoodInInventory();
    }
    cout << "Pilih makanan dari penyimpanan" << endl;
    this->inventory.displayObject();
    cout << endl;

    string slot;
    cout << "Slot: ";
    cin >> slot;
    pair<int, int> pos;
    bool isValid = false;
    while (!isValid){
        try{
            pos = this->inventory.getPositionFromSlot(slot);
            if (this->inventory.getElement(pos.first,pos.second) == nullptr){
                throw EmptyFoodSlot();
            }
            bool found = false;
            for(int i = 0; i < Toko::availableProduct.size();i++){
                if (*this->inventory.getElement(pos.first,pos.second) == Toko::availableProduct[i].first){
                    found = true;
                }
            }
            if (!found){
                throw NotEatableSlot();
            }

            if (this->inventory.getElement(pos.first,pos.second)->getTipeObject() != "PRODUCT"){
                throw NotEatableSlot();
            } else {
                Product* itemToEat = dynamic_cast<Product*>(this->inventory.getElement(pos.first, pos.second));
                if (itemToEat->getAddedWeight() == 0){
                    throw NotEatableSlot();
                }
            }

            this->inventory.deleteElement(pos.first, pos.second);
            cout << endl
                 << endl;
            cout << "Dengan lahapnya, kamu memakan hidangan itu" << endl;
            cout << "Alhasil, berat badan kamu naik menjadi ";
            isValid = true;

        } catch (InvalidResponseToko err){
            err.what();
        } catch (EmptyFoodSlot err){
            cout << endl << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
        } catch (NotEatableSlot err){
            cout << endl << "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!" << endl;
        }
    }
}

void Pemain::setInv(int rows, int cols, GameObject a){
    this->inventory.setElement(rows, cols, &a);
}