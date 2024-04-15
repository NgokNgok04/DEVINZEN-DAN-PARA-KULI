#include <iostream>
#include <vector>
#include "../Header/walikota.hpp"
#include "../Header/pemain.hpp"
using namespace std;

WaliKota::WaliKota() : Pemain()
{
    this->tipe = "walikota";
    this->username = "Walikota";
}

WaliKota::WaliKota(string usn, float guld, int bb, int smol, int med, int big) : Pemain(usn, guld, bb, smol, med, big)
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

void WaliKota::pungutPajak(vector<Pemain *> allPlayers)
{
    // Butuh track semua player
    float gained = 0;
    for (int i = 0; i < allPlayers.size(); i++)
    {
        if (allPlayers[i]->getTipe() == "petani" || allPlayers[i]->getTipe() == "peternak")
        {
            gained += allPlayers[i]->calculateTax();
        }
    }
    this->gulden += gained;
}

void WaliKota::beli()
{
    std::cout << endl
         << endl;
    

    GameObject *itemToBuy = nullptr;
    bool isSubMenuCancelled = false;
    int wantToBuy;
    while(!isSubMenuCancelled){
        wantToBuy = Toko::buyProcess();
        std::cout << "WANT TO BUY : " << wantToBuy << endl;
        std::cout << endl;
        try {
            if (wantToBuy == 0){
                std::cout << "Ditunggu Kedatangan Selanjutnya!!" << endl;
                isSubMenuCancelled = true;
            } else if (wantToBuy == -1){
                isSubMenuCancelled = true;
            } else {
                string subResponse;
                int validSubResponse;
                int counterAvailableItem;
                if (wantToBuy == 1){
                    cout << "masuk Hewan";
                    Toko::displayAvailableHewan();
                    std::cout << "Barang yang ingin dibeli : ";
                    std::cin >> subResponse;

                    if (isAllDigits(subResponse)){
                        validSubResponse = stoi(subResponse);
                    } else {
                        throw InvalidSubResponse();
                    }

                    if (validSubResponse != Toko::availableHewan.size() + 1){
                        if (validSubResponse >= 1 && validSubResponse <= Toko::availableHewan.size()){
                            itemToBuy = &Toko::availableHewan[validSubResponse - 1];
                            isSubMenuCancelled = true;
                        } else {
                            throw InvalidSubResponse();
                        }
                    } else {
                        std::cout << endl; //cancel
                    }

                } else if (wantToBuy == 2){
                    cout << "Masuk Tanaman";
                    Toko::displayAvailableTanaman();
                    std::cout << "Barang yang ingin dibeli : ";
                    std::cin >> subResponse;

                    if (isAllDigits(subResponse)){
                        validSubResponse = stoi(subResponse);
                    } else {
                        throw InvalidSubResponse();
                    }

                    if (validSubResponse != Toko::availableTanaman.size() + 1){
                        if (validSubResponse >= 1 && validSubResponse <= Toko::availableTanaman.size()){
                            itemToBuy = &Toko::availableTanaman[validSubResponse - 1];
                            isSubMenuCancelled = true;
                        } else {
                            throw InvalidSubResponse();
                        }

                    } else {
                        std::cout << endl; //cancel
                    }
                } else if (wantToBuy == 3 && !Toko::isProductEmptyStock()){
                    counterAvailableItem = Toko::displayAvailableProduct();
                    std::cout << "Barang yang ingin dibeli : ";
                    std::cin >> subResponse;

                    if (isAllDigits(subResponse)){
                        validSubResponse = stoi(subResponse);
                    } else {
                        throw InvalidSubResponse();
                    }

                    if (validSubResponse != counterAvailableItem + 1){
                        if (validSubResponse >= 1 && validSubResponse <= counterAvailableItem){
                            int count = 0;
                            bool found = false;
                            for (int i = 0; i < Toko::availableProduct.size(); i++){
                                if (Toko::availableProduct[i].second != 0){
                                    count++;
                                }
                                if (validSubResponse == count && !found){
                                    itemToBuy = &Toko::availableProduct[i].first;
                                    // itemToBuy = &Toko::availableProduct[count].first;
                                    found = true;
                                    isSubMenuCancelled = true;
                                }
                            }
                        } else{
                            throw InvalidSubResponse(); //response < 0 atau > seharusnya
                        }
                    } else {
                        std::cout << endl; //cancel
                    }
                } else if (wantToBuy == 3 && Toko::isProductEmptyStock() && !Toko::isBangunanEmptyStock()){
                    throw CantBuyBangunan();
                } else if (wantToBuy == 4 && !Toko::isBangunanEmptyStock()){
                    throw CantBuyBangunan();
                }
            }
        
        } catch (BaseException& err){
            std::cout << err.what();
            std::cout << endl << endl;
        }
    }

    if (itemToBuy != nullptr){
        std::cout << endl
                  << "Uang Anda : " << this->gulden << endl;
        this->inventory.displayRemainderSlot();
        std::cout << endl;

        string quantity;
        int validQuantity;

        try{
            std::cout << "Kuantitas : ";
            std::cin >> quantity;
            if (isAllDigits(quantity)){
                validQuantity = stoi(quantity);
                if (validQuantity == 0) {
                    throw InvalidSubResponse();
                }
            } else {
                throw InvalidSubResponse();
            }

            this->gulden -= itemToBuy->getPrice() * validQuantity;
            if (validQuantity > this->inventory.getEmptySlot()){
                this->gulden += itemToBuy->getPrice() * validQuantity;
                throw InventoryNotEnough();
            }
            int stock = Toko::getStock(itemToBuy->getName());
            if (stock != -1 && stock < validQuantity){
                this->gulden += itemToBuy->getPrice() * validQuantity;
                throw StockTokoNotEnough();
            }
            if (this->gulden < 0){
                this->gulden += itemToBuy->getPrice() * validQuantity;
                throw NotEnoughGulden();
            }
            std::cout << endl;
            std::cout << "Selamat Anda berhasil membeli " << validQuantity << " " << itemToBuy->getName();
            std::cout << ". Uang yang tersisa " << this->gulden << "." << endl
                << endl;
                
            std::cout << "Pilih slot untuk menyimpan barang yang anda beli!" << endl;
            this->inventory.displayObject();
            string slot;
            bool isValid = false;
            for (int i = 0; i < validQuantity; i++){
                isValid = false;
                while(!isValid){
                    try {
                        std::cout << "Petak slot " << i + 1 << ": ";
                        std::cin >> slot;
                        pair<int, int> position;
                        position = this->inventory.getPositionFromSlot(slot);
                        if (this->inventory.getElement(position.first,position.second) != nullptr){
                            throw SlotFilled();
                        }

                        this->inventory.setElement(position.first, position.second, itemToBuy);
                        isValid = true;
                    } catch (BaseException& err){
                        cout << err.what();
                        cout << endl;
                    }
                }
            }
            std::cout << itemToBuy->getName() << " berhasil disimpan dalam penyimpanan!" << endl;
            Toko::itemDibeli(itemToBuy, validQuantity);
        }
        catch (BaseException& err)
        {
            std::cout << err.what();
            std::cout << endl;
        }
     }
        
    
}

