#include <iostream>
#include <vector>
#include "../Header/petani.hpp"

using namespace std;

// EXTRA FUNCTIONS

Petani::Petani() : Pemain()
{
    this->tipe = "Petani";
    int FieldRow = ParserMisc::getFieldSize().first;
    int FieldCol = ParserMisc::getFieldSize().second;
    MatrixArea<Tanaman> n(FieldRow, FieldCol);
    this->ladang = n;
    this->username = "Petani1";
}

Petani::Petani(string usn, float guld, int bb) : Pemain(usn, guld, bb)
{
    this->tipe = "Petani";
    pair<int,int> sizeLadang = ParserMisc::getFarmSize();
    MatrixArea<Tanaman> n(sizeLadang.first, sizeLadang.second);
    this->ladang = n;
}

Petani::Petani(const Petani &other) : Pemain(other)
{
    this->tipe = "Petani";
    MatrixArea<Tanaman> n(other.ladang);
    this->ladang = n;
}

Petani::~Petani()
{
    this->inventory.~MatrixArea();
    this->ladang.~MatrixArea();
}

void Petani::beli()
{
    std::cout << endl
              << endl;

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
                else if (((wantToBuy == 3 && Toko::isProductEmptyStock()) || (wantToBuy == 4)) && !Toko::isBangunanEmptyStock())
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
                            for (int i = 0; i < Toko::getAvailableProductSize(); i++)
                            {
                                if (Toko::getPairProductInt(i)->second != 0)
                                {
                                    count++;
                                }
                                if (validSubResponse == count && !found)
                                {
                                    itemToBuy = &Toko::getPairProductInt(i)->first;
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

void Petani::jual() // perlu catch ItemQuantityToSellNotEnough
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
                    std::cout << e.what() << endl;
                }
            }
            int idx1 = slot[0] - 'A' + 1;
            int idx2 = std::stoi(slot.substr(1));
            profit += this->inventory.getElement(idx2, idx1)->getPrice();
            Toko::itemDijual(this->inventory.getElement(idx2, idx1), 1);
            this->inventory.deleteElement(idx2, idx1);
        }
        this->gulden += profit;
        cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << profit << " gulden!" << endl;
    }
    catch (BaseException &e)
    {
        std::cout << e.what() << endl;
    }
}

MatrixArea<Tanaman> &Petani::getLadang()
{
    return this->ladang;
}

void Petani::cetakLadang()
{
    this->ladang.displayObject();
    this->ladang.displayRemainderSlot();
}

