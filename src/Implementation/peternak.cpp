#include <iostream>
#include <vector>
#include "../Header/peternak.hpp"
#include "../Header/Product.hpp"
using namespace std;
// EXTRA FUNCTIONS
Peternak::Peternak() : Pemain()
{
    this->tipe = "Peternak";
    int farmRow = ParserMisc::getFarmSize().first;
    int farmCol = ParserMisc::getFarmSize().second;
    MatrixArea<Hewan> n(farmRow, farmCol);
    this->ternakan = n;
    this->username = "Peternak1";
}

Peternak::Peternak(string usn, float guld, int bb) : Pemain(usn, guld, bb)
{
    this->tipe = "Peternak";
    pair<int,int> sizePeternakan = ParserMisc::getFieldSize();
    MatrixArea<Hewan> n(sizePeternakan.first, sizePeternakan.second);
    this->ternakan = n;
}

Peternak::Peternak(const Peternak &other) : Pemain()
{
    this->tipe = "Peternak";
    MatrixArea<Hewan> n(other.ternakan);
    this->ternakan = n;
}

Peternak::~Peternak()
{
    this->inventory.~MatrixArea();
    this->ternakan.~MatrixArea();
}

MatrixArea<Hewan> &Peternak::getTernakan()
{
    return this->ternakan;
}

