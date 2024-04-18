#include <iostream>
#include <vector>
#include "../Header/walikota.hpp"
#include "../Header/pemain.hpp"
using namespace std;

WaliKota::WaliKota() : Pemain()
{
    this->tipe = "Walikota";
    this->username = "Walikota";
}

WaliKota::WaliKota(string usn, float guld, int bb) : Pemain(usn, guld, bb)
{
    this->tipe = "Walikota";
}

WaliKota::WaliKota(const WaliKota &other) : Pemain(other)
{
    this->tipe = "Walikota";
}

WaliKota::~WaliKota()
{
    this->inventory.~MatrixArea();
}

void WaliKota::pungutPajak(vector<Pemain *> allPlayers)
{
    
    float gained = 0;
    int sizePlayer = allPlayers.size();
    cout<<"Berikut adalah detil dari pemungutan pajak: "<<endl;
    for(int i=0;i<sizePlayer;i++){
        if(allPlayers[i]->getTipe()=="Walikota"){
            continue;
        }
        cout<<allPlayers[i]->getTipe();
        cout<<allPlayers[i]->getUsername()<<" - "<<allPlayers[i]->getTipe()<<": ";
        float paid = allPlayers[i]->calculateTax();
        cout<<paid<<" gulden"<<endl;
        gained += paid;
    }
    this->gulden += gained;
    cout << "Walikota sekarang mempunyai " << this->getGulden() << " gulden!" << endl;
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

                    if (validSubResponse != Toko::getAvailableHewanSize() + 1){
                        if (validSubResponse >= 1 && validSubResponse <= Toko::getAvailableHewanSize()){
                            itemToBuy = Toko::getHewan(validSubResponse - 1);
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

                    if (validSubResponse != Toko::getAvailableTanamanSize()+ 1){
                        if (validSubResponse >= 1 && validSubResponse <= Toko::getAvailableTanamanSize()){
                            itemToBuy = Toko::getTanaman(validSubResponse - 1);
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
                            for (int i = 0; i < Toko::getAvailableProductSize(); i++){
                                if (Toko::getPairProductInt(i)->second != 0){
                                    count++;
                                }
                                if (validSubResponse == count && !found){
                                    itemToBuy = &Toko::getPairProductInt(i)->first;
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
                        if(slot.length()!=3){
                            throw InvalidIndexMatrixArea();
                        }
                        if(isAllDigits(slot.substr(0,1))){
                            throw InvalidIndexMatrixArea();
                        }
                        if(!isAllDigits(slot.substr(1,2))){
                            throw InvalidIndexMatrixArea();
                        }
                        pair<int, int> position=this->inventory.getPositionFromSlot(slot);
                        if(position.first>inventory.getRows() || position.second>inventory.getCols()){
                            throw InvalidIndexMatrixArea();
                        }
                        if (this->inventory.getElement(position.first, position.second) != nullptr)
                        {
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
                    if(isAllDigits(slot.substr(0,1))){
                        throw InvalidIndexMatrixArea();
                    }
                    if(!isAllDigits(slot.substr(1,2))){
                        throw InvalidIndexMatrixArea();
                    }
                    int idx1 = slot[0] - 'A' + 1;
                    int idx2 = std::stoi(slot.substr(1));
                    if (idx2 > this->inventory.getRows() || idx1 > this->inventory.getCols())
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
    for (int i = 0; i < Toko::getAvailableBangunanSize(); i++)
    {
        std::cout << "    ";
        std::cout << i + 1 << ". " << Toko::getPairBangunanInt(i)->first.getName();
        std::cout << " (";
        // std::cout << Toko::getPairBangunanInt(i)->first.getPrice() << " gulden, ";
        for (int j = 0; j < ParserResep::getRecipeMaterialQuantity(i + 1).size(); j++)
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
    for (int i = 0; i < Toko::getAvailableBangunanSize(); i++)
    {
        if (Toko::getPairBangunanInt(i)->first.getName() == bangunanToBuy)
        {
            idxToBuy = i;
            found = true;
            break;
        }
    }
    Bangunan *bangunan = nullptr;
    try
    {
        if (!found)
        {
            throw CantFindNamaBangunan();
        }
        int idRecipe = ParserResep::convertNameToID(Toko::getPairBangunanInt(idxToBuy)->first.getName());
        vector<pair<string, int>> materialToBuild = ParserResep::getRecipeMaterialQuantity(idRecipe);
        string materialToFind;
        int counterMaterial;
        vector<pair<string,int>> materialKurang;
        for (int i = 0; i < materialToBuild.size(); i++)
        {
            materialToFind = materialToBuild[i].first;
            counterMaterial = this->inventory.countSameName(materialToFind);
            if(counterMaterial<materialToBuild[i].second){
                materialKurang.push_back(make_pair(materialToFind,materialToBuild[i].second-counterMaterial));
            }
        }
        if(!materialKurang.empty()){
            throw MaterialNotEnough(materialKurang);
        }
        bangunan = new Bangunan(idRecipe);
        for(int i=0;i<materialToBuild.size();i++){
            materialToFind = materialToBuild[i].first;
            counterMaterial = materialToBuild[i].second;
            for(int j=1;j<=inventory.getRows();j++){
                for(int k=1;k<=inventory.getCols();k++){
                    if(inventory.getElement(j,k)==nullptr){
                        continue;
                    }
                    if(inventory.getElement(j,k)->getTipeObject()=="PRODUCT"){
                        if(inventory.getElement(j,k)->getName()==materialToFind){
                            GameObject* temp = inventory.getElement(j,k);
                            inventory.setElement(j,k,nullptr);
                            delete temp;
                            counterMaterial--;
                            if(counterMaterial==0){
                                break;
                            }
                        }
                    }
                }
                if(counterMaterial==0){
                    break;
                }
            }
        }
    }
    catch (CantFindNamaBangunan err)
    {
        std::cout <<err.what()<<endl;
        return;
    }
    catch (MaterialNotEnough err)
    {
        std::cout <<err.what()<< endl;
        return;
    }
    this->ownedBangunan.push_back(*bangunan);
    GameObject* temp = dynamic_cast<GameObject*>(bangunan);
    inventory+(temp);
    std::cout << Toko::getPairBangunanInt(idxToBuy)->first.getName() << "berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
}

float WaliKota::calculateTax()
{
    return 0;
}

void WaliKota::tambahPemain(vector<Pemain *> &allPlayers, int &playerAmount, int& currentPlayerIndex, Pemain* currentPlayer){
    try{
        if (this->gulden < 50){
            throw NotEnoughGulden();
        }

        string tipePemain;
        cout << "Masukkan jenis pemain: ";
        cin >> tipePemain;
        
        if (tipePemain != "petani" && tipePemain != "peternak"){
            throw InvalidTypePemain();
        }

        string namaPemain;
        cout << "Masukkan nama pemain: ";
        
        cin >> namaPemain;
        bool found = false;

        for(int i = 0; i < allPlayers.size(); i++){
            if (namaPemain == allPlayers[i]->getUsername()){
                found = true;
            }
        }

        if (found){
            throw UserNamePemainTidakUnik();
        }

        if (tipePemain == "petani"){
            Petani * newPetani = new Petani(namaPemain,50,40);
            allPlayers.push_back(newPetani);
            playerAmount++;
            if (playerAmount > 1)
            { // geser pemain yang baru dimasukkan supaya terurut otomatis
                Pemain *P1 = nullptr;
                Pemain *P2 = nullptr;
                int i = playerAmount - 1;
                while (i - 1 >= 0)
                {
                    P1 = allPlayers[i];
                    P2 = allPlayers[i - 1];

                    if (*P1 < *P2)
                    {
                        allPlayers[i] = P2;
                        allPlayers[i - 1] = P1;
                    }
                    else
                    {
                        break;
                    }
                    i--;
                }
            }
            if(allPlayers[currentPlayerIndex]->getUsername() != currentPlayer->getUsername()){ //kalo pemain sekarang bergeser posisinya
                currentPlayerIndex++; //pindah indeks pemain sekarang dengan 1
            }
        } else if (tipePemain == "peternak"){
            Peternak * newPeternak = new Peternak(namaPemain,50,40);
            allPlayers.push_back(newPeternak);
            playerAmount++;
            if (playerAmount > 1)
            { // geser pemain yang baru dimasukkan supaya terurut otomatis
                Pemain *P1 = nullptr;
                Pemain *P2 = nullptr;
                int i = playerAmount - 1;
                while (i - 1 >= 0)
                {
                    P1 = allPlayers[i];
                    P2 = allPlayers[i - 1];

                    if (*P1 < *P2)
                    {
                        allPlayers[i] = P2;
                        allPlayers[i - 1] = P1;
                    }
                    else
                    {
                        break;
                    }
                    i--;
                }
            }

            if(allPlayers[currentPlayerIndex]->getUsername() != currentPlayer->getUsername()){ //kalo pemain sekarang bergeser posisinya
                currentPlayerIndex++; //pindah indeks pemain sekarang dengan 1
            }
        } else {
            throw InvalidTypePemain();
        }

        this->gulden -= 50;
        cout << endl << "Pemain baru ditambahkan!" << endl;
        cout << "Selamat datang "<< namaPemain << " di kota ini!" << endl; 

    } catch (BaseException& err){
        cout << err.what();
        cout << endl;
    }
}