void WaliKota::jual()
{
    try
    {
        std::cout << "Berikut merupakan penyimpanan Anda" << endl;
        this->inventory.displayObject();
        string quantity;
        int quantityint;
        std::cout << "Masukkan kuantitas barang yang ingin dijual : ";
        std::cin >> quantity;
        std::cout << endl;
        if (!isAllDigits(quantity))
        {
            throw InvalidPanenIdx();
        }
        else
        {
            quantityint = std::stoi(quantity);
            if ((quantityint - this->ownedBangunan.size()) > ((this->inventory.getCols() * this->inventory.getRows()) - this->inventory.getEmptySlot()))
            {
                throw ItemQuantityToSellNotEnough();
            }
        }

        std::cout << endl
             << "Silahkan pilih petak yang ingin anda jual!"
             << endl;
        string slot;
        pair<int, int> position;
        int profit = 0;
        GameObject *itemToSell;
        bool isValid;
        for (int i = 0; i < quantityint; i++)
        {
            isValid = false;
            while (!isValid)
            {
                std::cout << "Petak slot " << i + 1 << ": ";
                std::cin >> slot;
                std::cout << endl;

                int idx1 = slot[0] - 'A' + 1;
                int idx2 = std::stoi(slot.substr(1));
                try
                {
                    if (slot.length() != 3)
                    {
                        throw InvalidIndexMatrixArea();
                    }
                    else if (idx2 > this->inventory.getRows() || idx1 > this->inventory.getCols())
                    {
                        throw InvalidIndexMatrixArea();
                    }
                    else
                    {
                        if (this->inventory.getElement(idx2, idx1) != nullptr)
                        {
                            isValid = true;
                        }
                        else
                        {
                            throw InvalidEmptySlot();
                        }
                    }
                }
                catch (BaseException &e)
                {
                    std::cout << e.what() << endl;
                }
            }
            int idx1 = slot[0] - 'A' + 1;
            int idx2 = std::stoi(slot.substr(1));
            profit += this->inventory.getElement(idx2, idx1)->getPrice();
            cout << this->inventory.getElement(idx2, idx1)->getPrice() << endl;
            Toko::itemDijual(this->inventory.getElement(idx2, idx1), 1);
            this->inventory.deleteElement(idx2, idx1);
        }
        this->gulden += profit;
        cout << this->gulden << ' ' << profit << endl;
        cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << profit << " gulden!" << endl;
    }
    catch (BaseException &e)
    {
        std::cout << e.what() << endl;
    }
}

