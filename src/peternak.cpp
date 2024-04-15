#include <iostream>
#include <vector>
#include "peternak.hpp"
#include "./Header/Product.hpp"
using namespace std;
// EXTRA FUNCTIONS
Peternak::Peternak() : Pemain()
{
    this->tipe = "peternak";
    MatrixArea<Hewan> n(8, 8);
    this->ternakan = n;
    this->username = "Petani1";
}

Peternak::Peternak(string usn, int guld, int bb, int smol, int med, int big, int terrows, int tercols) : Pemain(usn, guld, bb, smol, med, big)
{
    this->tipe = "peternak";
    MatrixArea<Hewan> n(terrows, tercols);
    this->ternakan = n;
}

Peternak::Peternak(const Peternak &other) : Pemain()
{
    this->tipe = "peternak";
    MatrixArea<Hewan> n(other.ternakan);
    this->ternakan = n;
}

Peternak::~Peternak()
{
    this->inventory.~MatrixArea();
    this->ternakan.~MatrixArea();
}

MatrixArea<Hewan> Peternak::getTernakan()
{
    return this->ternakan;
}

void Peternak::beli()
{
    cout << endl
         << endl;
    int wantToBuy = Toko::buyProcess();
    int subResponse;
    int counterAvailableItem;
    GameObject *itemToBuy = nullptr;
    if (wantToBuy == 1)
    {
        Toko::displayAvailableHewan();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != Toko::availableHewan.size() + 1)
        {
            if (subResponse >= 1 && subResponse <= Toko::availableHewan.size())
            {
                itemToBuy = &Toko::availableHewan[subResponse - 1];
            }
            else
            {
                throw InvalidSubResponse();
            }
        }
    }
    else if (wantToBuy == 2)
    {
        Toko::displayAvailableTanaman();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != Toko::availableTanaman.size() + 1)
        {
            if (subResponse >= 1 && subResponse <= Toko::availableTanaman.size())
            {
                itemToBuy = &Toko::availableTanaman[subResponse - 1];
            }
            else
            {
                throw InvalidSubResponse();
            }
        }
    }
    else if (wantToBuy == 3 && !Toko::isProductEmptyStock())
    {
        counterAvailableItem = Toko::displayAvailableProduct();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != counterAvailableItem + 1)
        {
            if (subResponse >= 1 && subResponse <= counterAvailableItem)
            {
                int count = 0;
                for (int i = 0; i < Toko::availableProduct.size(); i++)
                {
                    if (Toko::availableProduct[i].second != 0)
                    {
                        count++;
                    }
                    if (subResponse == count)
                    {
                        itemToBuy = &Toko::availableProduct[count].first;
                    }
                }
            }
            else
            {
                throw InvalidSubResponse();
            }
        }
    }
    else if (wantToBuy == 3 && !Toko::isBangunanEmptyStock() && Toko::isProductEmptyStock())
    {
        counterAvailableItem = Toko::displayAvailableBangunan();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != counterAvailableItem + 1)
        {
            if (subResponse >= 1 && subResponse <= counterAvailableItem)
            {
                int count = 0;
                bool found = false;
                for (int i = 0; i < Toko::availableBangunan.size(); i++)
                {
                    if (Toko::availableBangunan[i].second != 0)
                    {
                        count++;
                    }
                    if (subResponse == count && !found)
                    {
                        itemToBuy = &Toko::availableBangunan[count].first;
                        this->ownedBangunan.push_back(Toko::availableBangunan[count].first);
                        found = true;
                    }
                }
            }
            else
            {
                throw InvalidSubResponse();
            }
        }
    }
    else if (wantToBuy == 4 && !Toko::isBangunanEmptyStock)
    {
        counterAvailableItem = Toko::displayAvailableBangunan();
        cout << "Barang yang ingin dibeli : ";
        cin >> subResponse;
        if (subResponse != counterAvailableItem + 1)
        {
            if (subResponse >= 1 && subResponse <= counterAvailableItem)
            {
                int count = 0;
                bool found = false;
                for (int i = 0; i < Toko::availableBangunan.size(); i++)
                {
                    if (Toko::availableBangunan[i].second != 0)
                    {
                        count++;
                    }
                    if (subResponse == count && !found)
                    {
                        itemToBuy = &Toko::availableBangunan[count].first;
                        this->ownedBangunan.push_back(Toko::availableBangunan[count].first);
                        found = true;
                    }
                }
            }
            else
            {
                throw InvalidSubResponse();
            }
        }
    }

    if (itemToBuy != nullptr)
    {
        cout << endl;
        cout << "Uang Anda : " << this->gulden << endl;
        this->inventory.displayRemainderSlot();
        cout << endl;

        int quantity;
        cout << "Kuantitas : ";
        cin >> quantity;

        this->gulden -= itemToBuy->getPrice() * quantity;
        try
        {
            if (quantity > this->inventory.getEmptySlot())
            {
                this->gulden += itemToBuy->getPrice() * quantity;
                throw InventoryNotEnough();
            }
            int stock = Toko::getStock(itemToBuy->getName());
            if (stock != -1 && stock < quantity)
            {
                this->gulden += itemToBuy->getPrice() * quantity;
                throw StockTokoNotEnough();
            }
            if (this->gulden < 0)
            {
                this->gulden += itemToBuy->getPrice() * quantity;
                throw NotEnoughGulden();
            }
            cout << endl;
            cout << "Selamat Anda berhasil membeli " << quantity << " " << itemToBuy->getName();
            cout << ". Uang yang tersisa " << this->gulden << "." << endl
                 << endl;

            cout << "Pilih slot untuk menyimpan barang yang anda beli!" << endl;
            this->inventory.displayObject();
            string slot;
            for (int i = 0; i < quantity; i++)
            {
                cout << "Petak slot " << i + 1 << ": ";
                cin >> slot;
                pair<int, int> position;
                try
                {
                    position = this->inventory.getPositionFromSlot(slot);
                    if (this->inventory.getElement(position.first, position.second) != nullptr)
                    {
                        throw SlotFilled();
                    }
                    this->inventory.setElement(position.first, position.second, itemToBuy);
                }
                catch (InvalidPositionMatrixArea err)
                {
                    err.what();
                    cout << endl;
                }
                catch (SlotFilled err)
                {
                    err.what();
                    cout << endl;
                }
            }
            cout << itemToBuy->getName() << "berhasil disimpan dalam penyimpanan!" << endl;
            Toko::itemDibeli(itemToBuy, quantity);
        }
        catch (InventoryNotEnough err)
        {
            err.what();
            cout << endl;
        }
        catch (StockTokoNotEnough err)
        {
            err.what();
            cout << endl;
        }
        catch (NotEnoughGulden err)
        {
            err.what();
            cout << endl;
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
        cout << "Masukkan kuantitas barang yang ingin dijual :";
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
             << "Silahkan pilih petak yang ingin anda jual!";
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
                    else if (idx2 > this->inventory.getRows() || idx1 > this->inventory.getCols())
                    {
                        throw InvalidIndexMatrixArea();
                    }
                    // position = this->inventory.getPositionFromSlot(slot);
                    // itemToSell = this->inventory.getElement(position.first, position.second);
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
            profit += this->inventory.getElement(idx2, idx1)->getPrice();
            cout << this->inventory.getElement(idx2, idx1)->getPrice() << endl;
            this->inventory.deleteElement(idx2, idx1);
        }
        this->gulden += profit;
        cout << this->gulden << ' ' << profit << endl;
        cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << profit << " gulden!" << endl;
        Toko::itemDijual(itemToSell, quantityint);
    }
    catch (BaseException &e)
    {
        cout << e.what() << endl;
    }
}