void Peternak::beli()
{
    std::cout << endl;
    GameObject *itemToBuy = nullptr;
    bool isSubMenuCancelled = false;
    int wantToBuy;
    while (!isSubMenuCancelled)
    {
        wantToBuy = Toko::buyProcess();
        std::cout << endl;
        try
        {
            if (wantToBuy == 0)
            {
                std::cout << "Ditunggu Kedatangan Selanjutnya!!" << endl;
                isSubMenuCancelled = true;
            }
            else if (wantToBuy == -1)
            {
                isSubMenuCancelled = true;
            }
            else
            {
                string subResponse;
                int validSubResponse;
                int counterAvailableItem;
                if (wantToBuy == 1)
                {
                    Toko::displayAvailableHewan();
                    std::cout << "Barang yang ingin dibeli : ";
                    std::cin >> subResponse;

                    if (isAllDigits(subResponse))
                    {
                        validSubResponse = stoi(subResponse);
                    }
                    else
                    {
                        throw InvalidSubResponse();
                    }

                    if (validSubResponse != Toko::getAvailableHewanSize() + 1)
                    {
                        if (validSubResponse >= 1 && validSubResponse <= Toko::getAvailableHewanSize())
                        {
                            itemToBuy = Toko::getHewan(validSubResponse - 1);
                            isSubMenuCancelled = true;
                        }
                        else
                        {
                            throw InvalidSubResponse();
                        }
                    }
                    else
                    {
                        std::cout << endl; // cancel
                    }
                }
                else if (wantToBuy == 2)
                {
                    Toko::displayAvailableTanaman();
                    std::cout << "Barang yang ingin dibeli : ";
                    std::cin >> subResponse;

                    if (isAllDigits(subResponse))
                    {
                        validSubResponse = stoi(subResponse);
                    }
                    else
                    {
                        throw InvalidSubResponse();
                    }

                    if (validSubResponse != Toko::getAvailableTanamanSize() + 1)
                    {
                        if (validSubResponse >= 1 && validSubResponse <= Toko::getAvailableTanamanSize())
                        {
                            itemToBuy = Toko::getTanaman(validSubResponse - 1);
                            isSubMenuCancelled = true;
                        }
                        else
                        {
                            throw InvalidSubResponse();
                        }
                    }
                    else
                    {
                        std::cout << endl; // cancel
                    }
                }
                else if (wantToBuy == 3 && !Toko::isProductEmptyStock())
                {
                    counterAvailableItem = Toko::displayAvailableProduct();
                    std::cout << "Barang yang ingin dibeli : ";
                    std::cin >> subResponse;

                    if (isAllDigits(subResponse))
                    {
                        validSubResponse = stoi(subResponse);
                    }
                    else
                    {
                        throw InvalidSubResponse();
                    }

                    if (validSubResponse != counterAvailableItem + 1)
                    {
                        if (validSubResponse >= 1 && validSubResponse <= counterAvailableItem)
                        {
                            int count = 0;
                            bool found = false;
                            for (int i = 0; i < Toko::getAvailableProductSize(); i++)
                            {
                                if (Toko::getPairProductInt(i)->second != 0)
                                {
                                    count++;
                                }
                                if (validSubResponse == count && !found)
                                {
                                    itemToBuy = &Toko::getPairProductInt(i)->first;
                                    // itemToBuy = &Toko::availableProduct[count].first;
                                    found = true;
                                    isSubMenuCancelled = true;
                                }
                            }
                        }
                        else
                        {
                            throw InvalidSubResponse(); // response < 0 atau > seharusnya
                        }
                    }
                    else
                    {
                        std::cout << endl; // cancel
                    }
                }
                else if (wantToBuy == 3 && !Toko::isBangunanEmptyStock() && Toko::isProductEmptyStock())
                {
                    counterAvailableItem = Toko::displayAvailableBangunan();
                    std::cout << "Barang yang ingin dibeli : ";
                    std::cin >> subResponse;

                    if (isAllDigits(subResponse))
                    {
                        validSubResponse = stoi(subResponse);
                    }
                    else
                    {
                        throw InvalidSubResponse();
                    }

                    if (validSubResponse != counterAvailableItem + 1)
                    {
                        if (validSubResponse >= 1 && validSubResponse <= counterAvailableItem)
                        {
                            int count = 0;
                            bool found = false;
                            for (int i = 0; i < Toko::getAvailableBangunanSize(); i++)
                            {
                                if (Toko::getPairBangunanInt(i)->second != 0)
                                {
                                    count++;
                                }
                                if (validSubResponse == count && !found)
                                {
                                    itemToBuy = &Toko::getPairBangunanInt(i)->first;
                                    // itemToBuy = &Toko::availableBangunan[count].first;
                                    this->ownedBangunan.push_back(Toko::getPairBangunanInt(count)->first);
                                    found = true;
                                    isSubMenuCancelled = true;
                                }
                            }
                        }
                        else
                        {
                            throw InvalidSubResponse();
                        }
                    }
                    else
                    {
                        std::cout << endl; // cancel
                    }
                }
                else if (wantToBuy == 4 && !Toko::isBangunanEmptyStock())
                {
                    counterAvailableItem = Toko::displayAvailableBangunan();
                    std::cout << "Barang yang ingin dibeli : ";
                    std::cin >> subResponse;

                    if (isAllDigits(subResponse))
                    {
                        validSubResponse = stoi(subResponse);
                    }
                    else
                    {
                        throw InvalidSubResponse();
                    }

                    if (validSubResponse != counterAvailableItem + 1)
                    {
                        if (validSubResponse >= 1 && validSubResponse <= counterAvailableItem)
                        {
                            int count = 0;
                            bool found = false;
                            for (int i = 0; i < Toko::getAvailableBangunanSize(); i++)
                            {
                                if (Toko::getPairBangunanInt(i)->second != 0)
                                {
                                    count++;
                                }
                                if (validSubResponse == count && !found)
                                {
                                    itemToBuy = &Toko::getPairBangunanInt(i)->first;
                                    // itemToBuy = &Toko::availableBangunan[count].first;
                                    this->ownedBangunan.push_back(Toko::getPairBangunanInt(count)->first);
                                    found = true;
                                    isSubMenuCancelled = true;
                                }
                            }
                        }
                        else
                        {
                            throw InvalidSubResponse();
                        }
                    }
                    else
                    {
                        std::cout << endl;
                    }
                }
            }
        }
        catch (BaseException &err)
        {
            cout << err.what();
            std::cout << endl
                      << endl;
        }
    }

    if (itemToBuy != nullptr)
    {
        std::cout << endl
                  << "Uang Anda : " << this->gulden << endl;
        this->inventory.displayRemainderSlot();
        std::cout << endl;

        string quantity;
        int validQuantity;

        try
        {
            std::cout << "Kuantitas : ";
            cin >> quantity;
            if (isAllDigits(quantity))
            {
                validQuantity = stoi(quantity);
                if (validQuantity == 0)
                {
                    throw InvalidSubResponse();
                }
            }
            else
            {
                throw InvalidSubResponse();
            }

            this->gulden -= itemToBuy->getPrice() * validQuantity;
            if (validQuantity > this->inventory.getEmptySlot())
            {
                this->gulden += itemToBuy->getPrice() * validQuantity;
                throw InventoryNotEnough();
            }
            int stock = Toko::getStock(itemToBuy->getName());
            if (stock != -1 && stock < validQuantity)
            {
                this->gulden += itemToBuy->getPrice() * validQuantity;
                throw StockTokoNotEnough();
            }
            if (this->gulden < 0)
            {
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
            for (int i = 0; i < validQuantity; i++)
            {
                isValid = false;
                while (!isValid)
                {
                    try
                    {
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
                    }
                    catch (BaseException &err)
                    {
                        cout << err.what();
                        cout << endl;
                    }
                }
            }
            std::cout << itemToBuy->getName() << " berhasil disimpan dalam penyimpanan!" << endl;
            Toko::itemDibeli(itemToBuy, validQuantity);
        }
        catch (BaseException &err)
        {
            std::cout << err.what();
            std::cout << endl;
        }
    }
}

void Peternak::jual()
{
    try
    {
        cout << "Berikut merupakan penyimpanan Anda" << endl;
        this->inventory.displayObject();
        string quantity;
        int quantityint;
        cout << "Masukkan kuantitas barang yang ingin dijual : ";
        cin >> quantity;
        cout << endl;
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

        cout << endl
             << "Silahkan pilih petak yang ingin anda jual!"
             << endl;
        string slot;
        pair<int, int> position;
        int profit = 0;
        GameObject *itemToSell;
        vector<GameObject *> validItemToSell;
        bool isValid;
        for (int i = 0; i < quantityint; i++)
        {
            isValid = false;
            while (!isValid)
            {
                cout << "Petak slot " << i + 1 << ": ";
                cin >> slot;
                cout << endl;

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
                    // position = this->inventory.getPositionFromSlot(slot);
                    else
                    {
                        if (this->inventory.getElement(idx2, idx1) != nullptr)
                        {
                            if (this->inventory.getElement(idx2, idx1)->getTipeObject() == "BANGUNAN")
                            {
                                throw CantSellBangunan();
                            }
                            else
                            {
                                isValid = true;
                            }
                        }
                        else
                        {
                            throw InvalidEmptySlot();
                        }
                    }
                }
                catch (BaseException &e)
                {
                    cout << e.what() << endl;
                }
            }
            int idx1 = slot[0] - 'A' + 1;
            int idx2 = std::stoi(slot.substr(1));

            itemToSell = this->inventory.getElement(idx2, idx1);
            validItemToSell.push_back(itemToSell);

            profit += this->inventory.getElement(idx2, idx1)->getPrice();
            Toko::itemDijual(inventory.getElement(idx2, idx1), 1);
            this->inventory.deleteElement(idx2, idx1);
        }
        this->gulden += profit;
        cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << profit << " gulden!" << endl;
    }
    catch (BaseException &e)
    {
        cout << e.what() << endl;
    }
}

