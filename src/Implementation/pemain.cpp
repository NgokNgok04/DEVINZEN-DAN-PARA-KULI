#include <iostream>
#include <vector>
#include <string>
#include "../Header/pemain.hpp"
#include "../Header/ParserMisc.hpp"
using namespace std;

Pemain::Pemain()
{
    int inventoryRows = ParserMisc::getStorageSize().first;
    int inventoryCols = ParserMisc::getStorageSize().second;
    this->gulden = 50;
    this->berat_badan = 40;
    MatrixArea<GameObject> inv(inventoryRows, inventoryCols);
    this->inventory = inv;
    this->ownedBuild = {0, 0, 0};
}

Pemain::Pemain(string usn, float guld, int bb)
{
    this->gulden = guld;
    this->berat_badan = bb;
    pair<int, int> sizeInven = ParserMisc::getStorageSize();
    MatrixArea<GameObject> inv(sizeInven.first, sizeInven.second);
    this->inventory = inv;
    this->username = usn;
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

MatrixArea<GameObject> &Pemain::getInventory()
{
    return this->inventory;
}

void Pemain::cetakPenyimpanan()
{
    this->inventory.displayObject();
    this->inventory.displayRemainderSlot();
}

void Pemain::makan() // butuh Catch EmptyInventory n NoFoodInInventory
{
    try
    {
        if (this->inventory.isEmpty())
        {
            throw EmptyInventory();
        }

        bool foundEatable = false;
        Product *itemInSearch;
        for (int i = 0; i < this->inventory.getRows(); i++)
        {
            for (int j = 0; j < this->inventory.getCols(); j++)
            {
                if (this->inventory.getElement(i + 1, j + 1) != nullptr && this->inventory.getElement(i + 1, j + 1)->getTipeObject() == "PRODUCT")
                {
                    itemInSearch = dynamic_cast<Product *>(this->inventory.getElement(i + 1, j + 1));
                    if (itemInSearch->getAddedWeight() != 0)
                    {
                        foundEatable = true;
                        break;
                    }
                }
            }
            if (foundEatable)
            {
                break;
            }
        }
        if (!foundEatable)
        {
            throw NoFoodInInventory();
        }
        cout << "Pilih makanan dari penyimpanan" << endl;
        this->inventory.displayObject();
        cout << endl;

        string slot;
        // cout << "Slot: ";
        // cin >> slot;
        pair<int, int> pos;
        bool isValid = false;
        while (!isValid)
        {
            cout << "Slot: ";
            cin >> slot;
            try
            {

                pos = this->inventory.getPositionFromSlot(slot);
                if (this->inventory.getElement(pos.first, pos.second) == nullptr)
                {
                    throw EmptyFoodSlot();
                }

                if (this->inventory.getElement(pos.first, pos.second)->getTipeObject() != "PRODUCT")
                {
                    throw NotEatableSlot();
                }
                else
                {
                    Product *itemToEat = dynamic_cast<Product *>(this->inventory.getElement(pos.first, pos.second));
                    if (itemToEat->getAddedWeight() == 0)
                    {
                        throw NotEatableSlot();
                    }
                    else
                    {
                        this->berat_badan += itemToEat->getAddedWeight();
                        delete this->inventory.getElement(pos.first, pos.second);
                        this->inventory.deleteElement(pos.first, pos.second);

                        cout << endl;
                        cout << "Dengan lahapnya, kamu memakan hidangan itu" << endl;
                        cout << "Alhasil, berat badan kamu naik menjadi " << this->berat_badan << endl;

                        isValid = true;
                    }
                }
            }
            catch (InvalidResponseToko err)
            {
                err.what();
            }
            catch (EmptyFoodSlot err)
            {
                cout << endl
                     << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
            }
            catch (NotEatableSlot err)
            {
                cout << endl
                     << "Apa yang kamu lakukan?! Kamu mencoba untuk memakan itu?!" << endl;
            }
        }
    }
    catch (BaseException &e)
    {
        cout << e.what() << endl;
    }
}

string Pemain::getUsername()
{
    return this->username;
}

int Pemain::getBeratBadan()
{
    return this->berat_badan;
}

bool Pemain::operator<(Pemain &other)
{
    string actualUsername1 = this->getUsername();
    string actualUsername2 = other.getUsername();
    string lowerUsername1 = actualUsername1;
    string lowerUsername2 = actualUsername2;
    for (auto &x : lowerUsername1)
    {
        x = tolower(x);
    }
    for (auto &x : lowerUsername2)
    {
        x = tolower(x);
    }
    if (lowerUsername1 == lowerUsername2)
    {
        return actualUsername1 < actualUsername2;
    }
    else
    {
        return lowerUsername1 < lowerUsername2;
    }
}

bool Pemain::operator==(Pemain &other)
{
    return this->getUsername() == other.getUsername();
}

void Pemain::setInv(int rows, int cols, GameObject *a)
{
    this->inventory.setElement(rows, cols, a);
}

int Pemain::countKekayaanInven()
{
    int sum = 0;
    for (int i = 1; i <= inventory.getRows(); i++)
    {
        for (int j = 1; j <= inventory.getCols(); j++)
        {
            GameObject *ptr = inventory.getElement(i, j);
            if (ptr != nullptr)
            {
                // cout<<ptr->getName()<<" "<<ptr->getPrice()<<endl;
                sum += ptr->getPrice();
            }
        }
    }
    // cout<<"Total Inven "<<sum<<endl;
    return sum;
}

float Pemain::getTaxRate(int KKP)
{
    if (KKP <= 6)
    {
        return 0.05;
    }
    else if (KKP <= 25)
    {
        return 0.15;
    }
    else if (KKP <= 50)
    {
        return 0.25;
    }
    else if (KKP <= 500)
    {
        return 0.3;
    }
    else
    {
        return 0.35;
    }
}

float Pemain::getGulden()
{
    return this->gulden;
}