void Peternak::cetakTernak()
{
    this->ternakan.displayObject();
    // this->ternakan.displayRemainderSlot();
}

void Peternak::ternak()
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
            if (petak.length() != 3)
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
                    InvalidFilledSlot();
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

    if (temp)
    {
        cout << "SUCCC" << endl;
        cout << temp->getKode() << endl;
    }
    else
    {
        cout << "GAGGG" << endl;
    }

    this->ternakan.setElement(idx4, idx3, temp);
    this->inventory.deleteElement(idx2, idx1);
    cout << this->ternakan.getElement(idx4, idx3)->getKode() << endl;
    cout << "Berhasil diternakkan" << endl;
}

void Peternak::kasihMakan()
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
            if (slot.length() != 3)
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
            if (slot2.length() != 3)
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

    // Output Hasil
}

void Peternak::panenTernak()
{
    if (this->ternakan.isEmpty())
    {
        throw NoHarvestableAnimal();
    }
    try
    {
        if (!this->ternakan.isEmpty())
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
                        cout << this->ternakan.getElement(i, j)->getKode() << endl;
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
            cout << " BATAS " << endl;

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
                            cout << j << k << endl;
                            cout << this->ternakan.getElement(j, k)->getKode() << endl;
                            if (this->ternakan.getElement(j, k)->getKode() == ownedHew[i])
                            {
                                if (this->ternakan.getElement(j, k)->isHarvestable())
                                {
                                    count += 1;
                                    bool found = false;
                                    size_t it = 0;
                                    cout << "1" << endl;
                                    while (it < readyPanen.size())
                                    {
                                        cout << "2" << endl;
                                        cout << "3" << endl;
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
                                    cout << "-----------------" << endl;
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
                            cout << idx2 << idx1 << endl;
                            if (want.length() != 3)
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
                                    cout << "a" << endl;
                                    cout << this->ternakan.getElement(idx2, idx1)->getKode() << endl;
                                    if (this->ternakan.getElement(idx2, idx1)->getKode() != readyPanen[maupanenint - 1])
                                    {
                                        cout << "b" << endl;
                                        throw InvalidPlantChoice();
                                    }
                                    else
                                    {
                                        cout << "c" << endl;
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

                cout << "WS" << wants.size() << endl;
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
                                cout << j << k << endl;
                                vector<Product *> temp = this->ternakan.getElement(idx2, idx1)->hasilPanen();
                                for (int n = 0; n < temp.size(); n++)
                                {
                                    cout << "XXX" << endl;
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
    int KKP = countKekayaanInven() + countKekayaanTernakan() - KTKP_PETERNAK;
    return getTaxRate(KKP) * KKP;
}

int Peternak::countKekayaanTernakan()
{
    int sum = 0;
    for (int i = 0; i < ternakan.getRows(); i++)
    {
        for (int j = 0; j < ternakan.getCols(); i++)
        {
            if (ternakan.getElement(i, j) != 0)
            {
                sum += ternakan.getElement(i, j)->getPrice();
            }
        }
    }
    return sum;
}