void Peternak::cetakTernak()
{
    this->ternakan.displayObject();
    this->ternakan.displayRemainderSlot();
}

void Peternak::ternak()
{
    try{
    if (this->ternakan.getEmptySlot() == 0)
    {
        throw NoEmptySlot();
    }
    bool existAnimal = false;
            for (int a = 1; a < this->inventory.getRows(); a++)
            {
                for (int b = 1; b < this->inventory.getCols(); b++)
                {
                    if (this->inventory.getElement(a, b) != nullptr)
                    {
                        if (this->inventory.getElement(a, b)->getTipeObject() == "HEWAN")
                        {
                            existAnimal = true;
                        }
                    }
                }
            }
    if (!existAnimal)
    {
        throw NoAnimal();
    }
    else
    {
    cout << "Pilih hewan dari penyimpanan" << endl;
    this->cetakPenyimpanan();
    this->cetakTernak();

    bool isValid = false;
    string slot;
    while (!isValid)
    {
        cout << "Slot: ";
        cin >> slot;
        cout << endl;
        // Validasi
        int idx1 = slot[0] - 'A' + 1;
        int idx2 = std::stoi(slot.substr(1));
        try
        {
            this->cetakTernak();

            if (slot.length() != 3 && isAllDigits(slot.substr(1)))
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
                    if (this->inventory.getElement(idx2, idx1)->getTipeObject() != "HEWAN")
                    {
                        throw InvalidNotHewan();
                    }
                    else
                    {
                        isValid = true;
                    }
                }
                else
                {
                    throw InvalidEmptySlot();
                }
            }
        }
        catch (BaseException &e)
        {
            cout << e.what() << endl;
        }
    }

    int idx1 = slot[0] - 'A' + 1;
    int idx2 = std::stoi(slot.substr(1));

    cout << "Kamu memilih " << this->inventory.getElement(idx2, idx1)->getName() << endl; // Nama Objeknya
    cout << "Pilih petak tanah yang akan ditinggali" << endl;
    this->cetakTernak();

    isValid = false;
    string petak;
    while (!isValid)
    {
        cout << "Petak Tanah: ";
        cin >> petak;
        cout << endl;
        // Validasi
        int idx3 = petak[0] - 'A' + 1;
        int idx4 = std::stoi(petak.substr(1));
        try
        {
            if (petak.length() != 3 && isAllDigits(petak.substr(1)))
            {
                throw InvalidIndexMatrixArea();
            }
            else if (idx4 > this->ternakan.getRows() || idx3 > this->ternakan.getCols())
            {
                throw InvalidIndexMatrixArea();
            }
            else
            {
                if (this->ternakan.getElement(idx4, idx3) == nullptr)
                {

                    isValid = true;
                }
                else
                {
                    throw InvalidFilledSlot();
                }
            }
        }
        catch (BaseException &e)
        {
            cout << e.what() << endl;
        }
    }

    int idx3 = petak[0] - 'A' + 1;
    int idx4 = std::stoi(petak.substr(1));

    Hewan *temp = dynamic_cast<Hewan *>(this->inventory.getElement(idx2, idx1));

    this->ternakan.setElement(idx4, idx3, temp);
    this->inventory.deleteElement(idx2, idx1);
    cout << "Berhasil diternakkan" << endl;
    }
    } catch (BaseException &e)
    {
        cout << e.what() << endl;
    }
}