void Petani::tanam()
{
    try{
    if (this->ladang.getEmptySlot() == 0)
    {
        throw NoEmptySlot();
    }
    bool existPlant = false;
            for (int a = 1; a < this->inventory.getRows(); a++)
            {
                for (int b = 1; b < this->inventory.getCols(); b++)
                {
                    if (this->inventory.getElement(a, b) != nullptr)
                    {
                        if (this->inventory.getElement(a, b)->getTipeObject() == "TANAMAN")
                        {
                            existPlant = true;
                        }
                    }
                }
            }
    if (!existPlant)
    {
        throw NoPlant();
    }
    else
    {
    std::cout << "Pilih Tanaman dari penyimpanan" << endl;
    this->cetakPenyimpanan();
    this->cetakLadang();

    bool isValid = false;
    string slot;

    while (!isValid)
    {
        std::cout << "Slot: ";
        std::cin >> slot;
        std::cout << endl;
        // Validasi
        int idx1 = slot[0] - 'A' + 1;
        int idx2 = std::stoi(slot.substr(1));
        try
        {
            this->cetakLadang();

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
                    if (this->inventory.getElement(idx2, idx1)->getTipeObject() != "TANAMAN")
                    {
                        throw InvalidNotTanaman();
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
            std::cout << e.what() << endl;
        }
    }

    int idx1 = slot[0] - 'A' + 1;
    int idx2 = std::stoi(slot.substr(1));

    std::cout << "Kamu memilih " << this->inventory.getElement(idx2, idx1)->getName() << endl; // Nama Objeknya
    std::cout << "Pilih petak tanah yang akan ditanami" << endl;
    this->cetakLadang();

    isValid = false;
    string petak;
    while (!isValid)
    {
        std::cout << "Petak Tanah: ";
        std::cin >> petak;
        std::cout << endl;
        // Validasi
        int idx3 = petak[0] - 'A' + 1;
        int idx4 = std::stoi(petak.substr(1));
        try
        {
            if (petak.length() != 3 && isAllDigits(petak.substr(1)))
            {
                throw InvalidIndexMatrixArea();
            }
            else if (idx4 > this->ladang.getRows() || idx3 > this->ladang.getCols())
            {
                throw InvalidIndexMatrixArea();
            }
            else
            {
                if (this->ladang.getElement(idx4, idx3) == nullptr)
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
            std::cout << e.what() << endl;
        }
    }
    int idx3 = petak[0] - 'A' + 1;
    int idx4 = std::stoi(petak.substr(1));

    Tanaman *temp = dynamic_cast<Tanaman *>(this->inventory.getElement(idx2, idx1));

    this->ladang.setElement(idx4, idx3, temp);
    daftarTanaman.push_back(temp);
    this->inventory.deleteElement(idx2, idx1);
    std::cout << this->ladang.getElement(idx4, idx3)->getKode() << endl;
    std::cout << "Berhasil ditanam" << endl;
    }
    } catch (BaseException &e)
    {
        cout << e.what() << endl;
    }
}

void Petani::panenTani()
{
    try
    {
        if (this->ladang.isEmpty())
        {
            throw NoHarvestablePlant();
        }
        else
        {
            bool existHarvest = false;
            for (int a = 1; a < this->ladang.getRows(); a++)
            {
                for (int b = 1; b < this->ladang.getCols(); b++)
                {
                    if (this->ladang.getElement(a, b) != nullptr)
                    {
                        if (this->ladang.getElement(a, b)->getTipeObject() == "TANAMAN")
                        {
                            if (this->ladang.getElement(a, b)->isHarvestable())
                            {
                                existHarvest = true;
                            }
                        }
                    }
                }
            }
            if (!existHarvest)
            {
                throw NoHarvestablePlant();
            }
            else
            {
                this->cetakLadang();
                vector<string> ownedTan = {};
                vector<string> ownedTanName = {};
                vector<string> readyPanen = {};
                vector<int> readyPanenAmt = {};

                for (int i = 1; i < this->ladang.getRows() + 1; i++)
                {
                    for (int j = 1; j < this->ladang.getCols() + 1; j++)
                    {
                        if (this->ladang.getElement(i, j) != nullptr)
                        {
                            if (this->ladang.getElement(i, j)->getTipeObject() == "TANAMAN")
                            {
                                bool found = false;
                                int it = 0;
                                while (it < ownedTan.size())
                                {

                                    if (ownedTan[it] == this->ladang.getElement(i, j)->getKode())
                                    {
                                        found = true;
                                        it = ownedTan.size() + 1;
                                    }
                                    it++;
                                }

                                if (!found)
                                {
                                    string temp1 = this->ladang.getElement(i, j)->getKode();
                                    string temp2 = this->ladang.getElement(i, j)->getName();

                                    ownedTan.push_back(temp1);
                                    ownedTanName.push_back(temp2);

                                    // cout << "awdasdwdasdawd" << endl;
                                    // this->cetakLadang();
                                }
                            }
                        }
                    }
                }

                // Output tanaman yang ada
                for (size_t i = 0; i < ownedTan.size(); ++i)
                {
                    cout << ownedTan[i] << " - " << ownedTanName[i] << endl;
                }

                // Output pilihan tanaman berdasarkan siap panennnya
                for (size_t i = 0; i < ownedTan.size(); ++i)
                {
                    int count = 0;
                    int num = 1;

                    for (int j = 1; j < this->ladang.getRows(); j++)
                    {
                        for (int k = 1; k < this->ladang.getCols(); k++)
                        {
                            if (this->ladang.getElement(j, k) != nullptr)
                            {
                                if (this->ladang.getElement(j, k)->getKode() == ownedTan[i])
                                {
                                    if (this->ladang.getElement(j, k)->isHarvestable())
                                    {
                                        count += 1;
                                        bool found = false;
                                        size_t it = 0;
                                        while (it < readyPanen.size())
                                        {
                                            if (readyPanen[it] == this->ladang.getElement(j, k)->getKode())
                                            {
                                                found = true;
                                                it = readyPanen.size() + 1;
                                            }
                                            it++;
                                        }
                                        if (!found)
                                        {
                                            string temp = this->ladang.getElement(j, k)->getKode();
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
                    // cout << this->ladang.getElement(5, 4)->getKode() << endl;

                    while (!isValid)
                    {
                        try
                        {
                            cout << "Nomor tanaman yang ingin dipanen: ";
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
                                else if (idx2 > this->ladang.getRows() || idx1 > this->ladang.getCols())
                                {
                                    throw InvalidIndexMatrixArea();
                                }
                                else
                                {
                                    if (this->ladang.getElement(idx2, idx1) != nullptr)
                                    {
                                        if (this->ladang.getElement(idx2, idx1)->getKode() != readyPanen[maupanenint - 1])
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
                        for (int j = 1; j < this->inventory.getRows() + 1; j++)
                        {
                            for (int k = 1; k < this->inventory.getCols() + 1; k++)
                            {
                                if (this->inventory.getElement(j, k) == nullptr)
                                {
                                    this->inventory.setElement(j, k, this->ladang.getElement(idx2, idx1)->hasilPanen());
                                    auto it = find(daftarTanaman.begin(),daftarTanaman.end(),this->ladang.getElement(idx2,idx1));
                                    daftarTanaman.erase(it);
                                    delete this->ladang.getElement(idx2, idx1);
                                    this->ladang.deleteElement(idx2, idx1);
                                    foundslot = true;
                                    break;
                                }
                            }
                            if (foundslot)
                            {
                                break;
                            }
                        }
                    }
                    cout << "Panen Berhasil" << endl;
                }
            }
        }
    }
    catch (BaseException &e)
    {
        cout << e.what() << endl;
    }
}

int Petani::countKekayaanLadang()
{
    int sum = 0;
    for (int i = 1; i < ladang.getRows(); i++)
    {
        for (int j = 1; j < ladang.getCols(); j++)
        {
            Tanaman *ptr = ladang.getElement(i, j);
            if (ptr != nullptr)
            {
                // cout<<ptr->getName()<<" "<<ptr->getPrice()<<endl;
                sum += ptr->getPrice();
            }
        }
    }
    // cout<<"Total Ladang: "<<sum<<endl;
    return sum;
}

float Petani::calculateTax()
{
    float KKP = countKekayaanInven() + countKekayaanLadang() - KTKP_PETANI;
    // cout << "KKP: "<<KKP << endl;
    float tax = getTaxRate(KKP)*KKP;
    if(tax>this->gulden){
        float temp = this->gulden;
        this->gulden = 0;
        return temp;
    }
    this->gulden -= tax;
    return tax;
}

void Petani::tambahUmurTanaman(){
    int jmlhTanaman = daftarTanaman.size();
    for(int i=0;i<jmlhTanaman;i++){
        daftarTanaman[i]->tambahUmur();
    }
}

vector<Tanaman*> &Petani::getDaftarTanaman(){
    return daftarTanaman;
}
