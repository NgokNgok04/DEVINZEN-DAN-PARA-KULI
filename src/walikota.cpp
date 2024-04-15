#include <iostream>
#include <vector>
#include "pemain.hpp"
#include "walikota.hpp"
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
    else
    {
        throw InvalidSubResponse();
    }

    if (itemToBuy != nullptr)
    {
        cout << endl;
        cout << "Uang Anda : " << this->gulden << endl;
        this->inventory.displayRemainderSlot();
        cout << endl;

        int quantity;
        cout << "Kuantitas : "; // asumsi valid (nanti exception)
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

void WaliKota::jual()
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
                    cout << e.what() << endl;
                }
            }
            int idx1 = slot[0] - 'A' + 1;
            int idx2 = std::stoi(slot.substr(1));
            profit += itemToSell->getPrice();
            cout << this->inventory.getElement(idx2, idx1)->getPrice() << endl;
            this->inventory.deleteElement(position.first, position.second);
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

void WaliKota::bangunBangunan()
{
    cout << "Resep Bangunan yang ada sebagai berikut: " << endl;
    for (int i = 0; i < Toko::availableBangunan.size(); i++)
    {
        cout << "    ";
        cout << i + 1 << ". " << Toko::availableBangunan[i].first.getName();
        cout << " (";
        cout << Toko::availableBangunan[i].first.getPrice() << " gulden, ";
        for (int j = 0; j < ParserResep::getRecipeMaterialQuantity(i + 1).size(); i++)
        {
            cout << ParserResep::getRecipeMaterialQuantity(i + 1)[j].first;
            cout << " ";
            cout << ParserResep::getRecipeMaterialQuantity(i + 1)[j].second;
            if (j != ParserResep::getRecipeMaterialQuantity(i + 1).size() - 1)
            {
                cout << ",";
            }
            cout << " ";
        }
        cout << ")" << endl;
    }
    string bangunanToBuy;
    cout << "Bangunan yang ingin dibangun: ";
    cin >> bangunanToBuy;

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
        cout << endl;
    }
    catch (MaterialNotEnough err)
    {
        err.what();
        cout << endl;
    }

    this->ownedBangunan.push_back(Toko::availableBangunan[idxToBuy].first);
    cout << Toko::availableBangunan[idxToBuy].first.getName() << "berhasil dibangun dan telah menjadi hak milik walikota!" << endl;
}

float WaliKota::calculateTax()
{
    return 0;
}