void Peternak::kasihMakan()
{
    try
    {
        if (this->ternakan.isEmpty())
        {
            throw NoAnimalInCage();
        }
        if(checkAllHerbiv() && !searchFood(false)){
            throw AllHerbivNoFood();
        }
        if(checkAllCarniv()&& !searchFood(true)){
            throw AllCarnivNoFood();
        }
        else
        {
            cout << "Pilih petak kandang yang akan diberi makan" << endl;
            this->cetakTernak();

            bool isValid = false;
            string slot;
            while (!isValid)
            {
                try
                {
                    cout << "Petak Ternakan: ";
                    cin >> slot;
                    cout << endl;
                    // Validasi
                    int idx1 = slot[0] - 'A' + 1;
                    int idx2 = std::stoi(slot.substr(1));
                    if (slot.length() != 3 && isAllDigits(slot.substr(1)))
                    {
                        throw InvalidIndexMatrixArea();
                    }
                    else if (idx1 > this->ternakan.getRows() || idx2 > this->ternakan.getCols())
                    {
                        throw InvalidIndexMatrixArea();
                    }
                    else
                    {
                        if (this->ternakan.getElement(idx2, idx1) != nullptr)
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
                    cout << e.what() << endl;
                }
            }

            int idx1 = slot[0] - 'A' + 1;
            int idx2 = std::stoi(slot.substr(1));
            cout << "Kamu memilih " << this->ternakan.getElement(idx2, idx1)->getName() << " untuk diberi makan" << endl;
            if(this->ternakan.getElement(idx2,idx1)->getType()=="CARNIVORE" && !searchFood(true)){
                throw NoFoodForCarniv();
            }
            if(this->ternakan.getElement(idx2,idx1)->getType()=="HERBIVORE" && !searchFood(false)){
                throw NoFoodForHerbiv();
            }
            cout << "Pilih pangan untuk diberikan: " << endl;
            this->cetakPenyimpanan();

            isValid = false;
            string slot2;
            while (!isValid)
            {
                try
                {
                    cout << "Slot: ";
                    cin >> slot2;
                    cout << endl;
                    // Validasi
                    int idx3 = slot2[0] - 'A' + 1;
                    int idx4 = std::stoi(slot2.substr(1));
                    if (slot2.length() != 3 && isAllDigits(slot2.substr(1)))
                    {
                        throw InvalidIndexMatrixArea();
                    }
                    else if (idx3 > this->inventory.getRows() || idx4 > this->inventory.getCols())
                    {
                        throw InvalidIndexMatrixArea();
                    }
                    else if (this->inventory.getElement(idx4, idx3) == nullptr)
                    {
                        throw InvalidEmptySlot();
                    }
                    else if (this->inventory.getElement(idx4, idx3)->getTipeObject() != "PRODUCT")
                    {
                        throw InvalidNotProduct();
                    }

                    else
                    {
                        Product *temp = dynamic_cast<Product *>(this->inventory.getElement(idx4, idx3));
                        if (this->ternakan.getElement(idx2, idx1)->getType() == "CARNIVORE")
                        {
                            if (temp->fromHewan())
                            {
                                isValid = true;
                            }
                            else
                            {
                                throw InvalidCarnivore();
                            }
                        }

                        else if (this->ternakan.getElement(idx2, idx1)->getType() == "HERBIVORE")
                        {
                            if (!temp->fromHewan())
                            {
                                isValid = true;
                            }
                            else
                            {
                                throw InvalidHerbivore();
                            }
                        }

                        else
                        {
                            isValid = true;
                        }
                    }
                }
                catch (BaseException &e)
                {
                    cout << e.what() << endl;
                }
            }

            int idx3 = slot2[0] - 'A' + 1;
            int idx4 = std::stoi(slot2.substr(1));
            Product *temp = dynamic_cast<Product *>(this->inventory.getElement(idx4, idx3));

            this->ternakan.getElement(idx2, idx1)->makan(*temp);
            this->inventory.deleteElement(idx4, idx3);
            cout << this->ternakan.getElement(idx2, idx1)->getName() << " sudah diberi makan dan beratnya menjadi " << this->ternakan.getElement(idx2, idx1)->getCurWeight() << endl;
        }
    }
    catch (BaseException &e)
    {
        cout << e.what() << endl;
    }
    // Output Hasil
}

void Peternak::panenTernak()
{
    try
    {
        if (this->ternakan.isEmpty())
        {
            throw NoHarvestableAnimal();
        }
        else if (!this->ternakan.isEmpty())
        {
            bool existHarvest = false;
            for (int a = 1; a < this->ternakan.getRows(); a++)
            {
                for (int b = 1; b < this->ternakan.getCols(); b++)
                {
                    if (this->ternakan.getElement(a, b) != nullptr)
                    {
                        if (this->ternakan.getElement(a, b)->getTipeObject() == "HEWAN")
                        {
                            if (this->ternakan.getElement(a, b)->isHarvestable())
                            {
                                existHarvest = true;
                            }
                        }
                    }
                }
            }
            if (!existHarvest)
            {
                throw NoHarvestableAnimal();
            }
            else
            {
                this->cetakTernak();
                vector<string> ownedHew;
                vector<string> ownedHewName;
                vector<string> readyPanen;
                vector<int> readyPanenAmt;

                for (int i = 1; i < this->ternakan.getRows() + 1; i++)
                {
                    for (int j = 1; j < this->ternakan.getCols() + 1; j++)
                    {
                        if (this->ternakan.getElement(i, j) != nullptr)
                        {
                            if (this->ternakan.getElement(i, j)->getTipeObject() == "HEWAN")
                            {
                                bool found = false;
                                int it = 0;
                                while (it < ownedHew.size())
                                {
                                    if (ownedHew[it] == this->ternakan.getElement(i, j)->getKode())
                                    {
                                        found = true;
                                        it = ownedHew.size() + 1;
                                    }
                                    it++;
                                }

                                if (!found)
                                {
                                    string temp1 = this->ternakan.getElement(i, j)->getKode();
                                    string temp2 = this->ternakan.getElement(i, j)->getName();

                                    ownedHew.push_back(temp1);
                                    ownedHewName.push_back(temp2);
                                }
                            }
                        }
                    }
                }

                // Output hewan yang ada
                for (size_t i = 0; i < ownedHew.size(); ++i)
                {
                    cout << ownedHew[i] << " - " << ownedHewName[i] << endl;
                }

                // Output pilihan hewan berdasarkan siap panennnya
                for (size_t i = 0; i < ownedHew.size(); ++i)
                {
                    int count = 0;
                    int num = 1;

                    for (int j = 1; j < this->ternakan.getRows() + 1; j++)
                    {
                        for (int k = 1; k < this->ternakan.getCols() + 1; k++)
                        {
                            if (this->ternakan.getElement(j, k) != nullptr)
                            {
                                if (this->ternakan.getElement(j, k)->getKode() == ownedHew[i])
                                {
                                    if (this->ternakan.getElement(j, k)->isHarvestable())
                                    {
                                        count += 1;
                                        bool found = false;
                                        size_t it = 0;
                                        while (it < readyPanen.size())
                                        {
                                            if (readyPanen[it] == this->ternakan.getElement(j, k)->getKode())
                                            {
                                                found = true;
                                                it = readyPanen.size() + 1;
                                            }
                                            it++;
                                        }
                                        if (!found)
                                        {
                                            string temp = this->ternakan.getElement(j, k)->getKode();
                                            readyPanen.push_back(temp);
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (count > 0)
                    {
                        readyPanenAmt.push_back(count);
                    }
                    count = 0;
                }

                for (int i = 0; i < readyPanen.size(); i++)
                {
                    cout << i + 1 << ". " << readyPanen[i] << " (" << readyPanenAmt[i] << ")" << endl;
                }

                bool isValid = false;
                string maupanen;
                int maupanenint;

                if (readyPanen.size() > 0)
                {
                    while (!isValid)
                    {
                        try
                        {
                            cout << "Nomor hewan yang ingin dipanen: ";
                            cin >> maupanen;
                            cout << endl;

                            if (!isAllDigits(maupanen))
                            {
                                throw InvalidPanenIdx();
                            }
                            else
                            {
                                maupanenint = std::stoi(maupanen);

                                if (maupanenint > readyPanen.size() || maupanenint < 0)
                                {
                                    throw InvalidPanenIdx();
                                }
                                else
                                {
                                    isValid = true;
                                }
                            }
                        }
                        catch (BaseException &e)
                        {
                            cout << e.what() << endl;
                        }
                    }

                    isValid = false;
                    string brppanen;
                    int brppanenint;
                    while (!isValid)
                    {
                        try
                        {
                            cout << "Berapa petak yang ingin dipanen: ";
                            cin >> brppanen;
                            cout << endl;
                            if (!isAllDigits(brppanen))
                            {
                                throw InvalidPanenIdx();
                            }
                            else
                            {
                                brppanenint = std::stoi(brppanen);
                                if (brppanenint > this->inventory.getEmptySlot())
                                {
                                    throw InvalidInventorySpace();
                                }
                                else if (brppanenint > readyPanenAmt[maupanenint - 1])
                                {
                                    throw InvalidPanenAmountOver();
                                }
                                else if (brppanenint < 1)
                                {
                                    throw InvalidPanenAmount();
                                }
                                else
                                {
                                    isValid = true;
                                }
                            }
                            // Validasi
                            // if tidak valid ada output
                        }
                        catch (BaseException &e)
                        {
                            cout << e.what() << endl;
                        }
                    }

                    int i = 0;
                    string want;
                    vector<string> wants;
                    cout << "Pilih petak yang ingin dipanen: " << endl;
                    for (i; i < brppanenint; i++)
                    {
                        isValid = false;
                        while (!isValid)
                        {
                            try
                            {
                                cout << "Petak ke-" << i + 1 << ": ";
                                cin >> want;
                                int idx1 = want[0] - 'A' + 1;
                                int idx2 = std::stoi(want.substr(1));
                                if (want.length() != 3 && isAllDigits(want.substr(1)))
                                {
                                    throw InvalidIndexMatrixArea();
                                }
                                else if (idx2 > this->ternakan.getRows() || idx1 > this->ternakan.getCols())
                                {
                                    throw InvalidIndexMatrixArea();
                                }
                                else
                                {
                                    if (this->ternakan.getElement(idx2, idx1) != nullptr)
                                    {
                                        if (this->ternakan.getElement(idx2, idx1)->getKode() != readyPanen[maupanenint - 1])
                                        {
                                            throw InvalidPlantChoice();
                                        }
                                        else
                                        {
                                            isValid = true;
                                        }
                                    }
                                    else
                                    {
                                        throw InvalidEmptySlot();
                                    }
                                }
                            }
                            catch (BaseException &e)
                            {
                                cout << e.what() << endl;
                            }
                            // Validasi want, kalau valid wants.push_back(want);
                        }
                        wants.push_back(want);
                    }

                    for (int i = 0; i < wants.size(); i++)
                    {
                        bool foundslot = false;
                        int idx1 = wants[i][0] - 'A' + 1;
                        int idx2 = std::stoi(wants[i].substr(1));
                        int j = 1;
                        int k = 1;
                        while (j < this->inventory.getRows() + 1)
                        {
                            while (k < this->inventory.getCols() + 1)
                            {
                                if (this->inventory.getElement(j, k) == nullptr)
                                {
                                    vector<Product *> temp = this->ternakan.getElement(idx2, idx1)->hasilPanen();
                                    for (int n = 0; n < temp.size(); n++)
                                    {
                                        this->inventory.setElement(j, k, temp[n]);
                                        if (n < temp.size() - 1)
                                        {
                                            if (k == this->ternakan.getCols() && j == this->ternakan.getRows())
                                            {
                                                throw FullInv();
                                            }
                                            else if (k == this->ternakan.getCols())
                                            {
                                                j++;
                                                k = 1;
                                            }
                                            else
                                            {
                                                k++;
                                            }
                                        }
                                    }
                                    delete this->ternakan.getElement(idx2, idx1);
                                    this->ternakan.deleteElement(idx2, idx1);
                                    foundslot = true;
                                    break;
                                }
                                k++;
                            }
                            if (foundslot)
                            {
                                break;
                            }
                            j++;
                        }
                    }

                    cout << "Panen Berhasil" << endl;
                }
            }
        }
        else
        {
            throw NoHarvestableAnimal();
        }
    }
    catch (BaseException &e)
    {
        cout << e.what() << endl;
    }
}

float Peternak::calculateTax()
{
    float KKP = countKekayaanInven() + countKekayaanTernakan() - KTKP_PETERNAK;
    // cout<<"KKP: "<<KKP<<endl;
    float tax = getTaxRate(KKP)*KKP;
    if(tax>this->gulden){
        float temp = this->gulden;
        this->gulden = 0;
        return temp;
    }
    this->gulden -= tax;
    return tax;
}

int Peternak::countKekayaanTernakan()
{
    int sum = 0;
    for (int i = 1; i <= ternakan.getRows(); i++)
    {
        for (int j = 1; j <= ternakan.getCols(); j++)
        {
            Hewan* ptr = ternakan.getElement(i,j);
            if (ptr != nullptr)
            {
                // cout<<ptr->getName()<<" "<<ptr->getPrice()<<endl;
                sum += ternakan.getElement(i, j)->getPrice();
            }
        }
    }
    // cout<<"Total Ternak"<<sum<<endl;
    return sum;
}

bool Peternak::searchFood(bool animal){
    for(int i=1;i<=inventory.getRows();i++){
        for(int j=1;j<inventory.getCols();j++){
            GameObject* ptr = inventory.getElement(i,j);
            if(ptr = nullptr){
                continue;
            }
            if(ptr->getTipeObject()=="PRODUCT"){
                Product* temp = dynamic_cast<Product*>(ptr);
                if(animal && temp->fromHewan()){
                    return true;
                }
                if(!animal && temp->getType()=="PRODUCT_FRUIT_PLANT"){
                    return true;
                }
            }
        }
    }
    return false;
}
bool Peternak::checkAllHerbiv(){
    for(int i=1;i<ternakan.getRows();i++){
        for(int j=1;j<ternakan.getCols();j++){
            if(ternakan.getElement(i,j)->getType()=="CARNIVORE"){
                return false;
            }
        }
    }
    return true;
}
bool Peternak::checkAllCarniv(){
    for(int i=1;i<ternakan.getRows();i++){
        for(int j=1;j<ternakan.getCols();j++){
            if(ternakan.getElement(i,j)->getType()=="HERBIVORE"){
                return false;
            }
        }
    }
    return true;
}