void WaliKota::bangunBangunan()
{
    std::cout << "Resep Bangunan yang ada sebagai berikut: " << endl;
    for (int i = 0; i < Toko::availableBangunan.size(); i++)
    {
        std::cout << "    ";
        std::cout << i + 1 << ". " << Toko::availableBangunan[i].first.getName();
        std::cout << " (";
        std::cout << Toko::availableBangunan[i].first.getPrice() << " gulden, ";
        for (int j = 0; j < ParserResep::getRecipeMaterialQuantity(i + 1).size(); i++)
        {
            std::cout << ParserResep::getRecipeMaterialQuantity(i + 1)[j].first;
            std::cout << " ";
            std::cout << ParserResep::getRecipeMaterialQuantity(i + 1)[j].second;
            if (j != ParserResep::getRecipeMaterialQuantity(i + 1).size() - 1)
            {
                std::cout << ",";
            }
            std::cout << " ";
        }
        std::cout << ")" << endl;
    }
    string bangunanToBuy;
    std::cout << "Bangunan yang ingin dibangun: ";
    std::cin >> bangunanToBuy;

    int idxToBuy = 0;
    bool found = false;
    for (int i = 0; i < Toko::availableBangunan.size(); i++)
    {
        if (Toko::availableBangunan[i].first.getName() == bangunanToBuy)
        {
            idxToBuy = i;
            found = true;
        }
    }

    try
    {
        if (!found)
        {
            throw CantFindNamaBangunan();
        }
        int idRecipe = ParserResep::convertNameToID(Toko::availableBangunan[idxToBuy].first.getName());
        vector<pair<string, int>> materialToBuild = ParserResep::getRecipeMaterialQuantity(idRecipe);
        string materialToFind;
        int counterMaterial;
        for (int i = 0; i < materialToBuild.size(); i++)
        {
            materialToFind = materialToBuild[i].first;
            counterMaterial = this->inventory.countSameName(materialToFind);
            if (counterMaterial < materialToBuild[i].second)
            {
                throw MaterialNotEnough();
            }
        }
    }
    catch (CantFindNamaBangunan err)
    {
        err.what();
        std::cout << endl;
    }
    catch (MaterialNotEnough err)
    {
        err.what();
        std::cout << endl;
    }

    this->ownedBangunan.push_back(Toko::availableBangunan[idxToBuy].first);
    std::cout << Toko::availableBangunan[idxToBuy].first.getName() << "berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
}

float WaliKota::calculateTax()
{
    return 0;
}